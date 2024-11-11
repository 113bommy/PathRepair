#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, m, d, w;
  cin >> t;
  for (long int i2 = 0; i2 < t; i2++) {
    cin >> m >> d >> w;
    long long a = d - 1, b = w;
    while (a > 0 and b > 0) {
      if (a > b)
        a %= b;
      else
        b %= a;
    }
    long long n = w / (a + b), l = min(d, m);
    long long res = 0, k = l / n, r = l % n;
    cout << r * k + (n * (k - 1) * k) / 2 << "\n";
  }
  return 0;
}
