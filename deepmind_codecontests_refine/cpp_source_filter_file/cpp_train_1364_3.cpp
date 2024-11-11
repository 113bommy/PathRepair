#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
int n, c[mxN], a[mxN], vis[mxN], start, cost, t;
void dfs(int curr) {
  if (vis[curr] == 2) {
    t = 0;
    return;
  }
  if (vis[curr] == 1) {
    start = curr;
    return;
  }
  vis[curr] = 1;
  dfs(a[curr]);
  if (start != -1) t = min(t, c[curr]);
  if (start == curr) start = -1;
  vis[curr] = 2;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cost = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      start = -1;
      t = inf;
      dfs(i);
      cost += t;
    }
  }
  cout << cost << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  for (int tt = 1; tt <= T; ++tt) {
    solve();
  }
  return 0;
}
