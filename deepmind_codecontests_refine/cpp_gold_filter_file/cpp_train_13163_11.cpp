#include <bits/stdc++.h>
using namespace std;
long double x[1000000], y[1000000], z[1000000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
  long double mini = 2000000000;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long double hi1 = ((x[i] - x[0]) * (x[i] - x[0])) +
                        ((y[i] - y[0]) * (y[i] - y[0])) +
                        ((z[i] - z[0]) * (z[i] - z[0]));
      long double hi2 = ((x[j] - x[0]) * (x[j] - x[0])) +
                        ((y[j] - y[0]) * (y[j] - y[0])) +
                        ((z[j] - z[0]) * (z[j] - z[0]));
      hi1 = sqrt(hi1);
      hi2 = sqrt(hi2);
      hi1 += hi2;
      long double u = ((x[i] - x[j]) * (x[i] - x[j])) +
                      ((y[i] - y[j]) * (y[i] - y[j])) +
                      ((z[i] - z[j]) * (z[i] - z[j]));
      u = sqrt(u);
      hi1 += u;
      hi1 /= 2;
      mini = min(mini, hi1);
    }
  }
  cout << fixed << setprecision(20) << mini;
  return 0;
}
