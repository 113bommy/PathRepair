#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 5;
const long long INF = 1e15 + 5;
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 5;
const double PI = 3.14159265358979323846264338327950288419716939937510;
long long n, q, fact[M], inv[M], dp[M], ans[55][55], temp[M], temp1[M];
unordered_map<long long, long long> m;
inline void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += MOD;
}
long long fmod(long long b, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1ll) res = (res * b) % MOD;
    b = (b * b) % MOD;
    exp /= 2ll;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  n = s.length();
  for (long long i = 1; i <= n; i++) {
    if (s[i - 1] - 'a' >= 0 && s[i - 1] - 'a' <= 25)
      m[s[i - 1] - 'a' + 1]++;
    else
      m[s[i - 1] - 'A' + 27]++;
  }
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
  inv[n] = fmod(fact[n], MOD - 2);
  for (long long i = n - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
  long long w = (fact[n / 2] * fact[n / 2]) % MOD;
  for (long long i = 1; i <= 52; i++) w = (w * inv[m[i]]) % MOD;
  dp[0] = 1;
  for (long long i = 1; i <= 52; i++) {
    for (long long j = n; j >= m[i]; j--) {
      if (!m[i]) continue;
      add(dp[j], dp[j - m[i]]);
    }
  }
  for (long long i = 1; i <= 52; i++) ans[i][i] = dp[n / 2];
  for (long long i = 1; i <= 52; i++) {
    if (!m[i]) continue;
    for (long long j = 0; j <= n; j++) temp[j] = dp[j];
    for (long long j = m[i]; j <= n; j++) sub(temp[j], temp[j - m[i]]);
    for (long long j = i + 1; j <= 52; j++) {
      if (!m[j]) continue;
      for (long long k = 0; k <= n; k++) temp1[k] = temp[k];
      for (long long k = m[j]; k <= n; k++) sub(temp1[k], temp1[k - m[j]]);
      ans[i][j] = ans[j][i] = (2 * temp1[n / 2]) % MOD;
    }
  }
  cin >> q;
  for (long long i = 1; i <= q; i++) {
    long long a, b, c, d;
    cin >> c >> d;
    if ((s[c - 1] - 'a') >= 0 && (s[c - 1] - 'a') <= 25)
      a = s[c - 1] - 'a' + 1;
    else
      a = s[c - 1] - 'A' + 27;
    if ((s[d - 1] - 'a') >= 0 && (s[d - 1] - 'a') <= 25)
      b = s[d - 1] - 'a' + 1;
    else
      b = s[d - 1] - 'A' + 27;
    cout << (w * ans[a][b]) % MOD << "\n";
  }
}
