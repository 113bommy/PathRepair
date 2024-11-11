#include <bits/stdc++.h>
using namespace std;
int T;
long long x[5], y[5], ans, nx[5], ny[5], ax[5], ay[5];
bool used[5];
int p[5];
void getans() {
  long long mx = 0;
  for (int i = 1; i <= 4; ++i) {
    if (x[i] != nx[i] && y[i] != ny[i]) return;
    if (x[i] == nx[i]) mx = max(mx, abs(y[i] - ny[i]));
    if (y[i] == ny[i]) mx = max(mx, abs(x[i] - nx[i]));
  }
  if (mx < ans) {
    ans = mx;
    for (int i = 1; i <= 4; ++i) ax[i] = nx[i], ay[i] = ny[i];
  }
}
void check11() {
  if (x[p[4]] >= nx[p[2]]) return;
  nx[p[4]] = x[p[4]], ny[p[4]] = ny[p[2]] + nx[p[2]] - nx[p[4]];
  nx[p[3]] = nx[p[2]], ny[p[3]] = ny[p[4]];
  nx[p[1]] = nx[p[4]], ny[p[1]] = ny[p[2]];
  getans();
}
void check12() {
  if (y[p[4]] <= ny[p[2]]) return;
  ny[p[4]] = y[p[4]], nx[p[4]] = nx[p[2]] - ny[p[4]] + ny[p[2]];
  nx[p[3]] = nx[p[2]], ny[p[3]] = ny[p[4]];
  nx[p[1]] = nx[p[4]], ny[p[1]] = ny[p[2]];
  getans();
}
void check1() {
  nx[p[2]] = x[p[2]], ny[p[2]] = y[p[1]];
  check11();
  check12();
}
void check21() {
  if (x[p[3]] <= nx[p[1]]) return;
  nx[p[3]] = x[p[3]], ny[p[3]] = ny[p[1]] + nx[p[3]] - nx[p[1]];
  nx[p[2]] = nx[p[3]], ny[p[2]] = ny[p[1]];
  nx[p[4]] = nx[p[1]], ny[p[4]] = ny[p[3]];
  getans();
}
void check22() {
  if (y[p[3]] <= ny[p[1]]) return;
  ny[p[3]] = y[p[3]], nx[p[3]] = nx[p[1]] + ny[p[3]] - ny[p[1]];
  nx[p[2]] = nx[p[3]], ny[p[2]] = ny[p[1]];
  nx[p[4]] = nx[p[1]], ny[p[4]] = ny[p[3]];
  getans();
}
void check2() {
  nx[p[1]] = x[p[1]], ny[p[1]] = y[p[2]];
  check21();
  check22();
}
void check3() {
  if (x[p[1]] >= x[p[2]]) return;
  if (x[p[4]] != x[p[1]]) {
    nx[p[4]] = x[p[1]], ny[p[4]] = y[p[4]];
    nx[p[3]] = x[p[2]], ny[p[3]] = y[p[4]];
    nx[p[1]] = x[p[1]], ny[p[1]] = ny[p[4]] - (x[p[2]] - x[p[1]]);
    nx[p[2]] = x[p[2]], ny[p[2]] = ny[p[1]];
    getans();
  } else if (x[p[3]] != x[p[2]]) {
    nx[p[3]] = x[p[2]], ny[p[3]] = y[p[3]];
    nx[p[4]] = x[p[1]], ny[p[4]] = y[p[3]];
    nx[p[1]] = x[p[1]], ny[p[1]] = ny[p[4]] - (x[p[2]] - x[p[1]]);
    nx[p[2]] = x[p[2]], ny[p[2]] = ny[p[1]];
    getans();
  } else {
    if (ny[p[1]] >= ny[p[4]] || ny[p[2]] >= ny[p[4]]) return;
    nx[p[1]] = x[p[1]], nx[p[2]] = x[p[2]], nx[p[3]] = x[p[3]],
    nx[p[4]] = x[p[4]];
    long long l = x[p[2]] - x[p[1]],
              mi = min(min(y[p[1]], y[p[2]]), min(y[p[3]] - l, y[p[4]] - l)),
              mx = max(max(y[p[1]], y[p[2]]), max(y[p[3]] - l, y[p[4]] - l));
    long long pos = mi + mx >> 1;
    ny[p[1]] = ny[p[2]] = pos;
    ny[p[3]] = ny[p[4]] = pos + l;
    getans();
  }
}
void check4() {
  if (x[p[1]] >= x[p[2]] || y[p[1]] != y[p[2]]) return;
  long long l;
  nx[p[4]] = x[p[4]], ny[p[4]] = y[p[3]];
  nx[p[2]] = nx[p[4]], ny[p[2]] = y[p[2]];
  l = ny[p[4]] - ny[p[2]];
  if (l > 0) {
    nx[p[1]] = nx[p[2]] - l, ny[p[1]] = y[p[1]];
    nx[p[3]] = nx[p[1]], ny[p[3]] = ny[p[4]];
    getans();
  }
  nx[p[3]] = x[p[3]], ny[p[3]] = y[p[4]];
  nx[p[1]] = nx[p[3]], ny[p[1]] = y[p[1]];
  l = ny[p[3]] - ny[p[1]];
  if (l > 0) {
    nx[p[2]] = nx[p[1]] + l, ny[p[2]] = y[p[2]];
    nx[p[4]] = nx[p[2]], ny[p[4]] = ny[p[3]];
    getans();
  }
  l = x[p[4]] - x[p[3]];
  if (l > 0) {
    nx[p[1]] = nx[p[3]] = x[p[3]];
    nx[p[2]] = nx[p[4]] = x[p[4]];
    ny[p[1]] = ny[p[2]] = y[p[1]];
    ny[p[3]] = ny[p[4]] = y[p[1]] + l;
    getans();
  }
  if (y[p[3]] == y[p[4]] && y[p[3]] > y[p[1]]) {
    long long l = y[p[3]] - y[p[1]],
              mi = min(min(x[p[1]], x[p[2]] - l), min(x[p[3]] - l, x[p[4]])),
              mx = max(max(x[p[1]], x[p[2]] - l), max(x[p[3]] - l, x[p[4]]));
    long long pos = mi + mx >> 1;
    ny[p[1]] = ny[p[2]] = y[p[1]];
    ny[p[3]] = ny[p[4]] = y[p[3]];
    nx[p[1]] = nx[p[4]] = pos;
    nx[p[2]] = nx[p[3]] = pos + l;
    getans();
  }
}
void check() {
  check1();
  check2();
  check3();
  check4();
}
void dfs(int w) {
  if (w == 5) return check();
  for (int i = 1; i <= 4; ++i)
    if (!used[i]) used[i] = 1, p[w] = i, dfs(w + 1), used[i] = 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i = 1; i <= 4; ++i) scanf("%lld %lld", &x[i], &y[i]);
    ans = 0x3f3f3f3f3f3f3f3f;
    dfs(1);
    if (ans == 0x3f3f3f3f3f3f3f3f)
      printf("-1\n");
    else {
      printf("%lld\n", ans);
      for (int i = 1; i <= 4; ++i) printf("%lld %lld\n", ax[i], ay[i]);
    }
  }
  return 0;
}
