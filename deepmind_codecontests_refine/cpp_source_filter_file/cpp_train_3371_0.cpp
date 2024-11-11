#include <bits/stdc++.h>
using namespace std;
int n;
struct pp {
  double f_value, res;
  int num;
  bool path[6002];
};
pp dp[6002], ans;
double q, a, b, x[6600], y[6600], hh[6600];
void dfs(int id) {
  int i, j, s, p;
  double aa, bb, cc, xx, now;
  pp fir, sec;
  if (id == n) {
    dp[id].res = 0;
    dp[id].f_value = q;
    return;
  }
  if (dp[id].res >= 0) return;
  aa = 1;
  bb = -2 * x[id];
  cc = x[id] * x[id];
  now = 0;
  for (i = id; i < n; i++) {
    if (-bb / (2.0 * aa) < 1.0)
      xx = 1.00;
    else if (-bb / (2 * aa) > q - (n - 1 - i) * a - now)
      xx = q - (n - 1 - i) * a - now;
    else
      xx = -bb / (2 * aa);
    dfs(i + 1);
    sec.res = dp[i + 1].res;
    if (i == n - 1 ||
        (xx + now + a <= sec.f_value && xx + now + b >= sec.f_value)) {
      dp[id].f_value = xx;
      dp[id].res = aa * xx * xx + bb * xx + cc + sec.res;
      return;
    }
    if (sec.f_value < xx + now + a) {
      now += a;
      dp[id].path[dp[id].num++] = false;
    } else if (sec.f_value > xx + now + b) {
      now += b;
      dp[id].path[dp[id].num++] = true;
    }
    aa += 1;
    bb += 2 * (now - x[i + 1]);
    cc += (now - x[i + 1]) * (now - x[i + 1]);
  }
}
int main() {
  int i, j, s, p, id;
  double now, result;
  scanf("%d%lf%lf%lf", &n, &q, &a, &b);
  for (i = 0; i < n; i++) scanf("%lf", &x[i]);
  for (i = 0; i < n; i++) {
    dp[i].res = -1.00;
    dp[i].num = 0;
  }
  dfs(0);
  result = dp[0].res;
  id = 0;
  int cnt = 0;
  while (id < n) {
    ans = dp[id];
    now = ans.f_value;
    if (id != 0) putchar(' ');
    hh[cnt++] = now;
    printf("%.20f", now);
    id++;
    for (i = 0; i < ans.num; i++) {
      if (ans.path[i])
        now += b;
      else
        now += a;
      printf(" %.20f", now);
      hh[cnt++] = now;
      id++;
    }
  }
  result = 0;
  for (i = 0; i < n; i++) result += (hh[i] - x[i]) * (hh[i] - x[i]);
  printf("\n%.20f\n", result);
  return 0;
}
