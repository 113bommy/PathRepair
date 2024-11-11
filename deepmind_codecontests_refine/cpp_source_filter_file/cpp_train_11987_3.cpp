#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n >> k;
  if (k * (k - 1) < n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= k; ++i) {
    for (int j = i + 1; j <= k; ++j) {
      if (n < 1) return 0;
      cout << i << ' ' << j << '\n';
      --n;
      if (n > 1) {
        cout << j << ' ' << i << '\n';
        --n;
      }
    }
  }
  return 0;
}
