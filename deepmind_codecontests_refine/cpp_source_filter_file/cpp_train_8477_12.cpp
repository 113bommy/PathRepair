#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxN = (int)1e5 + 100;
const int BLOCK = 250;
int bl[maxN];
struct pt {
  long long x, y;
  pt(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
bool del(const pt& x, const pt& y, const pt& z) {
  return (y.y - x.y) * (x.x - z.x) <= (z.y - x.y) * (x.x - y.x);
}
long long get(const pt& a, long long y) { return (a.x * y + a.y); }
const long long INF = 2 * (long long)1e18;
vector<pt> cht[maxN];
void add(long long x, long long y, int bl) {
  pt nw(x, y);
  while (cht[bl].size() >= 2 &&
         del(cht[bl][cht[bl].size() - 1], cht[bl][cht[bl].size() - 2], nw)) {
    cht[bl].pop_back();
  }
  cht[bl].push_back(nw);
}
pair<long long, int> get(long long x, int bl) {
  if (cht[bl].empty()) return make_pair(-INF, -1);
  int l = 0;
  int r = cht[bl].size() - 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (get(cht[bl][m], x) > get(cht[bl][m + 1], x)) {
      r = m;
    } else
      l = m;
  }
  return max(make_pair(get(cht[bl][r], x), cht[bl][r].x),
             make_pair(get(cht[bl][l], x), cht[bl][l].x));
}
int f[maxN];
int n, w;
int lim;
void build(int v) {
  cht[v].clear();
  for (int i = v * BLOCK; i <= min(lim - 1, v + BLOCK - 1); i++) {
    add(i, 1LL * f[i] * i, v);
  }
}
vector<int> byB[maxN];
void add(int v) {
  int i = 0;
  while (i + BLOCK - 1 <= v) {
    bl[i / BLOCK]++;
    i += BLOCK;
  }
  if (i <= v) {
    int l = i;
    int r = min(i + BLOCK - 1, lim - 1);
    int id = i / BLOCK;
    for (int j = l; j <= r; j++) {
      f[j] += bl[id];
    }
    bl[id] = 0;
    for (int j = l; j <= v; j++) {
      f[j]++;
    }
    build(id);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> w;
  int max_a = 0;
  int max_b = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    byB[b].push_back(a);
    max_a = max(max_a, a);
    max_b = max(max_b, b);
  }
  lim = max_a + 3;
  for (int i = 0; i * BLOCK < lim; i++) {
    build(i);
  }
  int num_c = n;
  vector<pair<long long, int> > ans;
  for (int i = 0; i <= max_b + 1; i++) {
    if (i > 0) {
      for (int a : byB[i - 1]) {
        add(a);
        num_c--;
      }
    }
    pair<long long, int> best = make_pair(-INF, -1);
    for (int j = 0; j * BLOCK < lim; j++) {
      best = max(best, get(bl[j], j));
    }
    cout << (1LL * num_c * w * i + best.first) << " " << best.second << '\n';
  }
  return 0;
}
