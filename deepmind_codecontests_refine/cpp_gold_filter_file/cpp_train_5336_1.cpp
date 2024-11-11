#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << ' ' << n / 2 << endl;
    } else {
      int lim = sqrt(n + 0.5), fg = 0;
      for (int i = 3; i <= lim; ++i) {
        if (n % i == 0) {
          cout << (n / i) << ' ' << (n / i) * (i - 1) << endl;
          fg = 1;
          break;
        }
      }
      if (!fg) {
        cout << 1 << ' ' << n - 1 << endl;
      }
    }
  }
}
