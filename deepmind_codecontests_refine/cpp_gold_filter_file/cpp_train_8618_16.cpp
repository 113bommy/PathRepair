#include<cstdio>
int main() {int n,a,b,cnt = 0; scanf("%d%d",&n,&a); for(int i=1;i<=n;i++) { scanf("%d",&b); if(b>=a)cnt++; } printf("%d",cnt); }
