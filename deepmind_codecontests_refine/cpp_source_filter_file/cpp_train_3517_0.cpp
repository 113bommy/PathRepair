#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+1;

int n,m,k,f[MAXN],g[MAXN]={0},cnt[MAXN]={0};
map<pair<int,int>,bool> r;

inline find_root(int x) {
	return x==f[x] ? x:f[x]=find_root(f[x]);
}

inline bool merge(int x,int y) {
	x=find_root(x),y=find_root(y);
	if(x==y) return 0;
	f[x]=y,g[y]+=g[x];
	return 1;
}



int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=n; ++i) f[i]=i,g[i]=1;
	for(int i=1,a,b; i<=m; ++i) {
		scanf("%d %d",&a,&b);
		++cnt[a],++cnt[b];
		merge(a,b);
	}
	for(int i=1; i<=n; ++i) cnt[i]=g[find_root(i)]-cnt[i];
	for(int i=1,c,d; i<=k; ++i) {
		scanf("%d %d",&c,&d);
		if(f[c]==f[d]) --cnt[c],--cnt[d];
	}
	for(int i=1; i<=n; ++i) printf("%d ",cnt[i]-1);
	putchar('\n');
	return 0;
}