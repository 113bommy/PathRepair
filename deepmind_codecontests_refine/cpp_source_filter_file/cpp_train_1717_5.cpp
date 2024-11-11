#include <bits/stdc++.h>
using namespace std;
unsigned long long mod;
struct mat {
  unsigned long long a[2][2];
  unsigned long long n;
  mat(unsigned long long _n = 0, unsigned long long v = 0) {
    n = _n;
    memset(a, 0, sizeof a);
  }
};
mat operator*(mat a, mat b) {
  mat an;
  for (unsigned long long i = 0; i <= 1; i++)
    for (unsigned long long j = 0; j <= 1; j++)
      for (unsigned long long k = 0; k <= 1; k++)
        an.a[i][j] = (an.a[i][j] + (a.a[i][k] * b.a[k][j]) % mod) % mod;
  return an;
}
mat operator^(mat a, unsigned long long x) {
  mat an;
  an.a[1][1] = an.a[0][0] = 1;
  if (!x) return an;
  an = a ^ (x / 2);
  if (x % 2) return an * an * a;
  return an * an;
}
unsigned long long powe(unsigned long long x, unsigned long long y) {
  unsigned long long z = 1;
  if (!y) return z;
  z = powe(x, y / 2);
  z = (z * z) % mod;
  if (y % 2) return (z * x) % mod;
  return z % mod;
}
int main() {
  unsigned long long n, l, k, as = 0;
  cin >> n >> k >> l >> mod;
  mat ans;
  ans.a[0][0] = ans.a[1][0] = ans.a[0][1] = 1;
  ans = ans ^ (n + 1);
  unsigned long long ans1 = ans.a[0][0];
  unsigned long long ans2 = 1;
  unsigned long long pw = powe(2, n);
  for (unsigned long long i = 0; i < l; i++) {
    if (k & (1LL << i)) {
      as += (1LL << i);
      ans2 = (ans2 * ((pw - ans1 + mod) % mod)) % mod;
    } else
      ans2 = (ans2 * ans1) % mod;
  }
  if (k - as)
    cout << 0 << endl;
  else
    cout << ans2 << endl;
}
