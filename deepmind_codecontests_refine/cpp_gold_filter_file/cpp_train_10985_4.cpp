#include <bits/stdc++.h>
using namespace std;
int n;
long double mx[110000];
long double mn[110000];
long double pa[110000];
long double pb[110000];
long double ppa[110000];
long double ppb[110000];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> mx[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> mn[i];
  }
  for (int i = 1; i <= n; ++i) {
    long double x = mx[i] + mn[i];
    long double y = mx[i];
    long double b = ppb[i - 1] - ppa[i - 1] - x;
    long double c = y - x * ppb[i - 1];
    long double d = b * b - 4.0 * c;
    long double kr;
    if (d > 0.0000000001)
      kr = sqrt(d);
    else
      kr = 0;
    pb[i] = (-b + kr) / 2.0;
    pa[i] = x - pb[i];
    ppa[i] = ppa[i - 1] + pa[i];
    ppb[i] = ppb[i - 1] + pb[i];
  }
  for (int i = 1; i < n; ++i) printf("%.10f ", (double)pa[i]);
  printf("%.10f\n", (double)pa[n]);
  for (int i = 1; i < n; ++i) printf("%.10f ", (double)pb[i]);
  printf("%.10f\n", (double)pb[n]);
}
