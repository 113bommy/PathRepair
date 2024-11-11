#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    ll ans = 0;
    int a[5] = {}, b[5] = {};
    for (int i = 1; i <= n; ++i) {
      ++a[i % 5];
    }
    for (int i = 1; i <= m; ++i) {
      ++b[i % 5];
    }
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 5; j++) {
        if ((i + j) % 5 == 0) {
          ans += a[i] * b[j];
        }
      }
    }
    cout << ans << endl;
  }
}
