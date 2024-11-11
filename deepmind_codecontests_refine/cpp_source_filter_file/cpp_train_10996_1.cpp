#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long a0, q;
long long an(long long n) { return (a0 + q * n); }
long long nine[12], ten[12];
int main() {
  long long n;
  int m, a, b, c;
  ten[1] = 10;
  for (int i = 2; i <= 10; i++) ten[i] = ten[i - 1] * 10;
  nine[1] = 9;
  for (int i = 2; i <= 10; i++) nine[i] = nine[i - 1] * 10 + 9;
  while (cin >> n) {
    if (n <= 9) {
      if (n >= 5)
        cout << 4 - (8 - n) << endl;
      else {
        int r = 0;
        for (int i = 1; i < n; i++) r += i;
        cout << r << endl;
      }
      return 0;
    }
    for (int i = 1; i < 10; i++) {
      if ((2 * n - 1) >= nine[i] && (2 * n - 1) < nine[i + 1]) {
        m = i;
        break;
      }
    }
    a0 = 4;
    q = 5;
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
      if (n >= (i * ten[m] + nine[m])) {
        ans += an((i * ten[m] + nine[m]) / 10);
      } else {
        if (2 * n - 1 >= (i * ten[m] + nine[m])) {
          ans += an((i * ten[m] + nine[m]) / 10) -
                 ((i * ten[m] + nine[m]) - n - 1);
        } else
          break;
      }
    }
    cout << ans << endl;
  }
}
