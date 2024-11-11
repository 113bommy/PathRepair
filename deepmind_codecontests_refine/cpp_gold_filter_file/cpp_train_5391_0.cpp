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
long long n, sz[M], ans[M];
long long fac[M], inv[M];

LL mul(LL a, LL b) {
	return a * b % mod;
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = mul(fac[i - 1], i);
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = mul((mod - mod / i), inv[mod % i]);
}

void dfs(int u, int fa) {
	sz[u] = 1;
	for (int v : e[u]) {
		if (v != fa) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}

void reroot(int u, int fa) {
	ans[u] = mul(mul(ans[fa], sz[u]), inv[n - sz[u]]);
	for (int v : e[u]) {
		if (v != fa) {
			reroot(v, u);
		}
	}
}

int main() {
	cin >> n;
	init();
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	ans[1] = fac[n];
	for (int i = 1; i <= n; i++)
		ans[1] =  ans[1] *inv[ sz[i]] % mod;
	for (int v : e[1]) reroot(v, 1);
	for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
