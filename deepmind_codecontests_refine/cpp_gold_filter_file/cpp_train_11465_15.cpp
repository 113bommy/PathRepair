#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
long long mpower(long long x, long long y, long long p);
long long modInv(long long a, long long m);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, k, l, p, q, r, x, y, z, a, b, c, d, f, n, m,
      M = 1000000007;
  string s;
  vector<long long> v, w;
  vector<long long>::iterator itrv;
  unordered_map<long long, long long> N;
  set<long long> S;
  set<long long>::iterator itr;
  cin >> t;
  long double aa, bb, cc;
  while (t--) {
    cin >> n;
    p = n * n;
    p -= 4 * n;
    if (p < 0) {
      cout << "N"
           << "\n";
      continue;
    }
    cout << "Y ";
    cc = sqrt(p);
    aa = (n + cc) / 2;
    bb = (n - cc) / 2;
    cout << fixed << setprecision(12) << aa << " " << bb << "\n";
  }
  return 0;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
  return res;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
