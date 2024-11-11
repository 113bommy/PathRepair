#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
const double pi = 4 * atan(1);
double x[1100], y[1100], vx[1100], vy[1100];
int con[1100][1100];
double meet[1100][1100];
double t[1100];
pair<double, double> dv[1100];
int main() {
  int N, i, j, k, ans, cnt, n, m;
  double t1, t2, dx, dy, al, len;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%lf%lf%lf", &t1, &x[i], &y[i]);
    scanf("%lf%lf%lf", &t2, &vx[i], &vy[i]);
    vx[i] = (vx[i] - x[i]) / (t2 - t1);
    vy[i] = (vy[i] - y[i]) / (t2 - t1);
    x[i] -= t1 * vx[i];
    y[i] -= t1 * vy[i];
  }
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) {
      t1 = 0;
      if (fabs(vx[i] - vx[j]) > 1e-6) t1 = (x[i] - x[j]) / (vx[j] - vx[i]);
      if (fabs(vy[i] - vy[j]) > 1e-6) t1 = (y[i] - y[j]) / (vy[j] - vy[i]);
      if (fabs(x[i] + t1 * vx[i] - (x[j] + t1 * vx[j])) < 1e-6 &&
          fabs(y[i] + t1 * vy[i] - (y[j] + t1 * vy[j])) < 1e-6) {
        con[i][j] = con[j][i] = 1;
        meet[i][j] = meet[j][i] = t1;
      }
    }
  ans = 1;
  for (i = 0; i < N; i++) {
    n = 0;
    for (j = 0; j < i; j++)
      if (con[i][j]) t[n++] = meet[i][j];
    sort(t, t + n);
    for (j = 0; j < n; j = k) {
      for (k = j; k < n && fabs(t[k] - t[j]) < 1e-6; k++)
        ;
      chkmax(ans, k - j + 1);
    }
    for (j = n = 0; j < i; j++)
      if (con[i][j]) {
        dx = vx[j] - vx[i];
        dy = vy[j] - vy[i];
        al = atan2(dy, dx);
        while (al < 4) al += pi;
        len = dx * cos(al) + dy * sin(al);
        dv[n++] = make_pair(al, len);
      }
    sort(dv, dv + n);
    for (j = 0; j < n; j += m) {
      for (k = j, m = 0; k < n && fabs(dv[k].first - dv[j].first) < 1e-6; k++)
        t[m++] = dv[k].second;
      sort(t, t + m);
      for (k = cnt = 0; k < m; k++)
        if (k == 0 || t[k] - t[k - 1] > 1e-6) cnt++;
      chkmax(ans, cnt + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
