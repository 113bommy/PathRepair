#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 100;
const int oo = 2e9;
int n, m, p;
struct data {
  int power;
  ll cost;
  bool operator<(data o) const { return power < o.power; }
} atk[N], def[N];
ll satk[N], sdef[N];
struct data2 {
  ll x, y, z;
  bool operator<(data2 o) const { return x < o.x; }
} mon[N];
ll t[N << 2];
ll add[N << 2];
void build(int node, int L, int R) {
  if (L == R) {
    t[node] = -def[L].cost;
    add[node] = 0;
    return;
  }
  int mid = (L + R) >> 1, lc = node << 1, rc = lc | 1;
  build(lc, L, mid);
  build(rc, mid + 1, R);
  t[node] = max(t[lc], t[rc]);
  add[node] = 0;
}
void shift(int node, int L, int R) {
  if (add[node] == 0) return;
  int mid = (L + R) >> 1, lc = node << 1, rc = lc | 1;
  t[lc] += add[node];
  t[rc] += add[node];
  add[lc] += add[node];
  add[rc] += add[node];
  add[node] = 0;
}
void upd(int node, int L, int R, int l, int r, ll x) {
  if (r < L || R < l) return;
  if (l <= L && R <= r) {
    t[node] += x;
    add[node] += x;
    return;
  }
  shift(node, L, R);
  int mid = (L + R) >> 1, lc = node << 1, rc = lc | 1;
  upd(lc, L, mid, l, r, x);
  upd(rc, mid + 1, R, l, r, x);
  t[node] = max(t[lc], t[rc]);
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d %lld", &atk[i].power, &atk[i].cost);
  for (int i = 0; i < m; i++) scanf("%d %lld", &def[i].power, &def[i].cost);
  for (int i = 0; i < p; i++)
    scanf("%lld %lld %lld", &mon[i].y, &mon[i].x, &mon[i].z);
  sort(atk, atk + n);
  sort(def, def + m);
  sort(mon, mon + p);
  build(1, 0, m - 1);
  satk[n - 1] = atk[n - 1].cost;
  for (int i = n - 2; i >= 0; i--) satk[i] = min(satk[i + 1], atk[i].cost);
  sdef[m - 1] = def[m - 1].cost;
  for (int i = m - 2; i >= 0; i--) sdef[i] = min(sdef[i + 1], def[i].cost);
  ll mn1 = oo, mn2 = oo;
  for (int i = 0; i < n; i++) mn1 = min(mn1, atk[i].cost);
  for (int i = 0; i < m; i++) mn2 = min(mn2, def[i].cost);
  ll ans = -mn1 - mn2;
  int ptr = 0;
  for (int i = 0; i < p; i++) {
    while (ptr + 1 < n && atk[ptr].power <= mon[i].x) ptr++;
    if (atk[ptr].power <= mon[i].x) break;
    int lo = 0, hi = m - 1, idx = m;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (def[mid].power > mon[i].y)
        idx = mid, hi = mid - 1;
      else
        lo = mid + 1;
    }
    if (idx == m) continue;
    upd(1, 0, m - 1, idx, m - 1, mon[i].z);
    ans = max(ans, t[1] - satk[ptr]);
  }
  printf("%lld\n", ans);
  return 0;
}
