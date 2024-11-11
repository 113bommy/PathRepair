#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, a[N];
int main() {
  ios::sync_with_stdio(false);
  for (cin >> t; t; t--) {
    cin >> n;
    long long l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      l += a[i];
      r ^= a[i];
    }
    cout << 2 << '\n' << r << ' ' << (l + r) << '\n';
  }
  return 0;
}
