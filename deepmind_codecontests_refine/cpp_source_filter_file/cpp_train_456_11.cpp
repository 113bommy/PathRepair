#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[2000];
struct st {
  int v, l, r;
  st() {}
  st(int _v, int _l, int _r) {
    v = _v;
    l = _l;
    r = _r;
  }
};
int gl, gr;
vector<st> g[2000];
void dfs(int v) {
  vis[v] = 1;
  for (auto x : g[v]) {
    if (!vis[x.v] and x.l <= gl and gr <= x.r) dfs(x.v);
  }
}
bool func(int l, int r) {
  for (int i = 0; i < n; i++) vis[i] = 0;
  gl = l;
  gr = r;
  dfs(0);
  return vis[n - 1];
}
int bs(int l) {
  int hi = 1e6 + 5;
  int lo = l + 1;
  int mid;
  while (hi - lo > 1) {
    mid = (hi + lo) / 2;
    if (func(l, mid))
      lo = mid;
    else
      hi = mid;
  }
  return lo;
}
int main() {
  cin >> n >> m;
  long long int u, v, l, r;
  vector<int> lk;
  while (m--) {
    cin >> u >> v >> l >> r;
    u--;
    v--;
    g[u].push_back(st(v, l, r));
    g[v].push_back(st(u, l, r));
    lk.push_back(l);
  }
  sort(lk.begin(), lk.end());
  long long int ans = 0;
  for (auto x : lk) {
    if (func(x, x + 1)) {
      r = bs(x);
      ans = max(ans, r - x + 1);
    }
    if (ans == 0 and func(x, x)) {
      ans = 1;
    }
  }
  if (ans == 0) {
    cout << "Nice work, Dima!\n";
  }
  cout << ans;
}
