#include <stdio.h>
long long a [100010];
int main (){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%lld",&a[i]);
int zero =0;
for(int i=0;i<n;i++)if(a[i]==0) zero++;
if(zero >0){
printf("0\n");
return 0;
}
long long prod =1;
for(int i=0;i<n;i++){
if(a[i ] <=1000000000000000000/ prod ){
prod *=a[i];
}else{
printf("-1\n");
return 0;
}
}
printf("%lld\n",prod );
}
