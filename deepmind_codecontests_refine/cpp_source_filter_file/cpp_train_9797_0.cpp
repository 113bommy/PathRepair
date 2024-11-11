#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n, k;
  cin >> n >> k;
  int m = k * 2 + 1;
  if (n == k) {
    cout << "1\n1\n";
  } else if (n % m == 0) {
    cout << n / m << '\n';
    for (int i = k; i < n; i += m) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  } else {
    cout << n / m + 1 << '\n';
    if (n % m > k) {
      for (int i = k; i < n - n % m; i += m) {
        cout << i + 1 << ' ';
      }
      cout << (n - n % m + k) + 1 << '\n';
    } else {
      int t = 2 * k + 1 + n % m;
      cout << 1 << ' ';
      t -= k + 1;
      for (int i = k + k + 1; i < n - t; i += m) {
        cout << i + 1 << ' ';
      }
      cout << (n - t + k) + 1 << '\n';
    }
  }
  return 0;
}
