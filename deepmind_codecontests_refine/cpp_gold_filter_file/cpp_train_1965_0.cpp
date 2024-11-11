#include <stdio.h>
#include <string.h>
int main(void){
    int n=999999,a,b,c;
    int x[1000000];
    memset(x,0,sizeof(x));
    for(a=2,c=0;a<=n;a++){
        if(x[a]){x[a]=c;continue;}
        x[a]=++c;
        for(b=a*2;b<=n;b+=a)x[b]=-1;
    }
    while(~scanf("%d",&n)){
        printf("%d\n",x[n]);
    }
    return 0;
}