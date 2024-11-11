#include <bits/stdc++.h>
using namespace std;
#define N 1010
int x[N],y[N],d[N],vis[2];
inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while (!isdigit(ch)) {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main() {
    int n=read(),m=0;
    for (int i=1;i<=n;i++) {
        x[i]=read(),y[i]=read();
        vis[(x[i]+y[i])&1]=true;
    }
	if (vis[0]&vis[1]) return puts("-1")&0;
	if (vis[0]) d[++m]=1;
	for (int i=30;i>=0;i--) d[++m]=1<<i;
	printf("%d\n",m);
	for (int i=1;i<=m;i++) printf("%d ",d[i]); putchar('\n');
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (abs(x[i])>abs(y[i])) {
				if (x[i]>0) x[i]-=d[j],putchar('R');
				else x[i]+=d[j],putchar('L');
			} else {
				if (y[i]>0) y[i]-=d[j],putchar('U');
				else y[i]+=d[j],putchar('D');
			}
		}
		putchar('\n')
	}
	return 0;
}
