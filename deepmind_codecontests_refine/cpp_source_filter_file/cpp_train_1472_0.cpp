#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5;
long long fenw[MAXN];
long long sum(long long n) {
  long long ret = 0;
  for (int i = n; i > -1; i = (i & (i + 1)) - 1) ret += fenw[i];
  return ret;
}
void up(long long pos, long long val) {
  for (int i = pos; i < MAXN; i |= (i + 1)) {
    fenw[i]++;
  }
}
long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
long long powm(long long a, long long n, long long mod) {
  if (n == 0) return 1;
  if (n % 2 == 1) return powm(a, n - 1, mod) * a % mod;
  long long b = powm(a, n / 2, mod);
  return b * b % mod;
}
int main() {
  cout.precision(30);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  int m = 0;
  for (auto &i : a)
    if (i == -1) m++;
  long long mod = 998244353;
  long long res = 0;
  long long cur = 0;
  long long inv = 0;
  for (int i = n - 1; i > -1; i--) {
    if (a[i] != -1) {
      inv += sum(a[i] - 1);
      up(a[i] - 1, 1);
    }
  }
  vector<long long> free(n, -1);
  for (int i = 0; i < n; i++) {
    if (a[i] == -1)
      cur++;
    else
      free[a[i] - 1] = cur;
  }
  cur = 0;
  for (int i = 0; i < n; i++) {
    if (free[i] != -1)
      cur += free[i];
    else {
      res += cur;
      res %= mod;
    }
  }
  cur = 0;
  for (int i = n - 1; i > -1; i--) {
    if (free[i] != -1)
      cur += m - free[i];
    else {
      res += cur;
      res %= mod;
    }
  }
  if (m == 0) {
    cout << inv % mod;
    return 0;
  }
  long long chisl = res * 4 % mod;
  chisl %= mod;
  chisl += m * (m - 1) % mod * m % mod;
  chisl %= mod;
  chisl += inv % mod * 4 * m % mod;
  chisl %= mod;
  long long znam = 4 * m;
  cout << chisl * powm(znam, mod - 2, mod) % mod;
  return 0;
}
