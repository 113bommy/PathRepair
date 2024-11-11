#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x, d;
  long double sum = 0;
  scanf("%lld%lld", &n, &m);
  vector<long long int> a(n, 0);
  while (m--) {
    scanf("%lld%lld", &x, &d);
    sum += n * x;
    if (d > 0) {
      sum += d * (n - 1) * n / 2;
    } else {
      if (n % 2) {
        sum += d * (n / 2) * (n / 2 + 1);
      } else {
        sum += n * n * d / 4;
      }
    }
  }
  cout << fixed << setprecision(10) << sum / n << "\n";
  return 0;
}
