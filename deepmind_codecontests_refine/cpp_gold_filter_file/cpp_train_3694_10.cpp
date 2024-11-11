#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[210];
int f[210][210][210], g[210];
void add(int &a, int b) { a = (a + b) % 10007; }
int tot;
struct Matrix {
  int m[210 * 2][210 * 2];
} T, T0, S;
void multi(Matrix &a, Matrix &b) {
  static Matrix c;
  for (int i = 0; i <= tot; ++i)
    for (int j = i; j <= tot; ++j) {
      long long sum = 0;
      for (int k = i; k <= j; ++k) sum += a.m[i][k] * b.m[k][j];
      c.m[i][j] = sum % 10007;
    }
  memcpy(&a, &c, sizeof c);
}
void getpow(int n) {
  for (; n; n >>= 1, multi(T, T))
    if (n & 1) multi(S, T);
}
void build(bool er = 1) {
  tot = n + ((n - 1) / 2 + 1) + 1 - 1;
  memset(&T, 0, sizeof T);
  for (int i = 0; i < n; ++i) {
    T.m[i][i] = 24;
    if (i < n - 1) T.m[i][i + 1] = 1;
    int j = tot - ((n - i - 1) / 2 + 1);
    T.m[i][j] = g[i];
  }
  for (int i = n; i < tot; ++i) {
    T.m[i][i] = 25;
    T.m[i][i + 1] = 1;
  }
  T.m[tot][tot] = (er ? 26 : 0);
}
int main() {
  scanf("%s%d", s + 1, &m);
  n = strlen(s + 1);
  f[1][n][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = n; j >= i; --j)
      for (int k = 0; k <= n - (j - i + 1); ++k)
        if (f[i][j][k]) {
          int v = f[i][j][k];
          if (i + 1 == j && s[i] == s[j] || i == j)
            add(g[k], v);
          else if (s[i] == s[j])
            add(f[i + 1][j - 1][k], v);
          else {
            add(f[i + 1][j][k + 1], v);
            add(f[i][j - 1][k + 1], v);
          }
        }
  build();
  if (n + m & 1) {
    S.m[0][1] = 1;
    S.m[0][tot - ((n - 1) / 2 + 1)] = g[0];
    getpow((n + m + 1 >> 1));
    long long ans = S.m[0][tot];
    for (int k = 0; k < n; ++k) {
      g[k] = 0;
      for (int i = 1; i < n; ++i)
        if (s[i] == s[i + 1]) add(g[k], f[i][i + 1][k]);
    }
    build(0);
    memset(&S, 0, sizeof S);
    S.m[0][1] = 1;
    S.m[0][tot - ((n - 1) / 2 + 1)] = g[0];
    getpow((n + m + 1 >> 1));
    ans = (ans - S.m[0][tot] + 10007) % 10007;
    printf("%d\n", ans);
  } else {
    S.m[0][1] = 1;
    S.m[0][tot - ((n - 1) / 2 + 1)] = g[0];
    getpow((n + m >> 1));
    printf("%d\n", S.m[0][tot]);
  }
  return 0;
}
