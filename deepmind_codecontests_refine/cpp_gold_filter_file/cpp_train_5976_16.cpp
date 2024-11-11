#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int oo = INT_MAX;
const int maxN = 1e6 + 1;
int n;
int cnt[maxN];
vector<int> f[maxN];
inline void nhap() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    f[u].push_back(v);
    f[v].push_back(u);
  }
}
bool oke[maxN];
int dem(int u, int par) {
  cnt[u] = 1;
  for (int x : f[u])
    if (x != par && oke[x] == false) cnt[u] += dem(x, u);
  return cnt[u];
}
int finding(int u, int par, int res) {
  for (int x : f[u])
    if (x != par && oke[x] == false)
      if (cnt[x] >= res) return finding(x, u, res);
  return u;
}
char ans[maxN];
inline void sol(int u, int par, char c) {
  int n = dem(u, par);
  if (n == 0) return;
  int t = finding(u, par, n / 2);
  oke[t] = true;
  ans[t] = c;
  c++;
  for (int x : f[t])
    if (oke[x] == false) sol(x, t, c);
}
inline void solve() {
  sol(1, 1, 'A');
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    nhap();
    solve();
  }
}
