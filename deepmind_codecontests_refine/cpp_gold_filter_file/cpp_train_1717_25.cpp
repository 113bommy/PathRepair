#include <bits/stdc++.h>
using namespace std;
long long mod;
long long quickpow(long long a, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}
const int maxn = 2;
int num = 2;
struct mat {
  long long data[maxn][maxn];
  void one() {
    init();
    for (int i = 0; i < num; i++) data[i][i] = 1;
  }
  inline void init() { memset(data, 0, sizeof(data)); }
} st;
mat copy(const mat& a) {
  mat c;
  for (int i = 0; i < num; i++)
    for (int j = 0; j < num; j++) c.data[i][j] = a.data[i][j];
  return c;
}
mat operator*(const mat& a, const mat& b) {
  mat c;
  c.init();
  for (int k = 0; k < num; k++) {
    for (int i = 0; i < num; i++) {
      if (!a.data[i][k]) continue;
      for (int j = 0; j < num; j++) {
        c.data[i][j] += a.data[i][k] * b.data[k][j];
        c.data[i][j] %= mod;
      }
    }
  }
  return c;
}
mat operator+(const mat& a, const mat& b) {
  mat c;
  for (int i = 0; i < num; i++)
    for (int j = 0; j < num; j++)
      c.data[i][j] = (a.data[i][j] + b.data[i][j]) % mod;
  return c;
}
mat operator^(const mat& aa, long long k) {
  mat a = copy(aa);
  mat c;
  c.one();
  for (; k; k >>= 1) {
    if (k & 1) c = c * a;
    a = a * a;
  }
  return c;
}
long long n, r, le;
int main() {
  cin >> n >> r >> le >> mod;
  long long ans = 1 % mod;
  st.init();
  st.data[0][1] = st.data[1][0] = st.data[1][1] = 1;
  mat s = st ^ (n - 1);
  long long d0 = (s.data[0][0] + s.data[0][1]) % mod;
  long long d1 = (s.data[1][0] + s.data[1][1]) % mod;
  d0 = (d0 + d1) % mod;
  d1 = ((quickpow(2, n) - d0) % mod + mod) % mod;
  for (int i = 0; i < le; i++) {
    if (i < 60) {
      if (r & (1ll << i)) {
        ans = ans * d1 % mod;
        r -= (1ll << i);
      } else
        ans = ans * d0 % mod;
    } else
      ans = ans * d0 % mod;
  }
  if (r) ans = 0;
  cout << ans << endl;
}
