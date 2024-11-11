#include <bits/stdc++.h>
using namespace std;
int n, r, ans, p, q, a[111], b[111], c[111], d[111], now;
bool ok;
long long sum;
set<int> sign;
void fail() {
  cout << "NO";
  exit(0);
}
int main() {
  cin >> n;
  if (n < 4) fail();
  if (!(n & 1)) {
    cout << "YES\n";
    cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    for (int i = 6; i <= n; i += 2) {
      cout << i << " - " << i - 1 << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  } else {
    if (n > 9) {
      cout << "YES\n";
      cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n24 + 5 = 29\n29 + 6 = 35\n35 "
              "- 11 = 24\n";
      cout << "8 - 7 = 1\n24 * 1 = 1\n10 - 9 = 1\n24 * 1 = 24\n";
      for (int i = 13; i <= n; i += 2) {
        cout << i << " - " << i - 1 << " = 1\n";
        cout << "24 * 1 = 24\n";
      }
    } else {
      cout << "YES\n";
      cout << "4 * 5 = 20\n3 - 1 = 2\n2 * 2 = 4\n20 + 4 = 24\n";
      if (n >= 7) {
        cout << "7 - 6 = 1\n24 * 1 = 24\n";
      }
      if (n == 9) {
        cout << "9 - 8 = 1\n24 * 1 = 24\n";
      }
    }
  }
  return 0;
}
