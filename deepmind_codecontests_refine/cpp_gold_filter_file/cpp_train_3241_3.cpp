#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x = f ? -x : x;
}
const int N = 100 + 10;
const int P = 998244353;
int K, n, m, i, j, x, y, yy, t, b[N];
struct matrix {
  int v[N][N];
  void O() { memset(v, 0, sizeof(v)); }
  void E() {
    memset(v, 0, sizeof(v));
    for (int i = 0; i < K; ++i) v[i][i] = 1;
  }
  matrix operator*(const matrix &b) const {
    matrix c;
    c.O();
    for (int k = 0; k < K; k++) {
      for (int i = 0; i < K; i++)
        if (v[i][k]) {
          for (int j = 0; j < K; j++) {
            c.v[i][j] = (c.v[i][j] + (long long)v[i][k] * b.v[k][j]) % (P - 1);
          }
        }
    }
    return c;
  }
  matrix operator^(int p) const {
    matrix y;
    y.E();
    matrix x;
    memcpy(x.v, v, sizeof(v));
    while (p) {
      if (p & 1) y = y * x;
      x = x * x;
      p >>= 1;
    }
    return y;
  }
} mat;
int fexp(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    n >>= 1;
  }
  return res;
}
int baby_step_gaint_step(int a, int b, int p) {
  map<int, int> hash;
  hash.clear();
  b %= p;
  int t = (int)sqrt(p) + 1;
  for (int j = 0; j < t; ++j) {
    int val = (long long)b * fexp(a, j, p) % p;
    hash[val] = j;
  }
  a = fexp(a, t, p);
  if (a == 0) return b == 0 ? 1 : -1;
  for (int i = 0; i <= t; ++i) {
    int val = fexp(a, i, p);
    int j = hash.find(val) == hash.end() ? -1 : hash[val];
    if (j >= 0 && i * t - j >= 0) return i * t - j;
  }
  return -1;
}
int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int z = x;
  x = y;
  y = z - y * (a / b);
  return d;
}
int main() {
  read(K);
  for (i = 1; i <= K; ++i) read(b[i]);
  read(n), read(m);
  for (i = 0; i < K; ++i) mat.v[0][i] = b[i + 1];
  for (i = 1; i < K; ++i) mat.v[i][i - 1] = 1;
  mat = mat ^ (n - K);
  y = mat.v[0][0];
  t = baby_step_gaint_step(3, m, P);
  if (t == -1) return puts("-1"), 0;
  int d = exgcd(y, P - 1, x, yy);
  if (t % d != 0)
    puts("-1");
  else {
    x = 1LL * x * t / d % (P - 1);
    x = (x % (P - 1) + (P - 1)) % (P - 1);
    printf("%d\n", fexp(3, x, P));
  }
  return 0;
}
