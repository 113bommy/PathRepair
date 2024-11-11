#include <bits/stdc++.h>
using namespace std;
long long modI(long long a, long long m);
long long gcd(long long a, long long b);
long long powM(long long x, long long y, long long m);
long long swap(long long a, long long b);
void swap(long long& a, long long& b) {
  long long tp = a;
  a = b;
  b = tp;
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
long long modI(long long a, long long m) {
  long long m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
const long long N = 30007;
long long gem[N];
long long dp[N][500];
bool used[N][500];
long long n, d;
long long solve(long long i, long long j) {
  long long tp = j - (d - 250);
  if (i >= N) return 0;
  if (used[i][tp]) return dp[i][tp];
  used[i][tp] = 1;
  long long tpans;
  if (j == 1) {
    tpans = gem[i] + max(solve(i + j, j), solve(i + j + 1, j + 1));
  } else {
    tpans = gem[i] + max(solve(i + j - 1, j - 1),
                         max(solve(i + j, j), solve(i + j + 1, j + 1)));
  }
  dp[i][j] = tpans;
  return tpans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long tt = 1;
  while (tt--) {
    cin >> n >> d;
    for (long long i = 0; i < n; i++) {
      long long z;
      cin >> z;
      gem[z]++;
    }
    long long ans = solve(d, d);
    cout << ans << "\n";
  }
  return 0;
}
