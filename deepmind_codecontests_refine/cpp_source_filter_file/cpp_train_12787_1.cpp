#include<bits/stdc++.h>
using namespace std;
const int boss=1e5;
int n,m,vis[boss+10];
vector<int> lj[boss+10];
int dfs(int u,int fa) {
	if (lj[u].size()>2) return u;
	for (int i:lj[u]) if (i!=fa) return dfs(i,u);
	return u;
}
int main() {
	int i,u,v;
	scanf("%d",&n);
	for (i=1; i<n; i++) {
		scanf("%d%d",&u,&v)
		u++;
		v++;
		lj[u].push_back(v);
		lj[v].push_back(u);
	}
	for (i=1; i<=n; i++) if (lj[i].size()==1) vis[dfs(i,0)]=1,m++;
	for (i=1; i<=n; i++) if (vis[i]) m--;

	printf("%d",max(m,1));
	return 0;
}