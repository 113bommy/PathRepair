#include<stdio.h>
int main(){
    int N,K,blood[101],family[101],tmp,i,j,x;
    while(1){
         scanf("%d %d", &N, &K);
         if(N==0&&K==0)
         break;
        tmp=1;
        for(i=0;i<K;i++)
            scanf("%d",&blood[i]);
        for(i=0;i<N;i++){
            for(j=0;j<K;j++){
                scanf("%d",&x);
                blood[j]-=x;
                if(blood[j]<0)
                tmp=0;
            }
        }
        if(tmp==0)
        printf("No\n");
        else
        printf("Yes\n");
    }
}