#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 310;
const int P = 1000000007;
using namespace std;
inline void sc(int &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
inline void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
inline void pr(long long x) { print(x), putchar('\n'); }
int C[N][N], jc[N];
void init(const int fw) {
  C[0][0] = 1;
  for (int i = 1; i <= fw; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  jc[0] = 1;
  for (int i = 1; i <= fw; i++) jc[i] = 1LL * i * jc[i - 1] % P;
}
int a[N];
long long S(long long x) { return x * x; }
bool check(long long x) { return S(sqrt(x)) == x; }
bool vis[N];
int siz[N], sum[N];
int f[N][N];
int main() {
  int n;
  sc(n);
  init(n);
  for (int i = 1; i <= n; i++) sc(a[i]);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1, siz[++tot] = 1;
    for (int j = i + 1; j <= n; j++)
      if (check(1LL * a[i] * a[j])) vis[j] = 1, ++siz[tot];
    sum[tot] = sum[tot - 1] + siz[tot];
  }
  f[0][0] = 1;
  for (int i = 1; i <= tot; i++)
    for (int j = 0; j <= sum[i - 1]; j++)
      for (int k = 1; k <= min(siz[i], sum[i - 1] + 1); k++)
        for (int l = 0; l <= min(k, j); l++)
          (f[i][j - l + siz[i] - k] += 1LL * f[i - 1][j] *
                                       C[siz[i] - 1][k - 1] % P * C[j][l] % P *
                                       C[sum[i - 1] + 1 - j][k - l]) %= P;
  int ans = f[tot][0];
  for (int i = 1; i <= tot; i++) ans = 1LL * ans * jc[siz[i]] % P;
  pr(ans);
  return 0;
}
