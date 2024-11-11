#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 3e5 + 5;
class Vector {
 public:
  double x, y;
  inline Vector() {}
  inline Vector(int _x, int _y) : x(_x), y(_y) {
    if (x) {
      y /= abs(x);
      x /= abs(x);
    } else
      (y /= abs(y)) *= INF;
    return;
  }
  bool operator<(const Vector &oth) const {
    return make_pair(x, y) < make_pair(oth.x, oth.y);
  }
} slp[maxn];
int n, m, q;
int s[maxn], ans[maxn];
vector<pair<int, int> > qry[maxn];
map<Vector, int> mp;
class FenwickTree {
 private:
  inline void update(int x, int k) {
    for (++x; x <= n; x += x & (-x)) {
      dat[x] += k;
    }
    return;
  }

 public:
  int dat[maxn];
  inline void update(int l, int r, int k) {
    if (l > r) return;
    update(l, k);
    update(r + 1, -k);
    return;
  }
  inline int query(int x) {
    int ret = 0;
    for (++x; x; x -= x & (-x)) ret += dat[x];
    return ret;
  }
} fen;
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    int k;
    scanf("%d", &k);
    s[i] = m;
    int x, y, nx, ny, sx, sy;
    for (int j = (0); j < (k); ++j) {
      scanf("%d%d", &nx, &ny);
      if (j)
        slp[m++] = Vector(x - nx, y - ny);
      else
        sx = nx, sy = ny;
      x = nx, y = ny;
    }
    slp[m++] = Vector(x - sx, y - sy);
  }
  s[n] = m;
  scanf("%d", &q);
  for (int i = (0); i < (q); ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;
    qry[r].push_back(make_pair(l, i));
  }
  for (int i = 0, j = 0; i < n; ++i) {
    for (; j < s[i + 1]; ++j) {
      int pos = (mp.find(slp[j]) != mp.end()) ? mp[slp[j]] : -1;
      fen.update(pos + 1, i, 1);
      mp[slp[j]] = i;
    }
    for (int x = (0); x < (qry[i].size()); ++x) {
      ans[qry[i][x].second] = fen.query(qry[i][x].first);
    }
  }
  for (int i = (0); i < (q); ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
