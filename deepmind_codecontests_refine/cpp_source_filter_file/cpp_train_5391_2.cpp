#include<iostream>
#include <algorithm>
#include<queue>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<set>
using LL = long long;
using namespace std;
 
const int M = 2e5 + 100;
const int mod = 1e9 + 7;
 
vector<int> e[M];
int n, sz[M], ans[M];
int fac[M], inv[M], inv2[M];
 
LL mul(LL a, LL b) {
	return a * b % mod;
}
 
void init() 
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++) 
		fac[i] = mul(fac[i - 1], i);
	inv[1] = 1;
	for (int i = 2; i <= n; i++) 
		//常规公式为inv[i] = mul((- mod / i), inv[mod % i])，为使得逆元为正数，分子加上mod仍有i*inv[i] = 1(mod p)
		inv[i] = mul((mod - mod / i), inv[mod % i]);
 
}
 
void dfs(int u, int fa) 
{
	sz[u] = 1;
	for (int v : e[u]) 
	{
		if (v != fa) 
		{
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
 
void reroot(int cur, int p)
{
	ans[cur] = 1LL * ans[p] * sz[cur] * inv[(n - sz[cur])] % mod;
	for (int i : g[cur])
	{
		if (i == p)
			continue;
		reroot(i,cur);
	}
}
int main() {
	cin >> n;
 	init();
	for (int i = 0; i < n - 1; i++) 
	{
		int u, v; 
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	ans[1] = fac[n];
	for (int i = 1; i <= n; i++) 
		ans[1] = mul(ans[1], inv[sz[i]]);
	for (int v : e[1]) 
		reroot(v, 1);
	for (int i = 1; i <= n; i++) 
		cout << ans[i] << "\n";
}