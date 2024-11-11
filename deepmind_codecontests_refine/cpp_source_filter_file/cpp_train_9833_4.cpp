#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n, m;
  cin >> n >> m;
  cout.precision(11);
  if (n == 1) {
    cout << "1.0000000000\n";
    return 0;
  }
  if (m == 1) {
    cout << 1 / (n * n);
    return 0;
  }
  long double P = 1;
  long double Q = 0;
  for (int i = 0; i < n; ++i) {
    P *= (m * n - m - i) / (m * n - i);
  }
  for (int t = 1; t <= n; ++t) {
    P *= (m - t + 1) * (n - t + 1) / (t * (m * n - m - n + t));
    Q += P * t * t;
  }
  cout << Q / n << "\n";
  return 0;
}
