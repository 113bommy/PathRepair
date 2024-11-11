#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 2e5 + 10;
int pre[40];
int ans[N];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int len = s.length();
  int tot = 0;
  for (int i = 0; i < len; i++) {
    int mx = 0;
    for (int j = s[i] - 'a' + 1; j < 26; j++) {
      mx = max(mx, pre[j]);
    }
    ans[i] = mx + 1;
    tot = max(ans[i], tot);
    pre[s[i] - 'a'] = max(mx + 1, pre[s[i] - 'a']);
  }
  if (tot > 2)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < len; i++) cout << ans[i] - 1;
  }
  return 0;
}
