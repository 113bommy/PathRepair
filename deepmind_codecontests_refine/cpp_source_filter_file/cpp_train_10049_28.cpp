#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long tmp = n * (n - 1) / 2;
  long long res = 0;
  for (long long i = 1; i <= k && n > 1; i++) {
    res += 2 * (n - 2);
    n -= 2;
  }
  res = min(res, tmp);
  cout << res << endl;
}
