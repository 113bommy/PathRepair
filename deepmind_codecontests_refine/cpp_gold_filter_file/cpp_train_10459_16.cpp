#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  while (cin >> a >> b) {
    if (b > a) {
      cout << 0 << '\n';
      continue;
    }
    if (b == a) {
      cout << "infinity" << '\n';
      continue;
    }
    int ans = 0;
    int n = a - b;
    for (int i = 1; i <= int(sqrt(double(n))); i++) {
      if (n % i == 0) {
        if (i > b) {
          ans++;
        }
        if (n / i > b && n / i != i) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
