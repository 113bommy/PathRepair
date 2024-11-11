#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, smx = 0, smi = 0, x, y;
  cin >> n >> m;
  double ans = 0;
  smx = (n - 1) * (n) / 2;
  x = n / 2;
  smi = (x) * (x + 1);
  if (n % 2 == 0) {
    smi -= n / 2;
  }
  while (m--) {
    cin >> x >> y;
    ans += n * x;
    if (y >= 0) {
      ans += smx * y;
    } else
      ans += smi * y;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(12) << ans / n << '\n';
}
