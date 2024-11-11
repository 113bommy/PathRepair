#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
const int qwq = 303030;
const int inf = 0x3f3f3f3f;
const double littl = 1e-10;
double T;
int n, m;
struct E {
  double zhi, t, lt, rt;
} a[N];
inline bool cmp1(E aa, E bb) { return aa.zhi < bb.zhi; }
inline bool cmp(E aa, E bb) {
  if (fabs(aa.zhi * bb.t - aa.t * bb.zhi) < littl) return aa.zhi > bb.zhi;
  return aa.zhi * bb.t > aa.t * bb.zhi;
}
inline int read() {
  int sum = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
bool check(double h) {
  double mx = 0.0, now = 0.0;
  for (int i = 1; i <= n; i++) {
    if (a[i].zhi != a[i - 1].zhi) {
      mx = max(mx, now);
      now = 0.0;
    }
    double sc = a[i].zhi * (1 - h * a[i].rt / T);
    if (mx > sc) return 0;
    now = max(now, a[i].zhi * (1 - h * a[i].lt / T));
  }
  return 1;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].zhi = read();
  for (int i = 1; i <= n; i++) a[i].t = read(), T += a[i].t;
  sort(a + 1, a + n + 1, cmp);
  int L = 1, R = 0, now = 0;
  for (int i = 2; i <= n + 1; i++) {
    if (a[i].zhi * a[i - 1].t != a[i].t * a[i - 1].zhi || i == n + 1) {
      R = i - 1;
      for (int j = L; j <= R; j++) a[j].lt = a[j].t + now;
      for (int j = L; j <= R; j++) now += a[j].t;
      for (int j = L; j <= R; j++) a[j].rt = now;
      L = R + 1;
    }
  }
  sort(a + 1, a + n + 1, cmp1);
  double l = 0, r = 1, mid, ans;
  while (fabs(r - l) > littl) {
    mid = (l + r) / 2.0;
    if (check(mid))
      ans = mid, l = mid + littl;
    else
      r = mid - littl;
  }
  printf("%.9lf", ans);
  return 0;
}
