#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int MAXN = 505;
int n;
double p[MAXN];
double d[MAXN];
double ans, all = 1.0;
double calc(int pos) { return all / (1.0 - d[pos]) * d[pos] * p[pos]; }
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
    p[i] /= 100.0;
  }
  for (int i = 1; i <= n; i++) {
    d[i] = 1.0 - p[i];
    all *= p[i];
  }
  ans = all * n;
  for (int i = n + 1; i <= 20000; i++) {
    int mn = 1;
    for (int j = 2; j <= n; j++) {
      if (calc(j) > calc(mn)) {
        mn = j;
      }
    }
    double cur = calc(mn);
    ans += cur * i;
    d[mn] *= (1.0 - p[mn]);
    all += cur;
  }
  printf("%.9lf\n", ans);
}
void precalc() {}
int main() {
  srand(1363);
  precalc();
  int tests = 1;
  for (int i = 1; i <= tests; i++) {
    solve();
  }
  return 0;
}
