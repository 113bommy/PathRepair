#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, timer, n, m, taken, k, include[siz], par[siz], cnt;
struct E {
  long long x, y, w, in, id;
} edg[siz];
bool cmp(E a, E b) {
  if (a.w != b.w) return a.w < b.w;
  return a.x < b.x;
}
long long get_par(long long u) {
  if (u == par[u]) return u;
  return par[u] = get_par(par[u]);
}
void kruskal(long long tomin) {
  for (long long i = 1; i <= m; i++)
    edg[i].w = edg[i].in + (edg[i].x == 1 ? tomin : 0);
  for (long long i = 1; i <= n; i++) par[i] = i;
  sort(edg + 1, edg + 1 + m, cmp);
  taken = 0;
  cnt = 0;
  for (long long i = 1; i <= m; i++) {
    long long u = edg[i].x, v = edg[i].y;
    u = get_par(u);
    v = get_par(v);
    if (u == v) continue;
    if (edg[i].x == 1 and taken == k) continue;
    taken += (edg[i].x == 1);
    include[++cnt] = edg[i].id;
    par[v] = u;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= m; i++) {
    cin >> edg[i].x >> edg[i].y >> edg[i].in, edg[i].id = i;
    if (edg[i].x > edg[i].y) swap(edg[i].x, edg[i].y);
  }
  kruskal(-100000);
  if (taken < k or cnt < n - 1) return cout << -1 << endl, 0;
  long long l = -100000, r = 100000;
  long long mins = -1;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    kruskal(mid);
    if (taken >= k) {
      mins = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  kruskal(mins);
  cout << n - 1 << endl;
  for (long long i = 1; i < n; i++) cout << include[i] << " ";
}
