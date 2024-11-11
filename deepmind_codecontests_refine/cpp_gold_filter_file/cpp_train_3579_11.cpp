#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
long long dp[301][301];
long long f(long long p, long long q) {
  if (p > q) swap(p, q);
  if (p == q && p != 0) return 1;
  if ((p == 1 || q == 1) && (q + p < 3)) return 1;
  if (dp[p][q] != -1) return dp[p][q];
  if (q == 0 && q == 0) return 0;
  if ((p == 0) || (q == 0)) return 1;
  long long i, j, first, k;
  first = 0;
  for (i = 1; i < p; i++) {
    k = f(i, q);
    if (k == 0) {
      first = 1;
    }
  }
  for (i = 1; i < q; i++) {
    k = f(p, i);
    if (k == 0) {
      first = 1;
    }
  }
  for (i = 1; i < min(p, q) + 1; i++) {
    k = f(p - i, q - i);
    if (k == 0) {
      first = 1;
    }
  }
  dp[p][q] = first;
  return first;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, first, n, m;
  memset(dp, -1, sizeof(dp));
  cin >> n;
  if (n == 1) {
    cin >> first;
    if (first != 0) {
      cout << "BitLGM";
    } else {
      cout << "BitAryo";
    }
  } else if (n == 2) {
    cin >> n >> m;
    first = f(n, m);
    if (first == 1) {
      cout << "BitLGM";
    } else {
      cout << "BitAryo";
    }
  } else {
    cin >> n >> m >> first;
    if ((n ^ first ^ m) != 0) {
      cout << "BitLGM";
    } else {
      cout << "BitAryo";
    }
  }
  return 0;
}
