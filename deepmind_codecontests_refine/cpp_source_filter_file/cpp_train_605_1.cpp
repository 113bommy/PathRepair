#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define N 1005
#define inf 1000000000
#define lowbit(o) o&(-o)
using namespace std;
int i,j,k,l,s,n,m,tot,last[N],x,next[N],to[N],a[N],f[N][5005];
struct node {
	int a[3];
}A[N];
inline void add(int x,int y) {
	next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void Min(int &x,int y) {
	x=min(x,y);
}
int main() {
	scanf("%d",&n);
	for (i=2;i<=n;i++) scanf("%d",&x),add(x,i);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=n;i;i--) {
		for (j=1;j<=a[i];j++) f[0][j]=inf;
		f[0][0]=tot=0;
		for (j=last[i];j;j=next[j]) {
			++tot;
			for (k=0;k<=a[i];k++) f[tot][k]=inf;
			for (k=0;k<=a[i]-A[to[j]].a[1];k++) Min(f[tot][k+A[to[j]].a[1]],f[tot-1][k]+A[to[j]].a[2]);
			for (k=0;k<=a[i]-A[to[j]].a[2];k++) Min(f[tot][k+A[to[j]].a[2]],f[tot-1][k]+A[to[j]].a[1]);
		}
		A[i].a[2]=inf;
		for (j=0;j<=a[i];j++) Min(A[i].a[2],f[tot][j]);
		if (A[i].a[2]==inf) return puts("IMPOSSIBLE"),0;
		A[i].a[1]=a[i];
	}
	puts("POSSIBLE");
}
