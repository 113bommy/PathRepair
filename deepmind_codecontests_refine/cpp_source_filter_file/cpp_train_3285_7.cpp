#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int P = 998244353;
int k, n, m, x;
int nx[N], d[N];
int c[N][N], p[N][N], s[N][N];
int a, b, cl, bl;
int f[N], g[N], h[N], Ans[N];
bool v[N];
void Add(int& x, int y) { x = (x + y) % P; }
void init(int n) {
  s[0][0] = c[0][0] = p[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = p[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P,
      s[i][j] = (s[i - 1][j - 1] + 1ll * j * s[i - 1][j]) % P,
      p[i][j] = 1ll * p[i][j - 1] * (i - j + 1) % P;
  }
}
void Dfs(int x, bool y, bool z) {
  v[x] = 1;
  if (nx[x]) {
    if (!v[nx[x]])
      Dfs(nx[x], y ^ 1, z);
    else
      cl++;
  } else {
    if (y && z) bl++;
    if (y && !z) a++;
    if (!y && z) b++;
  }
}
void Get(int n, int* f) {
  for (int i = n; ~i; i--) {
    for (int j = 0; j <= n; j++)
      Add(f[i], 1ll * c[n][j] * s[j][i] % P * p[n - j + bl][n - j] % P);
    for (int j = i + 1; j <= n; j++) Add(f[i], -1ll * f[j] * c[j][i] % P);
  }
}
int main() {
  scanf("%d", &n);
  init(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (!x) continue;
    nx[i] = n + x;
    d[n + x]++;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (!x) continue;
    nx[n + x] = i;
    d[i]++;
  }
  for (int i = 1; i <= (n << 1); i++)
    if (!v[i] && !d[i]) Dfs(i, i > n, i > n);
  for (int i = 1; i <= (n << 1); i++)
    if (!v[i]) Dfs(i, i > n, i > n);
  Get(a, f);
  Get(b, g);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++) Add(h[i], 1ll * f[j] * g[i - j] % P);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) Add(Ans[i], 1ll * h[j] * s[bl][i - j] % P);
    Ans[i] = 1ll * Ans[i] * p[bl][bl] % P;
  }
  for (int i = 0; i < n; i++) {
    if (n - cl - i < 0)
      printf("0 ");
    else
      printf("%d ", (Ans[n - cl - i] + P) % P);
  }
  return 0;
}
