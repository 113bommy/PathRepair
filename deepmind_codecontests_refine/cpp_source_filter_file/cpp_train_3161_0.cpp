#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long gcd(long long a, long long b) { return (a == 0) ? b : gcd(b % a, a); }
long long cnt1(long long x) {
  long long cnt = 0;
  while (x > 0) x &= x - 1, cnt++;
  return cnt;
}
long long fact(long long n) { return n == 0 ? 1LL : n * fact(n - 1); }
long long fact(long long n, long long p) {
  return n == 0 ? 1LL : n * fact(n - 1) % p;
}
long long cnk(long long n, long long k) {
  return n == 1 || k == 1 ? 1 : cnk(n - 1, k) + cnk(n - 1, k - 1);
}
long long pow(long long a, long long n, long long p) {
  if (n == 0) return 1;
  long long t = pow(a, n / 2, p);
  return t * t * (n % 2 ? a : 1);
}
long long cnk(long long n, long long k, long long p) {
  return fact(n, p) * pow(fact(k, p), p - 2, p) * pow(fact(n - k, p), p - 2, p);
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (long long i = 0; i < v.size(); i++) is >> v[i];
  return is;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (long long i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << '\n';
  return os;
}
const long long N = 1001;
long long a[N][N];
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  long long cnt[N][2] = {0};
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < m; j++) {
      a[i][j] = s[j] == '#';
      cnt[j][1] += s[j] == '#';
      cnt[j][0] += s[j] == '.';
    }
  }
  for (long long i = 1; i < m; i++)
    cnt[i][0] += cnt[i - 1][0], cnt[i][1] += cnt[i - 1][1];
  long long dp[N][2];
  for (long long i = 0; i < N; i++) dp[0][1] = dp[0][0] = 1e+5;
  for (long long i = 1; i < m; i++)
    for (long long j = 0; j < 2; j++) {
      dp[i][j] = 1e+5;
      for (long long k = x; k <= y; k++)
        if (i - k + 1 >= 0)
          dp[i][j] = min(
              dp[i][j],
              cnt[i][1 - j] -
                  (i - k + 1 == 0 ? 0 : cnt[i - k][1 - j] - dp[i - k][1 - j]));
    }
  cout << min(dp[m - 1][0], dp[m - 1][1]);
}
