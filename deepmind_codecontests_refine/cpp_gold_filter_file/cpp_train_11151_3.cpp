#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int mod = 998244353;
string s, t;
int sum[MAXN];
long long qpow(long long a, long long b) {
  long long sum = 1;
  while (b) {
    if (b & 1) {
      sum = sum * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return sum;
}
int main() {
  int n, m;
  cin >> n >> m;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  for (int i = m - 1; i >= 0; i--) {
    sum[i] = sum[i + 1];
    if (t[i] == '1') sum[i]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ans = (ans + qpow(2, i) * sum[i] % mod) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
