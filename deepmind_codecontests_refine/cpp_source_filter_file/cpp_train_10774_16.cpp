#include <bits/stdc++.h>
using namespace std;
int i, n, a[200005];
double st = -1e5, dr = 1e5;
double ABS(double a) { return a > 0 ? a : -a; }
double Check1(double x) {
  double aux = 0, now = 0;
  for (int i = 1; i <= n; ++i) {
    now += a[i] - x;
    aux = max(aux, now);
    if (now < 0) now = 0;
  }
  return aux;
}
double Check2(double x) {
  double aux = 0, now = 0;
  for (int i = 1; i <= n; ++i) {
    now += x - a[i];
    aux = max(aux, now);
    if (now < 0) now = 0;
  }
  return aux;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  while (st <= dr) {
    double pivot = (st + dr) / 2.0;
    if (Check1(pivot) < Check2(pivot))
      dr = pivot - 1e-11;
    else
      st = pivot + 1e-11;
  }
  cout << setprecision(7) << fixed
       << max(Check1((st + dr) / 2.0), Check2((st + dr) / 2.0)) << '\n';
  return 0;
}
