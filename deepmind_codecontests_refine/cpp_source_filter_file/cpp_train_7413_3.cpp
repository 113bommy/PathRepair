#include <bits/stdc++.h>
using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    cin >> n >> p >> k;
    int a[n + 5], ans[n + 5], leftMoney[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n);
    memset(leftMoney, 0, sizeof(leftMoney));
    memset(ans, 0, sizeof(ans));
    int res = 0;
    leftMoney[0] = p;
    for (int i = 1; i <= n; i++) {
      if (i - k >= 0) {
        if (leftMoney[i - k] >= a[i]) {
          leftMoney[i] = leftMoney[i - k] - a[i];
          ans[i] = ans[i - k] + k;
        }
      } else {
        if (leftMoney[i - 1] >= a[i]) {
          ans[i] = ans[i - 1] + 1;
          leftMoney[i] = leftMoney[i - 1] - a[i];
        }
      }
      res = max(res, ans[i]);
    }
    cout << res << endl;
  }
  return 0;
}
