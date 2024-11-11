#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  k = min(k, n / 2);
  long long x = 2 * n - 3;
  for (long long i = 0; i < k; i++) {
    ans += x;
    x -= 4;
  }
  return cout << ans, 0;
}
