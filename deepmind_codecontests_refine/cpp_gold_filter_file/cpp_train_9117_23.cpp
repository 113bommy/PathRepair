#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
double solve(double val) {
  double l = 10.0, r = 1000.0;
  while (r - l > 1e-2) {
    double m = (l + r) / 2;
    if (m / log(m) < val)
      l = m;
    else
      r = m;
  }
  return (l + r) / 2;
}
const int M = 250;
int n, x[N];
double sum[N], fac[N];
int main() {
  cin >> n;
  fac[0] = 1;
  for (int i = (1); i <= (N - 1); i++)
    sum[i] = sum[i - 1] + log(i), fac[i] = fac[i - 1] * i;
  for (int t = (1); t <= (n); t++) {
    int maxx = 0, sumx = 0;
    for (int i = (1); i <= (M); i++) {
      scanf("%d", &x[i]);
      maxx = max(maxx, x[i]);
      sumx += x[i];
    }
    double p1 = (double)sumx / M;
    double p2 = maxx / 2.0;
    int cnt = 0;
    for (int i = (1); i <= (M); i++)
      if (x[i] < maxx / 8) cnt++;
    if (cnt > 10) {
      printf("%.0f\n", p2);
    } else {
      printf("%.0f\n", p1);
    }
  }
  return 0;
}
