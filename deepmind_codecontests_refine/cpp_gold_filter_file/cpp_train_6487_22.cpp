#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long ans = 0;
  if (k == 1 || k > n) {
    ans = 1;
    int i;
    for (i = 0; i < n; i++) {
      ans *= m;
      ans %= 1000000007;
    }
  } else if (k == n) {
    ans = 1;
    int i;
    for (i = 1; i <= n / 2; i++) {
      ans *= m;
      ans %= 1000000007;
    }
    if (n % 2) {
      ans = ans * m;
      ans %= 1000000007;
    }
  } else {
    if (k % 2 == 0) {
      ans = m;
    } else {
      if (n == 1) {
        ans = m;
      } else {
        ans = m * m;
      }
    }
  }
  ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
