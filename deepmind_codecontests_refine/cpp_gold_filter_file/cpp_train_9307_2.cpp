#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 100010;
int n, m, idx(0);
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct ele {
  int a, b, c;
  ele() {}
  ele(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator<(const ele &d) const {
    if (a != d.a) return a < d.a;
    if (b != d.b) return b < d.b;
    return c < d.c;
  }
};
vector<int> vxs[N], vxe[N], vys[N], vye[N];
map<ele, int> mp;
struct line {
  int x1, x2, y1, y2;
  int a, b, c, ix;
  void read() {
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
  }
  void init() {
    a = y2 - y1;
    b = x1 - x2;
    c = -(a * x1 + b * y1);
    int d = gcd(max((a), -(a)), max((b), -(b)));
    d = gcd(d, max((c), -(c)));
    if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0)) d = -d;
    a /= d, b /= d, c /= d;
    if (mp.count(ele(a, b, c)) == 0) mp[ele(a, b, c)] = idx++;
    int id = mp[ele(a, b, c)];
    if (x1 != x2) {
      vxe[id].push_back(2 * max(x1, x2) + 1);
      vxs[id].push_back(2 * min(x1, x2));
    } else {
      vye[id].push_back(2 * max(y1, y2) + 1);
      vys[id].push_back(2 * min(y1, y2));
    }
  }
} p[N];
struct circle {
  int x, y, r;
  void read() {
    scanf("%d%d", &x, &y);
    scanf("%d", &r);
  }
} c[N];
struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};
int dis2(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool C_intersec(circle &a, circle &b) {
  if (a.r != b.r) return true;
  if (dis2(point(a.x, a.y), point(b.x, b.y)) <= 4 * a.r * a.r) return true;
  return false;
}
void make(circle &a, circle &b, line &c) {
  c.x1 = a.x, c.y1 = a.y;
  c.x2 = b.x, c.y2 = b.y;
  if (a.y == b.y) {
    c.a = 2;
    c.b = 0, c.c = -(c.x1 + c.x2);
  } else if (a.x == b.x) {
    c.a = 0, c.b = 2, c.c = -(c.y1 + c.y2);
  } else {
    c.a = (c.x2 - c.x1) * 2;
    c.b = (c.y2 - c.y1) * 2;
    c.c = -(c.x2 * c.x2 - c.x1 * c.x1 + c.y2 * c.y2 - c.y1 * c.y1);
  }
  int d = gcd(max((c.a), -(c.a)), max((c.b), -(c.b)));
  d = gcd(d, max((c.c), -(c.c)));
  if (c.a < 0 || (c.a == 0 && c.b < 0) || (c.a == 0 && c.b == 0 && c.c < 0))
    d = -d;
  c.a /= d, c.b /= d, c.c /= d;
  c.x1 = (c.x1 + c.x2);
  c.y1 = (c.y1 + c.y2);
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 0; i < n; ++i) {
    p[i].read();
    p[i].init();
    p[i].ix = 0;
  }
  for (i = 0; i < idx; ++i) {
    sort(vxs[i].begin(), vxs[i].end());
    sort(vxe[i].begin(), vxe[i].end());
    sort(vys[i].begin(), vys[i].end());
    sort(vye[i].begin(), vye[i].end());
  }
  for (i = 0; i < m; ++i) c[i].read();
  int ans = 0;
  for (i = 0; i < m; ++i)
    for (j = i + 1; j < m; ++j) {
      if (C_intersec(c[i], c[j])) continue;
      make(c[i], c[j], p[n]);
      if (mp.count(ele(p[n].a, p[n].b, p[n].c)) == 0) continue;
      int id = mp[ele(p[n].a, p[n].b, p[n].c)];
      int ret = 0;
      ret += (upper_bound(vxs[id].begin(), vxs[id].end(), p[n].x1) -
              vxs[id].begin());
      ret -= (upper_bound(vxe[id].begin(), vxe[id].end(), p[n].x1) -
              vxe[id].begin());
      ret += (upper_bound(vys[id].begin(), vys[id].end(), p[n].y1) -
              vys[id].begin());
      ret -= (upper_bound(vye[id].begin(), vye[id].end(), p[n].y1) -
              vye[id].begin());
      ans += ret;
    }
  printf("%d\n", ans);
  return 0;
}
