#include <cstdio>
#define k 1024
#define r(a) for(int i=0;i<a;i++)
#define s(a) scanf("%d",&a);
#define m(a,b) a<b?a:b
int w,n,m,c[k],d[k],p[k];
int main(){s(n)s(m)r(n)s(d[i])r(m)s(c[i])r(n+1)p[i]=1e9;p[0]=0;r(m*n)w=n-i%n,p[w]=m(p[w],p[w-1]+c[i/n]*d[w-1]);printf("%d\n",p[n]);}