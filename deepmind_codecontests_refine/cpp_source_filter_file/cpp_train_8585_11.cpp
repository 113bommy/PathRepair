#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using db = double;
using vi = vector<int>;
const int inf = 0x3f3f3f3f;
const db eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
int n, m;
int dep[maxn], fa[maxn], cnt[maxn];
vector<int> G[maxn];
void dfs(int u, int pre) {
  dep[u] = dep[pre] + 1;
  fa[u] = pre;
  for (auto v : G[u]) {
    if (v == pre) continue;
    if (!dep[v]) {
      dfs(v, u);
      cnt[u] += cnt[v];
    } else if (dep[v] < dep[u]) {
      cnt[u] += 1;
      cnt[v] -= 1;
    }
  }
}
int lb, ub, L, U;
int o = 0;
void dfs1(int u, int pre) {
  for (auto v : G[u]) {
    if (v == pre) continue;
    if (dep[v] == dep[u] + 1)
      dfs1(v, u);
    else if (dep[v] < dep[u]) {
      if (!lb) {
        lb = u;
        ub = v;
      } else {
        L = u;
        U = v;
      }
    }
    if (L) return;
  }
}
int ans[maxn], num = 0, tmp[maxn], num1 = 0;
void getans(int u, int v) {
  if (dep[u] < dep[v]) {
    memset(tmp, 0, sizeof(tmp));
    num1 = 0;
    v = fa[v];
    while (v != u) {
      tmp[++num1] = v;
      v = fa[v];
    }
    tmp[++num1] = u;
    reverse(tmp + 1, tmp + num1 + 1);
    for (int i = 1; i <= num1; ++i) ans[++num] = tmp[i];
  } else {
    while (u != v) {
      ans[++num] = u;
      u = fa[u];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    if (!fa[i]) dfs(i, i);
  o = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 1) {
      o = i;
      break;
    }
  }
  if (!o) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  dfs1(o, fa[o]);
  if (dep[U] < dep[ub]) swap(U, ub), swap(L, lb);
  int x = lb, y = L;
  while (x != y) {
    if (dep[x] > dep[y])
      x = fa[x];
    else
      y = fa[y];
  }
  getans(x, lb);
  ans[++num] = lb;
  getans(ub, U);
  ans[++num] = U;
  cout << num << " ";
  for (int i = 1; i <= num; ++i) cout << ans[i] << " \n"[i == num];
  memset(ans, 0, sizeof(ans));
  num = 0;
  getans(x, L);
  ans[++num] = L;
  ans[++num] = U;
  cout << num << " ";
  for (int i = 1; i <= num; ++i) cout << ans[i] << " \n"[i == num];
  num = 0;
  memset(ans, 0, sizeof(ans));
  getans(x, U);
  ans[++num] = U;
  cout << num << " ";
  for (int i = 1; i <= num; ++i) cout << ans[i] << " \n"[i == num];
  return 0;
}
