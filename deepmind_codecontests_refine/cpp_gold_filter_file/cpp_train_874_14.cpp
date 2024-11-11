#include <bits/stdc++.h>
using namespace std;
bitset<1005> a[1005], cho;
long double vx[1005], vy[1005], px[1005], py[1005];
int n;
int ans;
int p[1005];
void calc() {
  int nowcnt = 0;
  cho.reset();
  for (int i = 1; i <= n; i++) {
    int now = p[i];
    if ((cho & a[now]) != cho) continue;
    nowcnt++;
    cho[now] = 1;
  }
  ans = max(ans, nowcnt);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long t1, x1, y1, t2, x2, y2;
    scanf("%lld%lld%lld%lld%lld%lld", &t1, &x1, &y1, &t2, &x2, &y2);
    vx[i] = 1.0 * (x2 - x1) / (t2 - t1);
    vy[i] = 1.0 * (y2 - y1) / (t2 - t1);
    px[i] = x1 - vx[i] * t1;
    py[i] = y1 - vy[i] * t1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      if (i == j) {
        a[i][j] = 1;
        continue;
      }
      long double Ax = vx[i] - vx[j], Bx = px[j] - px[i], timx;
      if (fabs(Ax) < 1e-6 && fabs(Bx) > 1e-6) continue;
      if (fabs(Ax) > 1e-6)
        timx = Bx / Ax;
      else
        timx = 1e18;
      long double Ay = vy[i] - vy[j], By = py[j] - py[i], timy;
      if (fabs(Ay) < 1e-6 && fabs(By) > 1e-6) continue;
      if (fabs(Ay) > 1e-6)
        timy = By / Ay;
      else
        timy = 1e18;
      if (fabs(timx - timy) < 1e-6) {
        a[i][j] = a[j][i] = 1;
        continue;
      }
      if (fabs(timx - 1e18) < 1e-6 || fabs(timy - 1e18) < 1e-6) {
        a[i][j] = a[j][i] = 1;
        continue;
      }
    }
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= 20000; i++) {
    random_shuffle(p + 1, p + n + 1);
    calc();
  }
  cout << ans;
  return 0;
}
