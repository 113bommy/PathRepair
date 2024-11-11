#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int i, j, k, n;
  cin >> n;
  int d = -1;
  for (d = 2; d * d <= n; ++d)
    if (n % d == 0) break;
  if (d == -1) return cout << "NO\n", 0;
  int m = n;
  while (m % d == 0) m /= d;
  if (m == 1) return cout << "NO\n", 0;
  d = n / m;
  int x = 1, y;
  while (1) {
    if ((n - 1 - d * x) % (n / d) == 0) {
      y = (n - 1 - d * x) / (n / d);
      break;
    }
    x++;
  }
  cout << "YES\n"
       << "2\n";
  cout << x << " " << n / d << "\n";
  cout << y << " " << d << "\n";
  return 0;
}
