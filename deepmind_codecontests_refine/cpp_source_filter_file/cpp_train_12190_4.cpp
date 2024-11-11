#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, d, e;
  double S = 0, V;
  cin >> n >> m;
  e = 2 * ((n - 1) / 2) * ((n - 1) / 2 + 1) / 2;
  if (n % 2 == 0) {
    e += n / 2;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> d;
    S += x * n;
    if (d > 0) {
      S += d * n * (n - 1) / 2;
    } else {
      S += d * e;
    }
  }
  V = S / n;
  cout << fixed << setprecision(10) << V;
  return 0;
}
