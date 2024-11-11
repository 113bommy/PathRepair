#include <bits/stdc++.h>
using namespace std;
const int _ = 4e5 + 10;
class point {
 public:
  int x, y, z, p;
  bool operator==(const point& b) const {
    return x == b.x && y == b.y && z == b.z;
  }
  bool operator<(const point& b) const {
    return y < b.y || (y == b.y && z < b.z);
  }
} a[_], c[_];
bool cmp(point x, point y) {
  return x.x < y.x || (x.x == y.x && (x.y < y.y || (x.y == y.y && x.z < y.z)));
}
int n;
struct zkw {
  int M;
  int d[_ * 4];
  inline void Build(int n) {
    for (M = 1; M < n; M <<= 1)
      ;
    for (int i = M + 1; i <= M + n; i++) d[i] = 0;
    for (int i = M - 1; i; i--) d[i] = max(d[i << 1], d[i << 1 | 1]);
  }
  inline void change(int pos, int v) {
    for (int i = (M + pos); i; i >>= 1) d[i] = max(d[i], v);
  }
  inline void clear(int pos) {
    for (int i = (M + pos); i; i >>= 1) d[i] = 0;
  }
  inline int sum(int l, int r, int res = 0) {
    for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) res = max(res, d[l ^ 1]);
      if (r & 1) res = max(res, d[r ^ 1]);
    }
    return res;
  }
} T;
void read() {
  int aa[_];
  int nn;
  cin >> nn;
  for (int i = 1; i <= nn; i++) cin >> aa[i];
  for (int i = 1; i <= nn; i++) {
    int x, y, z;
    x = i;
    y = i - aa[i];
    z = aa[i] + 1;
    if (y >= 0) {
      a[++n] = {x, y + 2, z, 1};
    }
  }
}
void cdq(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  cdq(l, mid);
  sort(a + mid + 1, a + r + 1);
  for (int i = l, j = mid + 1; j <= r; j++) {
    while (i <= mid && a[i].y <= a[j].y) T.change(a[i].z, a[i].p), i++;
    a[j].p = max(a[j].p, T.sum(1, a[j].z - 1) + 1);
  }
  sort(a + l, a + r + 1, cmp);
  for (int i = l; i <= mid; i++) T.clear(a[i].z);
  cdq(mid + 1, r);
  for (int i = l; i <= r; i++) c[i] = a[i];
  int k = l - 1;
  for (int i = l, j = mid + 1; i <= mid || j <= r;) {
    if (i <= mid && j <= r) {
      if (c[i] < c[j])
        a[++k] = c[i], i++;
      else
        a[++k] = c[j], j++;
    } else if (i <= mid)
      a[++k] = c[i], i++;
    else if (j <= r)
      a[++k] = c[j], j++;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  read();
  T.Build(_);
  sort(a + 1, a + 1 + n, cmp);
  cdq(1, n);
  sort(a + 1, a + 1 + n, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, a[i].p);
  cout << ans << '\n';
  return 0;
}
