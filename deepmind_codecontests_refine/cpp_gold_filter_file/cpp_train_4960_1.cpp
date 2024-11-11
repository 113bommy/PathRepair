#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int const N = 1e6 + 20;
int n, a[N];
ll res1[N], res2[N], ans;
bool mark[N];
vector<int> g[N];
int id[N];
inline bool cmp(int x, int y) { return a[x] < a[y]; }
int dsz[N], dpar[N];
int droot(int v) { return dpar[v] == v ? v : dpar[v] = droot(dpar[v]); }
void calc(ll res[N]) {
  iota(id, id + n, 0);
  sort(id, id + n, cmp);
  memset(mark, 0, sizeof mark);
  for (int i = 0; i < n; i++) dsz[i] = 1, dpar[i] = i;
  for (int ii = 0; ii < n; ii++) {
    int i = id[ii];
    mark[i] = 1;
    for (int j : g[i]) {
      if (!mark[j]) continue;
      int k = droot(j);
      res[i] += 1ll * dsz[i] * dsz[k];
      dsz[i] += dsz[k];
      dsz[k] = 0;
      dpar[k] = i;
    }
  }
}
int32_t main() {
  scanf("%d ", &n);
  for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
  for (int i = 0, u, v; i < n - 1; i++) {
    scanf("%d %d ", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  calc(res1);
  for (int i = 0; i < n; i++) a[i] *= -1;
  calc(res2);
  for (int i = 0; i < n; i++) a[i] *= -1;
  for (int i = 0; i < n; i++) ans += (res1[i] - res2[i]) * a[i];
  printf("%lld\n", ans);
}
