#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e3 + 100;
const int maxM = (int)1e3 + 100;
const int mod = (int)1e9 + 7;
const int maxlog = (int)20;
const int P = mod;
int n, m, used[maxn], col[maxn], q, a[maxn], mn[maxn];
map<int, int> cnt;
vector<int> g[maxn], gr[maxn], order;
void dfs(int v) {
  used[v] = 1;
  for (int to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  order.push_back(v);
}
void dfs1(int v) {
  col[v] = q;
  used[v] = 1;
  for (int to : gr[v]) {
    if (!used[to]) {
      dfs1(to);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], mn[i] = -1;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    gr[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  memset(used, 0, sizeof(used));
  reverse(order.begin(), order.end());
  for (int niza : order) {
    if (!used[niza]) {
      q++;
      dfs1(niza);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mn[col[i]] == -1)
      mn[col[i]] = a[i];
    else
      mn[col[i]] = min(mn[col[i]], a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (mn[col[i]] == a[i]) cnt[col[i]]++;
  }
  int ans = 0, tot = 1;
  for (int i = 1; i <= q; i++) {
    ans += mn[i];
    tot = (tot * 1ll * cnt[i]) % mod;
  }
  cout << ans << " " << tot;
}
