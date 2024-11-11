#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn], cnt0[maxn], cnt1[maxn], cnt[maxn][2];
vector<int> g[maxn];
void dfs1(int u, int f) {
  if (b[u] != c[u]) {
    if (c[u])
      cnt1[u] = 1;
    else
      cnt0[u] = 1;
  }
  for (auto v : g[u]) {
    if (v == f) continue;
    a[v] = min(a[v], a[u]);
    dfs1(v, u);
    cnt1[u] += cnt1[v];
    cnt0[u] += cnt0[v];
  }
}
long long ans;
void dfs2(int u, int f) {
  for (auto v : g[u]) {
    if (v == f) continue;
    dfs2(v, u);
    if (cnt0[v] && cnt1[v]) {
      if (cnt0[v] <= cnt1[v])
        ans += 2ll * a[v] * (cnt0[v] - cnt[v][0]);
      else
        ans += 2ll * a[v] * (cnt1[v] - cnt[v][1]);
      if (cnt0[v] >= cnt1[v]) {
        cnt[u][0] += cnt1[v];
        cnt[u][1] += cnt1[v];
      } else {
        cnt[u][0] += cnt0[v];
        cnt[u][1] += cnt0[v];
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  if (cnt0[1] != cnt1[1]) {
    cout << "-1\n";
    return 0;
  }
  g[0].push_back(1);
  g[1].push_back(0);
  dfs2(0, -1);
  cout << ans << "\n";
}
