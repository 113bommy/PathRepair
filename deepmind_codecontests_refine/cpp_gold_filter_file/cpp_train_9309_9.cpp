#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    if (l > n) {
      cout << "No" << endl;
      continue;
    }
    if (l <= n && r >= n) {
      cout << "Yes" << endl;
      continue;
    }
    if (l == r) {
      cout << ((n % l == 0) ? "Yes" : "No ") << endl;
      continue;
    }
    long long x = (long long)(ceil(n / (r * 1.0)));
    if (n - x * r <= 0 and n - x * l >= 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
