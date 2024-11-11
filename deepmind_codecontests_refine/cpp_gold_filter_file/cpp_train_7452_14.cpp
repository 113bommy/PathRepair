#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  string ans = "Marsel";
  if (n % 2 == 1) {
    int x;
    for (x = 2; x <= m / k; x++) {
      if (m % x == 0) {
        ans = "Timur";
        break;
      }
      if (x * x > m) break;
    }
    if (k == 1 && k < m) ans = "Timur";
  }
  cout << ans;
  return 0;
}
