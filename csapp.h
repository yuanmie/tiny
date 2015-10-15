#ifndef _CSAPP_H_
#define _CSAPP_H_


/*
 * 这个是第8章的进程控制所需要包含的文件
 * 作者：李凯
 * 时间：2015年08月16日
 */
#include <sys/types.h>
/*
 * 这个是第9章的虚拟存储器所需要包含的文件
 * 作者：李凯
 * 时间：2015年08月16日
 */
#include <sys/mman.h>
/*
 * 这个是第10章的rio库所需要包含的文件
 * 作者：李凯
 * 时间：2015年08月16日
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t rio_readn(int fd, void *usrbuf, size_t n);

ssize_t rio_writen(int fd, void *usrbuf, size_t n);

#define RIO_BUFSIZE 8192
typedef struct{
     int rio_fd; //Descriptor for this internal buf
     int rio_cnt; //Unread bytes in internal buf
     char *rio_bufptr; //Next unread byte in internal buf
     char rio_buf[RIO_BUFSIZE]; //Internal buffer
}rio_t;

void rio_readinitb(rio_t *rp, int fd);
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);

/*
 * 这个是11章web服务器所需要包含的文件
 * 作者：李凯
 * 时间：2015年08月16日
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define MAXLINE 8192
#define MAXBUF  8192
#define LISTENQ 1024

typedef struct sockaddr SA;
int open_clientfd(char *hostname, int port);
int open_listenfd(int port);
extern char **environ; 

#endif
