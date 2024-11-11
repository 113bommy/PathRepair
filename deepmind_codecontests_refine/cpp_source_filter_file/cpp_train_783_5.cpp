#include <bits/stdc++.h>
using namespace std;
double ans, vr, vb, poi[10086][2], m, tb[10086], tr[10086], ten, tfi, tenw,
    tfiw, dzou, b[10086], K, minn, tt;
int n, mini;
double min(double a, double b) {
  if (a < b) return a;
  return b;
}
double max(double a, double b) {
  if (a > b) return a;
  return b;
}
int main() {
  int i, j, k, tp;
  double a, x, y;
  scanf("%d%lf%lf%lf", &n, &m, &vb, &vr);
  tp = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &poi[i][0], &poi[i][1]);
    tb[i] = poi[i][0] / vb;
    tr[i] = poi[i][1] / vr;
    if (tr[i] > tb[i]) tp = 1;
  }
  if (tp == 0) {
    ans = m / vr;
    printf("%.7lf\n", ans);
    return 0;
  }
  K = vr / vb;
  for (i = 1; i <= n; i++) {
    b[i] = poi[i][1] - K * poi[i][0];
  }
  minn = 10080000000000;
  mini = -1;
  for (i = 0; i <= n; i++) {
    if (b[i] < minn && poi[i][0] > 0) {
      minn = b[i];
      mini = i;
    }
  }
  if (mini == -1) {
    printf("%.7lf", m / vr);
  } else {
    tt = poi[mini][0] / vb;
    tt = tt + (m - poi[mini][1]) / vr;
    tt = min(tt, m / vr);
    printf("%.7lf", tt);
  }
  return 0;
}
