#include<cstdio>
int main(){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
int n=100*a+10*b+c;
if(n%4==0)printf("YES\n");
else printf("NO\n");
return 0;
}