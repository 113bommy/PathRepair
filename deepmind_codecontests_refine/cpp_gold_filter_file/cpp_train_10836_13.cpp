#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000001;
const long long mod = 998244353;
long long pow_2[maxn];
long long a[maxn];
int n;
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    pow_2[0] = 1;
    for (int i = 1; i <= n; i++) pow_2[i] = (pow_2[i - 1] * 2) % mod;
    long long ans = pow_2[n - 1] * a[1] % mod, pre = a[1];
    for (int i = 2; i <= n; i++) {
      ans += (pow_2[n - i] * a[i] % mod + pow_2[n - i] * pre % mod) % mod;
      pre = (pre * 2 % mod + a[i] % mod) % mod;
    }
    cout << ans % mod << endl;
  }
  return 0;
}
