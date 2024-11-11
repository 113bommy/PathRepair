include<stdio.h>
#define mod 1000000009
int main(void){
long long int N,i,ans=1;
scanf("%lld",&N);
for(i=1;i<=N;i++){
ans*=i;
ans%=mod;
}
printf("%d\n",ans);
return 0;
}