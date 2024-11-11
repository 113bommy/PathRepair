#include <bits/stdc++.h>
using namespace std;
long long F[2002];
long long Fi[2002];
long long mod = 1e9 + 7;
long long powm(long long a, long long n, long long mod) {
  if (a == 0) return 0;
  if (n == 0 || a == 1) return 1 % mod;
  long long pw = 1;
  while (n > 0) {
    if (n & 1) pw = pw * a % mod, n--;
    a = a * a % mod;
    n /= 2;
  }
  return pw;
}
long long C(long long n, long long k) {
  if (k > n) return 0;
  return ((F[n] * Fi[k]) % mod) * Fi[n - k] % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  F[0] = Fi[0] = 1;
  for (int i = 1; i <= 2000; i++)
    F[i] = (F[i - 1] * i) % mod, Fi[i] = powm(F[i], mod - 2, mod);
  long long ats = C(n - 1, 2 * k) * C(m - 1, 2 * k) % mod;
  cout << ats;
}
