#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N], a[2], b[3];
int n, m, c[N], ans[N];
void dfs(int v, int p){
	c[v] = c[p] ^ 1;
	a[c[v]].pb(v);
	for(auto to : g[v])
		if(to != p)
			dfs(to, v);
}            
int aa(int i){
	int x = a[i].back();
	a[i].pop_back();
	return x;
}
int bb(int i){
	int x = b[i].back();
	b[i].pop_back();
	return x;
}
void ff(int i, int j){
	while(a[i].size() && b[j].size())
		ans[aa(i)] = bb(j);
}
int main()
{
	scanf("%d", &n);
	m = n - 1;
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++)
		b[i % 3].pb(i);
	if(a[0].size() > a[1].size()){ //如果与1距离为偶的点的个数>与a的距离为奇数的点的个数 
		ff(0, 1); //与1偶数   模3为1 
	}else{
		ff(1, 1); //与1奇数   模3为1
	}        
	if(a[0].size() > a[1].size()){
		ff(0, 2); //与1偶数   模3为2 
	}else{
		ff(1, 2); //与1奇数    模3为2 
	}        
	ff(0, 0);
	ff(1, 0);
	assert(a[0].empty());
	assert(a[1].empty());
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}            