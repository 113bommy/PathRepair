#include <bits/stdc++.h>
using namespace std;
double f[301], k[100001], s, ans;
int n;
int main() {
  scanf("%d%lf", &n, &s);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(200, n); j++) {
      f[j] =
          ((f[j + 1] + double(j)) / double(j + 1.0) +
           (double(j) * (f[j] + (double(j) + 1.0) / 2.0)) / double(j + 1.0)) /
              s +
          ((s - 1.0) * f[j]) / s;
    }
  }
  ans = f[1] * s;
  printf("%.9lf\n", ans);
}
