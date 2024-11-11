#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1005;
long long p2[MAX];
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
    ans %= MOD;
    a %= MOD;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  p2[0] = 1;
  for (int i = 1; i < MAX; i++) p2[i] = (p2[i - 1] * 2) % MOD;
  string s;
  cin >> s;
  int n = s.length();
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') {
      long long res = p2[i];
      res *= p2[2 * (n - i - 1)];
      res %= MOD;
      ans += res;
      ans %= MOD;
    }
  cout << ans << endl;
  return 0;
}
