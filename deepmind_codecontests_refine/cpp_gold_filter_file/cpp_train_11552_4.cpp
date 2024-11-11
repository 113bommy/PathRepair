#include <stdio.h>

int main() {
    int i,n,maxp,minp,a,b,c,d,e,sum;

    while(1){
        scanf("%d",&n);

        if(n == 0) break;

        maxp = 0;
        minp = 1000000;

        for(i=0; i<n; i++){
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            sum = a + b + c + d + e;
            if(sum > maxp) maxp = sum;
            if(sum < minp) minp = sum;
        }

        printf("%d %d\n",maxp,minp);

    }
    return 0;
}