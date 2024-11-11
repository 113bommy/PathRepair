#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;
int n, va, vb, vc, vd, N = 0, ans = 0, f[Maxn];
long long ry[Maxn];
inline int get() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int v = ch - 48;
  while (isdigit(ch = getchar())) v = v * 10 + ch - 48;
  return v;
}
struct Point {
  long long x, y;
  bool operator<(const Point &rhs) const {
    return x == rhs.x ? y < rhs.y : x > rhs.x;
  }
  void init() {
    static long long tx, ty;
    tx = get();
    ty = get();
    x = vb * ty - va * tx;
    y = vd * ty - vc * tx;
    ry[++N] = y;
  }
} p[Maxn];
class Bit {
  int v[Maxn];

 public:
  void modify(int x, int c) {
    for (; x <= N; x += x & -x)
      if (v[x] < c) v[x] = c;
  }
  int qry(int x) {
    int res = 0;
    for (; x; x -= x & -x)
      if (res < v[x]) res = v[x];
    return res;
  }
} tr;
int main() {
  n = get();
  va = get();
  vb = get();
  vc = get();
  vd = get();
  for (int i = 1; i <= n; i++) p[i].init();
  ++n;
  ry[++N] = 0;
  sort(ry + 1, ry + N + 1);
  N = unique(ry + 1, ry + N + 1) - ry - 1;
  for (int i = 1; i <= n; i++)
    p[i].y = lower_bound(ry + 1, ry + N + 1, p[i].y) - ry;
  int g = p[n].y;
  sort(p + 1, p + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= n && p[j].x > p[i].x; j++) tr.modify(p[j].y, f[j]);
    f[i] = tr.qry(p[i].y - 1) + 1;
    if (!p[i].x && p[i].y == g) {
      ans = f[i] - 1;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
