#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2500;
const long double PI = acos(-1.0L);
long double x[MAX_N + 1], y[MAX_N + 1], angle[MAX_N + 1];
long long ans;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%Lf%Lf", &x[i], &y[i]);
  ans = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
  int now;
  long double tmp, cnt;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (i != j)
        angle[j] = atan2(x[j] - x[i], y[j] - y[i]);
      else
        angle[j] = -10;
    sort(angle, angle + n);
    now = 1;
    for (int j = 1; j < n; j++) {
      while (now < j + n - 2) {
        tmp = angle[now % (n - 1) + 1] - angle[j];
        if (tmp < 0) tmp += 2 * PI;
        if (tmp < PI)
          now++;
        else
          break;
      }
      cnt = now - j;
      ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
