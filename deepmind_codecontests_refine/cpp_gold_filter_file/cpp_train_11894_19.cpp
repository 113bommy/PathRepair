#include <bits/stdc++.h>
using namespace std;
long long t, d, n, a[8005], b[8005], c[8005], ans, re, left, right, aa, bb,
    k[8005];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 3) {
      cout << -1 << '\n';
    } else {
      ans = n / 4 - 1;
      for (int i = 0; i < ans; i++) {
        cout << 4 * i + 2 << " " << 4 * i + 4 << " " << 4 * i + 1 << " "
             << 4 * i + 3 << " ";
      }
      if (n % 4 == 0) {
        cout << 4 * ans + 2 << " " << 4 * ans + 4 << " " << 4 * ans + 1 << " "
             << 4 * ans + 3 << '\n';
      }
      if (n % 4 == 1) {
        cout << 4 * ans + 2 << " " << 4 * ans + 4 << " " << 4 * ans + 1 << " "
             << 4 * ans + 3 << " " << 4 * ans + 5 << '\n';
      }
      if (n % 4 == 2) {
        cout << 4 * ans + 2 << " " << 4 * ans + 6 << " " << 4 * ans + 3 << " "
             << 4 * ans + 5 << " " << 4 * ans + 1 << " " << 4 * ans + 4 << '\n';
      }
      if (n % 4 == 3) {
        cout << 4 * ans + 2 << " " << 4 * ans + 6 << " " << 4 * ans + 3 << " "
             << 4 * ans + 5 << " " << 4 * ans + 1 << " " << 4 * ans + 4 << " "
             << 4 * ans + 7 << '\n';
      }
    }
  }
}
