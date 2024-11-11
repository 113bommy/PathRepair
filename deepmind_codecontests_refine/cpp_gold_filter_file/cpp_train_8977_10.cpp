#include <bits/stdc++.h>
using namespace std;
long long int mod = LLONG_MAX;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int ans = power(a, b / 2);
  ans = (ans * ans) % mod;
  if (b % 2) ans *= a;
  return ans % mod;
}
long long int mul(long long int a, long long int n, long long int mod) {
  long long int ret;
  if (n == 0) return 0;
  ret = mul(a, n / 2, mod);
  ret = (ret + ret) % mod;
  if (n % 2) ret = (ret + a) % mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long int t, n, val;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> help;
    vector<long long int> aval;
    help.push_back(1);
    aval.push_back(1);
    for (int i = 1; i <= 62; i++) {
      help.push_back(2 * help[i - 1] + 1);
      aval.push_back(aval[i - 1] * 2);
    }
    long long int ans = 0;
    for (int i = 62; i >= 0; i--) {
      if (n >= aval[i]) {
        n -= aval[i];
        ans += help[i];
      }
    }
    cout << ans << "\n";
  }
}
