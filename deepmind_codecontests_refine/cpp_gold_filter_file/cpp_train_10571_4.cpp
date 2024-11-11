#include <bits/stdc++.h>
using namespace std;
const int d1[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int d2[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
const int d3[4][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}};
const int N = 200005;
int n, m, top, ok[4];
map<int, int> mn, mx;
struct P {
  int x, y;
  P() {}
  P(int _x, int _y) {
    x = _x;
    y = _y;
  }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  long long operator*(const P &a) const {
    return 1ll * x * a.y - 1ll * y * a.x;
  }
  bool operator<(const P &a) const { return x == a.x ? y < a.y : x < a.x; }
  bool operator==(const P &a) const { return x == a.x && y == a.y; }
  long long dis() { return 1ll * x * x + 1ll * y * y; }
} a[N], q[N * 4];
bool cmp(P x, P y) {
  if (x * y) return x * y > 0;
  return x.dis() < y.dis();
}
void Convex_hull() {
  sort(q + 1, q + top + 1);
  top = unique(q + 1, q + top + 1) - q - 1;
  P bas = a[1];
  for (int i = (int)(1); i <= (int)(top); i++) q[i] = q[i] - bas;
  sort(q + 2, q + top + 1, cmp);
  n = top;
  top = 1;
  for (int i = (int)(2); i <= (int)(n); i++) {
    for (; top >= 2 && (q[top] - q[top - 1]) * (q[i] - q[top]) <= 0; top--)
      ;
    q[++top] = q[i];
  }
  for (int i = (int)(1); i <= (int)(top); i++) q[i] = q[i] + bas;
}
bool chk(int x, int y) {
  if (mn.find(x) == mn.end()) return 0;
  return mn[x] <= y && mx[x] >= y;
}
void solve() {
  top = 0;
  scanf("%d%d", &n, &m);
  if (!(n + m)) exit(0);
  mn.clear();
  mx.clear();
  for (int i = (int)(1); i <= (int)(m); i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = (int)(1); i <= (int)(m); i++) mn[a[i].x] = n + 1, mx[a[i].x] = 0;
  for (int i = (int)(1); i <= (int)(m); i++) {
    mn[a[i].x] = min(mn[a[i].x], a[i].y);
    mx[a[i].x] = max(mx[a[i].x], a[i].y);
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    ok[0] = ok[1] = ok[2] = ok[3] = 1;
    for (int j = (int)(0); j <= (int)(3); j++)
      if (!chk(a[i].x + d1[j][0], a[i].y + d1[j][1]))
        ok[j] = ok[(j + 1) % 4] = 0;
    for (int j = (int)(0); j <= (int)(3); j++)
      if (!chk(a[i].x + d2[j][0], a[i].y + d2[j][1])) ok[j] = 0;
    for (int j = (int)(0); j <= (int)(3); j++)
      if (ok[j]) q[++top] = P(a[i].x + d3[j][0], a[i].y + d3[j][1]);
  }
  Convex_hull();
  reverse(q + 2, q + top + 1);
  printf("%d\n", top);
  for (int i = (int)(1); i <= (int)(top); i++)
    printf("%d %d\n", q[i].x, q[i].y);
}
int main() {
  for (;;) solve();
}
