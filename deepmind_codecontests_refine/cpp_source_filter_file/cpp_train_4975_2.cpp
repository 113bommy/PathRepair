#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
inline int read() {
	int x = 0, f = 0; char ch = 0;
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int ans[N];
vector <int> G[N], col[2], mod[3];
void dfs(int x, int c, int fa) {
	col[c].push_back(x);
	for (auto y : G[x]) if (y != fa) dfs(y, c ^ 1, x);
}
void sol(int i, int j) {
	while (!col[i].empty() && !mod[j].empty()) {
		ans[col[i].back()] = mod[j].back();
		col[i].pop_back(), mod[j].pop_back();
	}
}
int main() {
	int n = read();
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		G[x].pb(y), G[y].pb(x);
	}
	for (int i = 1; i <= n; i++) mod[i % 3].pb(i);
	dfs(1, 0, 0);
	sol(col[0].size() < col[1].size(), 1), sol(col[0].size() < col[1].size(), 2);
	sol(0, 0), sol(1, 0);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}/kk