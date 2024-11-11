#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 998244353;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 998244353;
    a = a * a % 998244353;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve(long long ii) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  string str = s;
  long long ans = INT64_MAX;
  for (long long i = 0; i < n; i++) {
    if (str[i] == '>') {
      ans = min(ans, i);
      break;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (str[i] == '<') {
      ans = min(ans, n - i - 1);
      break;
    }
  }
  ans = min((long long)str.length() - 1, ans);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL),
      cout << setprecision(14);
  ;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
}
