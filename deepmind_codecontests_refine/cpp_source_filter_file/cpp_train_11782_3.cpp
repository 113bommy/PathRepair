#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k - n * b <= 0) {
      cout << -1 << "\n";
      continue;
    }
    int l = -1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (k - m * b - (n - m) * a > 0) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << n - r << "\n";
  }
}
