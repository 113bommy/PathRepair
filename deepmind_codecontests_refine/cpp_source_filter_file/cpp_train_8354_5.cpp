#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 2001;
double M(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
struct S {
  double x[2], y;
  bool operator<(const S &s) const { return M(x[0], y, s.x[0], s.y) > 0; }
} s[kMaxN], a[kMaxN * kMaxN];
struct V {
  double x, y;
  bool operator<(const V &v) const { return M(x, y, v.x, v.y) > 0; }
} v[kMaxN * kMaxN];
int l[kMaxN], r[kMaxN], ln, rn;
int n, m, t;
double ans = 1e14;
double C(int p, int d, int q) { return s[p].x[d] - v[q].x / v[q].y * s[p].y; }
void FindV() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i].y > s[j].y) {
        a[m++] = {s[j].x[0] - s[i].x[1], s[j].x[1] - s[i].x[0],
                  s[j].y - s[i].y};
      }
    }
  }
  sort(a, a + m);
  v[0] = {-1, 0};
  for (int i = 0; i < m; i++) {
    if (M(v[t].x, v[t].y, a[i].x[0], a[i].y) > 0) {
      v[++t] = {a[i].x[0], a[i].y};
      v[++t] = {a[i].x[1], a[i].y};
    } else if (M(v[t].x, v[t].y, a[i].x[1], a[i].y) > 0) {
      v[t].x = a[i].x[1], v[t].y = a[i].y;
    }
  }
  if (!t) {
    v[++t] = {0, -1};
  }
}
void Con() {
  sort(s + 1, s + 1 + n,
       [](S i, S j) { return i.y > j.y || (i.y == j.y && i.x[0] < j.x[0]); });
  for (int i = 1; i <= n; i++) {
    for (; ln >= 2 && M(s[i].x[0] - s[l[ln - 1]].x[0], s[i].y - s[l[ln - 1]].y,
                        s[i].x[0] - s[l[ln]].x[0], s[i].y - s[l[ln]].y) <= 0;
         ln--) {
    }
    l[++ln] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (; rn >= 2 && M(s[i].x[1] - s[r[rn - 1]].x[1], s[i].y - s[r[rn - 1]].y,
                        s[i].x[1] - s[r[rn]].x[1], s[i].y - s[r[rn]].y) <= 0;
         rn--) {
    }
    r[++rn] = i;
  }
}
void Calc() {
  for (int i = 1, pl = 1, pr = 1; i <= t; i++) {
    for (; pl < ln && C(l[pl], 0, i) >= C(l[pl + 1], 0, i); pl++) {
    }
    for (; pr < rn && C(r[pr], 1, i) <= C(r[pr + 1], 1, i); pr++) {
    }
    ans = min(ans, C(r[pr], 1, i) - C(l[pl], 0, i));
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].x[0] >> s[i].x[1] >> s[i].y;
  }
  Con();
  FindV();
  Calc();
  cout << fixed << setprecision(8) << ans;
  return 0;
}
