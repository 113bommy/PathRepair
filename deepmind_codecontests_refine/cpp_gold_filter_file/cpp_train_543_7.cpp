#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const int v1 = 1e5 + 5;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unsigned long long t = 0;
  cin >> t;
  while (t--) {
    unsigned long long n = 0;
    cin >> n;
    if (n == 1)
      cout << 0 << "\n";
    else {
      n = (n - 1) / 2;
      cout << 8 * (n * (n + 1) * (2 * n + 1)) / 6 << "\n";
    }
  }
}
