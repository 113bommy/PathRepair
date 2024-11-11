#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powmod(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = powmod(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modif(long long x, long long m) { return (powmod(x, m - 2, m)); }
bool fa(vector<long long> &x, vector<long long> &y) { return x[0] < y[0]; }
bool fa1(vector<long long> &x, vector<long long> &y) { return x[1] < y[1]; }
bool f1(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.second < y.second;
}
bool f2(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.first < y.first;
}
bool f3(long long &x, long long &y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long dp[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  long long b[26];
  long long ans = 0;
  for (int i = 0; i < 26; i++) cin >> b[i];
  long long f[n + 1];
  for (int i = 1; i < n + 1; i++) {
    long long c[26];
    for (int t = 0; t < 26; t++) c[t] = 0;
    long long len = 1;
    for (int t = 1; t < n + 1; t++) {
      long long x = i - t;
      if (x < 0) break;
      c[s[x] - 97]++;
      long long j = 0;
      for (int z = 0; z < 26; z++) {
        if (len > b[z] && c[z] > 0) {
          j++;
          break;
        }
      }
      if (j) break;
      ans = max(ans, len);
      dp[i] += dp[x];
      f[i] = len;
      dp[i] %= 1000000007;
      len++;
    }
  }
  cout << dp[n] << "\n";
  cout << ans << "\n";
  long long x = n;
  long long it = 0;
  while (x != 0) {
    x -= f[x];
    it++;
  }
  cout << it;
  return 0;
}
