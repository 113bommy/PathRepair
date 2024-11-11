#include <bits/stdc++.h>
using namespace std;
const int N = 255, Mo = 1e9 + 7;
int n, k, m, x, f[N], g[N], a[N], b[N], c[N], p[N];
int F[N], G[N], H[N];
long long T;
void mul(int *a, int *b, int *c) {
  for (int i = 0; i <= 2 * k - 2; i++) g[i] = 0;
  for (int i = 0; i <= k - 1; i++)
    for (int j = 0; j <= k - 1; j++)
      (g[i + j] += (long long)a[i] * b[j] % Mo) %= Mo;
  for (int i = 2 * k - 2; i >= k; i--)
    for (int j = k - 1; j >= 0; j--)
      (g[i - k + j] -= (long long)g[i] * f[j] % Mo) %= Mo;
  for (int i = 0; i <= k - 1; i++) c[i] = g[i];
}
int main() {
  scanf("%d%d%d", &n, &m, &T);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    k = max(k, x);
    a[x]++;
  }
  for (int i = 0; i <= k - 1; i++) f[i] = -a[k - i];
  f[k] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k - 1; j++) b[j] = c[j] = 0;
    if (k > 1)
      b[1] = 1;
    else
      b[0] = -f[0];
    c[0] = 1;
    for (; p[i]; p[i] >>= 1, mul(b, b, b))
      if (p[i] & 1) mul(c, b, c);
    for (int j = 0; j <= k - 1; j++) (F[j] += c[j]) %= Mo;
  }
  G[0] = 1;
  for (; T; T >>= 1, mul(F, F, F))
    if (T & 1) mul(G, F, G);
  H[0] = 1;
  for (int i = 1; i <= k - 1; i++)
    for (int j = 0; j <= i; j++)
      (H[i] += (long long)a[j] * H[i - j] % Mo) %= Mo;
  int ans = 0;
  for (int i = 0; i <= k - 1; i++) (ans += (long long)G[i] * H[i] % Mo) %= Mo;
  printf("%d\n", (ans + Mo) % Mo);
  return 0;
}
