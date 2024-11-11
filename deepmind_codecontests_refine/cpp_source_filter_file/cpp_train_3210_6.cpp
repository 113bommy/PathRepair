#include<stdio.h>
int mian(){
    int a,b,k,i;
    scanf("%d%d%d",&a,&b,&k);
    for(i=a;i<=b;i++){
        if(i<a+k||b-k<i)
            printf("%d\n",i);
    }
    return 0;
}