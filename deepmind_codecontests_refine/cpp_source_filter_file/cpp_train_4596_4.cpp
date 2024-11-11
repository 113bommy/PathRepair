#include <bits/stdc++.h>
inline int getint() {
  int x = 0, p = 1;
  char c = getchar();
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;
const int K = 3;
const int m = 3;
const int inv2 = (mod + 1) / 2;
int n, k, a[K], p[N][K];
vector<int> f[N];
inline int add(int x, int y) {
  x += y;
  return (x >= mod) ? x - mod : x;
}
inline int sub(int x, int y) {
  x -= y;
  return (x < 0) ? x + mod : x;
}
inline int mul(int x, int y) {
  long long ans = 1ll * x * y;
  return ans % mod;
}
inline int modpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
void fwt(vector<int> &f, int len) {
  for (int step = 1; step < len; step <<= 1) {
    for (int i = 0; i < len; i += step << 1) {
      for (int j = i; j < i + step; j++) {
        int x = f[j], y = f[j + step];
        f[j] = add(x, y);
        f[j + step] = sub(x, y);
      }
    }
  }
}
void ifwt(vector<int> &f, int len) {
  for (int step = 1; step < len; step <<= 1) {
    for (int i = 0; i < len; i += step << 1) {
      for (int j = i; j < i + step; j++) {
        int x = f[j], y = f[j + step];
        f[j] = mul(add(x, y), inv2);
        f[j + step] = mul(sub(x, y), inv2);
      }
    }
  }
}
int main() {
  n = getint();
  k = getint();
  for (int(i) = 0; (i) < (k); (i)++) a[i] = getint() % mod;
  int sum = 0;
  for (int(i) = 0; (i) < (n); (i)++) {
    vector<int> v;
    for (int(j) = 0; (j) < (k); (j)++) p[i][j] = getint();
    sum ^= p[i][0];
    for (int j = 1; j < k; j++) p[i][j] ^= p[i][0];
  }
  vector<int> res;
  for (int(mask) = 0; (mask) < (1 << m); (mask)++) f[mask].emplace_back(n);
  for (int(mask) = 0; (mask) < (1 << k - 1); (mask)++)
    if (mask) {
      vector<int> g(1 << m, 0);
      for (int(i) = 0; (i) < (n); (i)++) {
        int ans = 0;
        for (int(j) = 0; (j) < (k - 1); (j)++)
          if (mask >> j & 1) ans ^= p[i][j + 1];
        ++g[ans];
      }
      fwt(g, 1 << m);
      for (int(i) = 0; (i) < (1 << m); (i)++) f[i].emplace_back(g[i]);
    }
  for (int(mask) = 0; (mask) < (1 << m); (mask)++) {
    res.emplace_back(1);
    ifwt(f[mask], 1 << k - 1);
    for (int(msk) = 0; (msk) < (1 << k - 1); (msk)++) {
      int ans = a[0];
      for (int(j) = 0; (j) < (k - 1); (j)++) {
        if (msk >> j & 1)
          ans = sub(ans, a[j + 1]);
        else
          ans = add(ans, a[j + 1]);
      }
      res.back() = mul(res.back(), modpow(ans, f[mask][msk]));
    }
  }
  ifwt(res, 1 << m);
  for (int(i) = 0; (i) < (1 << m); (i)++) printf("%d ", res[i ^ sum]);
  return 0;
}
