#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define K 20
int n,m,v,a[N],l[N][K],r[N][K],f[N],g[N],h[N];

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();v=read();
	for (int i=1;i<=n;i++) a[i]=read();
	while (true){
		l[1][m]=1;r[n][m]=n;
		l[0][m]=1;r[n+1][m]=n;
		for (int i=2;i<=n;i++)
			l[i][m]=(a[i]-a[i-1]<=v)?l[i-1][m]:i;
		for (int i=n-1;i>=1;i--)
			r[i][m]=(a[i+1]-a[i]<=v)?r[i+1][m]:i;
		m++;if (!v) break;v/=2;
	}
	fill(g,g+(1<<m),n+1);
	for (int i=2;i<(1<<m);i+=2){
		for (int j=1;j<m;j++)
			if (i&(1<<j))
			f[i]=max(f[i],r[f[i-(1<<j)]+1][j]),
			g[i]=min(g[i],l[g[i-(1<<j)]-1][j]);
	fill(h,h+n+1,0x3fffffff);
	for (int i=0;i<(1<<m);i+=2)
		h[f[i]]=min(h[f[i]],g[(1<<m)-2-i]);
	for (int i=n-1;i>=0;i--)
		h[i]=min(h[i],h[i+1]);
	for (int i=1;i<=n;i++)
		printf((h[l[i][0]-1]<=r[i][0]+1)?"Possible\n":"Impossible\n");
	return 0;
}