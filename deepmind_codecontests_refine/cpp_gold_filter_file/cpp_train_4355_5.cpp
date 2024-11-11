#include<stdio.h>
int main(){
int n,k,i,a,ans;
scanf("%d%d",&n,&k);
for(i=0;i<n;i++)
scanf("%d",&a);
ans=(n-1)/(k-1);
if((n-1)%(k-1)!=0)
ans++;
printf("%d\n",ans);
return 0;
}
