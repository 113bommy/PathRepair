#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int need = n * m - k;
  long long ans = 10e10;
  for (int x = 0; x * n <= 2000; x++) {
    for (int y = 0; y <= 2000; y++) {
      if (x * n + y >= need) {
        if (ans > x * c + y * d) {
          ans = x * c + y * d;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
