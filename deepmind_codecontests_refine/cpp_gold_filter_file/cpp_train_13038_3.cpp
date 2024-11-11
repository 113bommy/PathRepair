#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    if (m == 1 && n == 1) {
      cout << 1 << '\n';
      continue;
    }
    if (max(m, n) % 2 == 0) {
      long long int x = max(m, n) / 2;
      cout << x * min(m, n) << '\n';
      continue;
    }
    long long int x = max(m, n) / 2;
    x = x * min(m, n);
    x = x + (min(m, n) / 2 + min(m, n) % 2);
    cout << x << '\n';
  }
  return 0;
}
