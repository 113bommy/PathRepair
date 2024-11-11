#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct flow_network {
	int n;
	struct edge { int v; ll c; int rev; };
	vector< vector<edge> > G;
	flow_network(int _n) : n(_n), G(_n) {}
	void add_edge(int u, int v, ll c) {
		edge e = {v, c, (int)G[v].size()}, _e = {u, 0, (int)G[u].size()};
		G[u].push_back(e); G[v].push_back(_e);
	}
	ll dfs(int u, int t, ll f, vector<bool>& vis) {
		if (u == t) return f;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge& e = G[u][i];
			if (vis[e.v] || e.c == 0) continue;
			ll d = min(e.c, dfs(e.v, t, min(f, e.c), vis));
			if (d == 0) continue;
			e.c -= d;
			G[e.v][e.rev].c += d;
			return d;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll res = 0;
		for (;;) {
			vector<bool> vis(n);
			ll f = dfs(s, t, LLONG_MAX, vis);
			if (f == 0) return res;
			res += f;
		}
	}
};

int main() {
	for (;;) {
		int H, W; cin >> H >> W;
		if (!H && !W) break;
		vector<vector<bool> > a(H + 2, vector<bool>(W + 2));
		for (int y = 1; y <= H; y++) {
			string s; cin >> s;
			for (int x = 1; x <= W; x++)
				a[y][x] = (s[x - 1] == '#');
		}
		H += 2; W += 2;
		vector<vector<int > > b(H, vector<int>(W));
		for (int y = 1; y <= H - 1; y++)
			for (int x = 1; x <= W - 1; x++)
				b[y][x] = a[y - 1][x - 1] + a[y - 1][x] + a[y][x - 1] + a[y][x];
		int ans = 1, N = 0, M = 0;
		vector<vector<vector<int> > > unko(H, vector<vector<int> >(W));
		for (int y = 1; y <= H - 1; y++)
			for (int x = 1; x <= W - 1; x++) {
				if (b[y][x] != 3) continue;
				ans++;
				if (a[y][x - 1] && a[y][x]) {
					int _y;
					for (_y = y + 1; b[_y][x] == 4; _y++);
					if (b[_y][x] != 3) continue;
					for (int z = y; z <= _y; z++)
						unko[z][x].push_back(N);
					N++;
				}
			}
		for (int y = 1; y <= H - 1; y++)
			for (int x = 1; x <= W - 1; x++) {
				if (b[y][x] != 3) continue;
				if (a[y - 1][x] && a[y][x]) {
					int _x;
					for (_x = x + 1; b[y][_x] == 4; _x++);
					if (b[y][_x] != 3) continue;
					for (int z = x; z <= _x; z++)
						unko[y][z].push_back(M);
					M++;
				}
			}
		flow_network fn(N + M + 2);
		int s = N + M, t = N + M + 1;
		for (int u = 0; u < N; u++)
			fn.add_edge(s, u, 1);
		for (int v = 0; v < M; v++)
			fn.add_edge(N + v, t, 1);
		for (int y = 1; y <= H - 1; y++)
			for (int x = 1; x <= W - 1; x++) {
				if (unko[y][x].size() != 2) continue;
				int u = unko[y][x][0], v = unko[y][x][1];
				fn.add_edge(u, N + v, 100000);
			}
		cout << ans - N - M + fn.max_flow(s, t) << endl;
	}
}