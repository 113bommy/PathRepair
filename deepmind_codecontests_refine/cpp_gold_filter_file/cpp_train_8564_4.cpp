#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
vector<long long> dp[8];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long ans;
    if (n % 4 == 0) {
      ans = (((n / 4 + 1) % MOD) * (((n / 4 + 1)) % MOD)) % MOD;
    } else if (n % 4 == 1) {
      ans = (((n / 4 + 1) % MOD) * (((n / 4 + 1)) % MOD)) % MOD;
    } else if (n % 4 == 2) {
      ans = (((n / 4 + 1) % MOD) * (((n / 4 + 2)) % MOD)) % MOD;
    } else {
      ans = (((n / 4 + 1) % MOD) * (((n / 4 + 2)) % MOD)) % MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}
