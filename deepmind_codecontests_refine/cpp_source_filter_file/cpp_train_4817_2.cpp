#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, mx = 0, sum = 0;
    cin >> n;
    for (long long i = 0, x; i < n; ++i) {
      cin >> x, mx = x, sum += x;
    }
    if (mx > sum - mx)
      cout << "T\n";
    else if (sum & 1)
      cout << "T\n";
    else
      cout << "HL\n";
  }
}
