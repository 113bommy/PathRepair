#include <bits/stdc++.h>
using namespace std;
static const int INF = 1010000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
int vx, vy;
int mat[1005][1005], tmp[1005][1005];
int xzip[2000005];
int calc(int y, int x) { return x * vy - y * vx; }
struct segtree {
  int val[8000002];
  int n;
  void init(int n_) {
    n = 1;
    while (n < n_) n <<= 1;
    for (int i = 0; i < n * 2; ++i) val[i] = 0;
  }
  int query(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return val[i];
    if (b <= l || r <= a) return INF;
    int md = (l + r) >> 1;
    val[i * 2 + 1] = max(val[i * 2 + 1], val[i]);
    val[i * 2 + 2] = max(val[i * 2 + 2], val[i]);
    return min(query(a, b, i * 2 + 1, l, md), query(a, b, i * 2 + 2, md, r));
  }
  void set(int a, int b, int i, int l, int r, int v) {
    if (a <= l && r <= b) {
      val[i] = max(v, val[i]);
      return;
    }
    if (b <= l || r <= a) return;
    int md = (l + r) >> 1;
    val[i * 2 + 1] = max(val[i * 2 + 1], val[i]);
    val[i * 2 + 2] = max(val[i * 2 + 2], val[i]);
    set(a, b, i * 2 + 1, l, md, v);
    set(a, b, i * 2 + 2, md, r, v);
    val[i] = min(val[i * 2 + 1], val[i * 2 + 2]);
  }
};
segtree seg;
int main() {
  scanf("%d%d%d", &n, &vx, &vy);
  swap(vx, vy);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &mat[i][j]);
  while (!(vx >= 0 && vy > 0)) {
    int nx = -vy, ny = vx;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) tmp[i][j] = mat[n - 1 - j][i];
    vy = ny;
    vx = nx;
    memcpy(mat, tmp, sizeof(mat));
  }
  int xn = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      xzip[xn++] = calc(i + 1, j);
      xzip[xn++] = calc(i, j + 1);
    }
  sort(xzip, xzip + xn);
  xn = unique(xzip, xzip + xn) - xzip;
  seg.init(xn);
  long long int res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int left = calc(i + 1, j), right = calc(i, j + 1);
      left = lower_bound(xzip, xzip + xn, left) - xzip;
      right = lower_bound(xzip, xzip + xn, right) - xzip;
      int lowest = seg.query(left, right, 0, 0, seg.n);
      res += max(0, mat[i][j] - lowest);
      seg.set(left, right, 0, 0, seg.n, mat[i][j]);
    }
  cout << res << endl;
  return 0;
}
