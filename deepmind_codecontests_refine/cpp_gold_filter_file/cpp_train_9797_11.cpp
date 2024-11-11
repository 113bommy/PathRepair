#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int p = n / (2 * k + 1);
  int q = n % (2 * k + 1);
  if (p == 0) {
    cout << "1\n";
    cout << q / 2 + 1 << "\n";
  } else if (q == 0) {
    cout << p << "\n";
    for (int i = 1; i <= p; ++i) {
      cout << (k + 1) + (i - 1) * (2 * k + 1) << " ";
    }
    cout << "\n";
  } else if (q <= k) {
    cout << p + 1 << "\n";
    cout << "1 ";
    for (int i = 1; i <= p - 1; ++i) {
      cout << 1 + i * (2 * k + 1) << " ";
    }
    cout << n - (q - 1) << "\n";
  } else if (q <= 2 * k) {
    cout << p + 1 << "\n";
    for (int i = 1; i <= p; ++i) {
      cout << (k + 1) + (i - 1) * (2 * k + 1) << " ";
    }
    cout << n - (q - (k + 1)) << "\n";
  }
  return 0;
}
