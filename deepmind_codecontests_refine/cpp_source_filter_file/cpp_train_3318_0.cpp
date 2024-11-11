#include <stdio.h>
#include <math.h>
int a[10],i,n,s;
int summing(int n,int s){
    int ans=0,i,max=0,min=0,m;
    if(n==1){if(s<10 && a[s]==1)return 1; else return 0;}
    else{
        for(i=0,m=n;m>0 && i<10;i++){if(a[i]==1){min+=m*i;m--;}}
        for(i=9,m=n;m>0 && i>=0;i--){if(a[i]==1){max+=m*i;m--;}}
        if(s<min || max<s)return 0;
        //for(i=0;i<10;i++){printf("%d",a[i]);}
        for(i=0;i<10;i++){
            if(a[i]==1 && n*i<=s){
                /*if(n==2){
                    m=s-i*2;
                    if(m>=0 && m<10 && i!=m && a[m]==1)ans++;
                }*/
                else{
                    a[i]=0;
                    ans+=summing(n-1,s-n*i);
                    a[i]=1;
                }
            }
        }
        //printf("%d,%d\n",n,ans);
        return ans;
    }
}
int main(void){
    for(i=0;i<10;i++)a[i]=1;
    while(scanf("%d %d",&n,&s)!=EOF){printf("%d\n",summing(n,s));}
    return 0;
}