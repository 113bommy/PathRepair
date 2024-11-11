#include <bits/stdc++.h>
using namespace std;
int dcmp(double x) {
  if (fabs(x) < 1e-9) return 0;
  return x > 1e-9 ? 1 : -1;
}
long long N, P, TP;
long long ff, rr;
long long tx[1000005], ty[1000005];
long long x[1000005], y[1000005], rk[1000005];
double pd[1000005], pu[1000005], sd[1000005], su[1000005];
bool cmp(int a, int b) { return x[a] < x[b]; }
struct event {
  double x;
  int type, num;
  bool operator<(event b) const {
    return x < b.x || dcmp(x - b.x) == 0 && type < b.type;
  }
} s[1000005];
int main() {
  long long i, j, flag, xx, yy;
  double mx, mn;
  scanf("%I64d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%I64d %I64d", &x[i], &y[i]);
    xx = x[i] - y[i], yy = x[i] + y[i];
    x[i] = tx[i] = xx, y[i] = ty[i] = yy, rk[i] = i;
  }
  sort(rk + 1, rk + 1 + N, cmp);
  for (i = 1; i <= N; i++) x[i] = tx[rk[i]], y[i] = ty[rk[i]];
  double mid, l1 = 0, r1 = 4 * 1000000000.0, dis;
  for (long long tt = 1; tt <= 55; tt++) {
    mid = (l1 + r1) / 2, P = 0;
    pu[0] = su[N + 1] = -1e15, pd[0] = sd[N + 1] = 1e15;
    for (i = 1; i <= N; i++)
      pu[i] = max(pu[i - 1], (double)y[i]),
      pd[i] = min(pd[i - 1], (double)y[i]);
    for (i = N; i >= 1; i--)
      su[i] = max(su[i + 1], (double)y[i]),
      sd[i] = min(sd[i + 1], (double)y[i]);
    ff = 1, rr = 0;
    for (i = 1; i <= N; i++) {
      rr = i;
      while (dcmp(x[ff] - (x[i] - mid * 2)) <= 0) ff++;
      mx = max(pu[ff - 1], su[rr + 1]);
      mn = min(pd[ff - 1], sd[rr + 1]);
      if (dcmp(mx - mn - mid * 2) <= 0) break;
    }
    if (i <= N)
      r1 = mid;
    else
      l1 = mid;
  }
  printf("%.9lf\n", mid);
  return 0;
}
