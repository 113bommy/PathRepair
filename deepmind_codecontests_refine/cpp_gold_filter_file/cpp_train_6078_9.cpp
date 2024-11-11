#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
const long long mod = 1e9 + 7;
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 1;
  for (int i = 2; i <= n; i++) {
    if (i <= k)
      ans = ans * k % mod;
    else
      ans = ans * (n - k) % mod;
  }
  cout << ans << endl;
  return 0;
}
