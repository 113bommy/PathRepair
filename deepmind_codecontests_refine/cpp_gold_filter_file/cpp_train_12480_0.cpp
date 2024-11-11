#include<cstdio>
int a,b,d=400;int main(){for(char c[d];~scanf("%s%d%d",c,&a,&b);a=a/d?d:a,printf("%s %d %d\n",c,a+b,a*200+b*300))b=b/d?d:b;}