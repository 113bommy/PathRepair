#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int l[100005], r[100005];
int last[100005], cnt;
vector<int> v[100005];
void dfs(int p, int fa) {
  l[p] = ++cnt;
  for (auto u : v[p])
    if (u != fa) dfs(u, p);
  r[p] = cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q, k;
  cin >> n >> m >> q >> k;
  int x, y;
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    if (last[y]) v[last[y]].emplace_back(x);
    last[y] = x;
  }
  for (int i = 1; i <= n; i++)
    if (!l[i]) dfs(i, -1);
  int t;
  for (int i = 1; i <= k; i++) {
    cin >> x >> y;
    t = last[y];
    if (l[x] <= l[y] && r[x] >= r[y]) {
      cout << r[x] - l[x] + 1 << '\n';
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
