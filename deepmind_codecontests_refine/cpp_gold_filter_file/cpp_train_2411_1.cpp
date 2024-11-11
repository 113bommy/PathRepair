#include <bits/stdc++.h>
using namespace std;
int n;
double x[1005], y[1005];
struct P {
  double k, b;
} val[1000005];
bool cmp(P u, P v) {
  if (u.k == v.k) return u.b < v.b;
  return u.k < v.k;
}
int main() {
  scanf(" %d", &n);
  for (int i = 1; i <= n; i++) scanf(" %lf %lf", &x[i], &y[i]);
  int cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (x[i] == x[j]) {
        val[++cnt].b = x[i];
        val[cnt].k = 1e9;
      } else {
        val[++cnt].k = (y[j] - y[i]) / (x[j] - x[i]);
        val[cnt].b = y[i] - x[i] * val[cnt].k;
      }
    }
  }
  sort(val + 1, val + cnt + 1, cmp);
  double posk = val[1].k - 1, posb = val[1].b - 1;
  long long num = 0, sol = 1, sum = 0;
  for (int i = 1; i <= cnt; i++) {
    if (val[i].k == posk) {
      if (val[i].b == posb) {
      } else {
        posb = val[i].b;
        sol++;
        num++;
      }
      if (i == cnt) sum -= sol * (sol - 1) / 2;
    } else {
      sum -= sol * (sol - 1) / 2;
      sol = 1;
      posk = val[i].k;
      posb = val[i].b;
      num++;
    }
  }
  sum += num * (num - 1) / 2;
  printf("%lld\n", sum);
}
