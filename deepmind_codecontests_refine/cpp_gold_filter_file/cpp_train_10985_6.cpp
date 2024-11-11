#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<double> mins(n), maxs(n), a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> maxs[i];
  for (int i = 0; i < n; ++i) cin >> mins[i];
  double sumin = 1, sumax = 0, sumf = 0, sums = 0;
  for (int i = 0; i < n; ++i) {
    sumin -= mins[i];
    sumax += maxs[i];
    double t = abs((1 + sumax - sumin) * (1 + sumax - sumin) - 4 * sumax);
    double f = abs(((sumin - sumax - 1) + sqrt(t))) / 2;
    double s = f == 0 ? 1 : sumax / f;
    a[i] = f - sumf;
    b[i] = s - sums;
    sumf += f - sumf;
    sums += s - sums;
  }
  for (auto i : a) cout << setprecision(10) << fixed << i << ' ';
  cout << '\n';
  for (auto i : b) cout << setprecision(10) << fixed << i << ' ';
  return 0;
}
