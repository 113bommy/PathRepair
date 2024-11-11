#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;
vector<int> vv[maxn];
void getfac(int num, int idx) {
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      vv[idx].push_back(i);
      while (num % i == 0) {
        num /= i;
      }
    }
  }
  if (num != 1) vv[idx].push_back(num);
}
vector<int> G[maxn];
int ans[maxn];
int ans2[maxn] = {0};
vector<int> mm[maxm];
int road[maxn];
void dfs(int u, int fa, int d) {
  ans[u] = 0;
  road[d] = u + 1;
  for (auto i : vv[u]) {
    if (mm[i].size()) {
      ans[u] = max(ans[u], mm[i][mm[i].size() - 1]);
    }
    mm[i].push_back(d);
  }
  ans2[u] = road[ans[u]];
  for (auto v : G[u]) {
    if (v != fa) dfs(v, u, d + 1);
  }
  for (auto i : vv[u]) mm[i].pop_back();
}
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    getfac(a[i], i);
  }
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1, 2);
  int op, x, y;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      cout << ans2[x] - 1 << endl;
    } else {
      cin >> x >> y;
      a[x] = y;
      vv[x].clear();
      getfac(y, x);
      dfs(1, 1, 2);
    }
  }
  return 0;
}
