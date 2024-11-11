#include <bits/stdc++.h>
#pragma GCC opmize(2)
#pragma GCC opmize(3)
using namespace std;
const int N = 1e5 + 7;
long long M = 1e9 + 7;
long long n, m, k;
int main() {
  ios::sync_with_stdio(0);
  long long ans = 1;
  cin >> n >> m >> k;
  if (k < n && k % 2 == 0) {
    cout << m << endl;
    return 0;
  }
  if (k == 1 || k > n) {
    for (int i = 1; i <= n; i++) ans = ans * m % M;
  } else if (n == k) {
    for (int i = 1; i <= k / 2; i++) ans = ans * m % M;
    if (k % 2) ans *= m;
  } else {
    if (!n % 2)
      ans = m;
    else
      ans = m * m;
  }
  ans %= M;
  cout << ans << endl;
  return 0;
}
