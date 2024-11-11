#include <bits/stdc++.h>
using namespace std;
int n, q, e[200002], box, a[200002], b[200002], pos[200002], d[1000001];
long long ans[200002];
bool ss(const int &u, const int &v) {
  int uu = a[u] / box, vv = a[v] / box;
  if (uu != vv) return uu < vv;
  if (uu & 1)
    return b[u] > b[v];
  else
    return b[u] < b[v];
}
long long kq = 0;
void add(int u) {
  kq -= d[u] * 1ll * d[u] * 1ll * u;
  ++d[u];
  kq += d[u] * 1ll * d[u] * 1ll * u;
}
void del(int u) {
  kq -= d[u] * 1ll * d[u] * 1ll * u;
  --d[u];
  kq += d[u] * 1ll * d[u] * 1ll * u;
}
int main() {
  scanf("%d%d", &n, &q);
  box = round(sqrt(n));
  for (int i = 1; i <= n; ++i) scanf("%d", e + i);
  for (int i = 1; i <= q; ++i) scanf("%d%d", a + i, b + i), pos[i] = i;
  sort(pos + 1, pos + 1 + q, ss);
  add(e[1]);
  int l = 1, r = 1;
  for (int i = 1, u, v; i <= n; ++i) {
    u = a[pos[i]], v = b[pos[i]];
    while (l < u) del(e[l++]);
    while (l > u) add(e[--l]);
    while (r < v) add(e[++r]);
    while (r > v) del(e[r--]);
    ans[pos[i]] = kq;
  }
  for (int i = 1; i <= q; ++i) printf("%I64d\n", ans[i]);
}
