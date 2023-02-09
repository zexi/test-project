#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void){
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi("8888"));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(fd, (struct sockaddr*)&addr, sizeof addr);

    while (true){
        char info[100];
        std::cin >> info;
        write(fd, info, sizeof info);
        if (!strcmp(info, "q")){
            break;
        }
    }

    close(fd);

    return 0;
}
