#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long y, lasty = n + 1, ans = n;
  for (y = lasty; y >= 0; y--) {
    if (1 * 1 + y * y <= n * n) {
      break;
    }
  }
  lasty = y;
  for (long long x = 2; x < n; x++) {
    for (y = lasty; y >= 0; y--) {
      if (x * x + y * y <= n * n) {
        break;
      }
    }
    if (y == lasty) ans++;
    lasty = y;
  }
  if (n == 0)
    cout << 1 << endl;
  else
    cout << 4 * ans << endl;
  return 0;
}
