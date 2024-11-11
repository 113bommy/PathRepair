#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long MOD2 = 998244353;
const long long N = 1000 * 100 + 10;
const long long N2 = 70;
const long double PI = 3.141592653589793;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void solve2() {}
signed main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  ;
  istream& in(cin);
  ostream& out(cout);
  string s1, s2;
  in >> s1 >> s2;
  long long a[8][8] = {{0}};
  long long i = s1[0] - 'a';
  long long j = s1[1] - '1';
  a[i][j] = 1;
  for (long long k = 0; k < 8; k++) {
    a[i][k] = 1;
  }
  for (long long k = 0; k < 8; k++) {
    a[k][j] = 1;
  }
  if (i >= 2 and j >= 1) a[i - 2][j - 1] = 1;
  if (i >= 2 and j <= 6) a[i - 2][j + 1] = 2;
  if (i >= 1 and j <= 5) a[i - 1][j + 2] = 1;
  if (i <= 6 and j <= 5) a[i + 1][j + 2] = 1;
  if (i <= 5 and j >= 1) a[i + 2][j - 1] = 1;
  if (i <= 5 and j <= 6) a[i + 2][j + 1] = 1;
  if (i >= 1 and j >= 2) a[i - 1][j - 2] = 1;
  if (i <= 6 and j >= 2) a[i + 1][j - 2] = 1;
  i = s2[0] - 'a';
  j = s2[1] - '1';
  a[i][j] = 1;
  if (i >= 2 and j >= 1) a[i - 2][j - 1] = 1;
  if (i >= 2 and j <= 6) a[i - 2][j + 1] = 1;
  if (i >= 1 and j <= 5) a[i - 1][j + 2] = 1;
  if (i <= 6 and j <= 5) a[i + 1][j + 2] = 1;
  if (i <= 5 and j >= 1) a[i + 2][j - 1] = 1;
  if (i <= 5 and j <= 6) a[i + 2][j + 1] = 1;
  if (i >= 1 and j >= 2) a[i - 1][j - 2] = 1;
  if (i <= 6 and j >= 2) a[i + 1][j - 2] = 1;
  long long cnt = 0;
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      if (a[i][j] == 0) {
        cnt++;
      }
    }
  }
  out << cnt;
  return 0;
}
