#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n == 2 * m)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
