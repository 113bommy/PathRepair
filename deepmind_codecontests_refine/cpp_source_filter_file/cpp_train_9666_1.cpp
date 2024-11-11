#include<cstdio>
using namespace std;

const int N=100000+5;

int n, m;
int d[N], v[N], c[N];

int cnt, first[N], to[2*N], next[2*N];
void add(int u, int v) {
	to[++cnt]=v; next[cnt]=first[u]; first[u]=cnt;
	to[++cnt]=u; next[cnt]=first[v]; first[v]=cnt;
}

int col[N], mark[N];
void work(int now, int len, int color) {
	if(len<0||(col[now]&&mark[now]>=len)) return;
	if(col[now]==0) col[now]=color, mark[now]=len;
	for(int p=first[now]; p; p=next[p])  work(to[p], len-1, color);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=m; i++) {
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	int Q;
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++) scanf("%d%d%d", &v[i], &d[i], &c[i]);
	for(int i=Q; i>=1; i--) work(v[i], 0, d[i], c[i]);
	for(int i=1; i<=n; i++) printf("%d\n", col[i]);
	return 0;
}