#include <stdio.h>
int main(){
    int n,l,r,tot;
    bool f;
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        tot=0;
        f=false;
        for(int i=0;i<12;i++){
            scanf("%d%d",&l,&r);
            tot+=l-r;
            if(tot>=n&&!f){
                f=true;
                printf("%d\n",i+1);
            }
        }
        if(!f)printf("NA\n");
        
    }
}