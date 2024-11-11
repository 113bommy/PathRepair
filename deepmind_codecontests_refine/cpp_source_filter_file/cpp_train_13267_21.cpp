#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
int ans;
int u[maxn];
int v[maxn];
int w[maxn];
int O[maxn];
int par[maxn];
int num[maxn];
void in();
void solve();
int dsu(int, int);
bool cmp(int, int);
int root(int);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;
    v[i]--;
  }
  for (int i = 0; i < n; i++) cin >> num[i];
}
void solve() {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += num[i];
    par[i] = -1;
    O[i] = i;
  }
  sort(O, O + n - 1, cmp);
  ans = w[O[0]];
  int ded = 0;
  for (int i = 0; i < n - 1; i++) {
    int x = dsu(u[i], v[i]);
    if (par[x] + sum - num[x] < 0) ded = 1;
    if (!ded) ans = w[O[i + 1]];
  }
}
int dsu(int u, int v) {
  u = root(u);
  v = root(v);
  if (par[u] < par[v]) swap(u, v);
  par[u] += par[v];
  num[u] += num[v];
  par[v] = u;
  return u;
}
int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
bool cmp(int i, int j) { return w[i] < w[j]; }
void out() { cout << ans; }
