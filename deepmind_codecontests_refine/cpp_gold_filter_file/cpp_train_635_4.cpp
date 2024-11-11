#include <bits/stdc++.h>
const int N = 1e5, V = 5;
const unsigned long long MOD = 1ull << 58, INV5 = 14757395258967641293ull;
struct Com {
  unsigned long long a[V];
  inline void clear() { a[0] = a[1] = a[2] = a[3] = a[4] = 0; }
  inline Com() { clear(); }
  inline unsigned long long &operator[](int x) { return a[x]; }
  inline const unsigned long long &operator[](const int &x) const {
    return a[x];
  }
  inline Com operator+(const Com &b) const {
    Com c;
    for (int i = 0; i < V; i++) c[i] = a[i] + b[i];
    return c;
  }
  inline Com operator-(const Com &b) const {
    Com c;
    for (int i = 0; i < V; i++) c[i] = a[i] - b[i];
    return c;
  }
  inline Com operator*(const unsigned long long &b) const {
    Com c;
    for (int i = 0; i < V; i++) c[i] = a[i] * b;
    return c;
  }
  inline Com operator*(const Com &b) const {
    static unsigned long long d[V << 1];
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) d[i + j] += a[i] * b[j];
    Com c;
    for (int i = 0; i < V; i++) c[i] = d[i] + d[i + V], d[i] = d[i + V] = 0;
    return c;
  }
  inline Com &operator+=(const Com &b) { return *this = *this + b; }
  inline Com &operator*=(const unsigned long long &b) {
    return *this = *this * b;
  }
  inline Com &operator*=(const Com &b) { return *this = *this * b; }
  inline void out() {
    printf("(%llu,%llu,%llu,%llu,%llu)\n", a[0], a[1], a[2], a[3], a[4]);
  }
  inline unsigned long long val() { return (a[0] - a[4]) >> 5; }
  inline bool operator!=(const Com &b) const {
    for (int i = 0; i < V; i++)
      if (a[i] != b[i]) return 1;
    return 0;
  }
} w[2][V << 1], a[N];
inline Com qpow(Com a, int b) {
  Com c;
  c[0] = 1;
  for (; b; b >>= 1, a *= a)
    if (b & 1) c *= a;
  return c;
}
inline void pre() {
  w[0][0][0] = w[1][0][0] = 1;
  w[0][1][3] = w[1][1][2] = -1;
  for (int i = 2; i < V << 1; i++) {
    w[0][i] = w[0][i - 1] * w[0][1], w[1][i] = w[1][i - 1] * w[1][1];
  }
}
const int pw[V] = {1, 10, 100, 1000, 10000};
inline void fft(int opt) {
  for (int i = 0; i < V; i++)
    for (int j = 0; j < N; j++)
      if (!((j / pw[i]) % 10)) {
        static Com f[V << 1];
        for (int a = 0; a < V << 1; a++)
          for (int b = 0; b < V << 1; b++) {
            f[a] += ::a[j + b * pw[i]] *
                    (opt ? w[0][(10 - a * b % 10) % 10] : w[0][a * b % 10]);
          }
        for (int a = 0; a < V << 1; a++) {
          ::a[j + a * pw[i]] = f[a];
          f[a].clear();
        }
      }
  if (opt) {
    unsigned long long INV = INV5 * INV5 * INV5 * INV5 * INV5;
    for (int i = 0; i < N; i++) a[i] *= INV;
  }
}
int n;
int main() {
  pre();
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    a[x][0]++;
  }
  fft(0);
  for (int i = 0; i < N; i++) a[i] = qpow(a[i], n);
  fft(1);
  for (int i = 0; i < n; i++) printf("%llu\n", a[i].val() % MOD);
  return 0;
}
