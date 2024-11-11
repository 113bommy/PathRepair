#include <bits/stdc++.h>
using namespace std;
double p[210];
int a[210];
double d[210][210][410];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] /= 100;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
    sum += a[i];
  }
  d[1][1][a[1]] = p[1];
  d[1][0][0] = 1 - p[1];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int s = 0; s <= 200; s++) {
        d[i + 1][j][s] += d[i][j][s] * (1 - p[i + 1]);
        int ss = s + a[i + 1];
        if (ss > 200) ss = 200;
        d[i + 1][j + 1][ss] += d[i][j][s] * p[i + 1];
      }
    }
  }
  double ans = 0;
  for (int j = 0; j <= n; j++) {
    for (int s = 0; s <= 200; s++) {
      if (j >= l && j <= k + s) ans += d[n][j][s];
    }
  }
  printf("%.8lf\n", ans);
  return 0;
}
