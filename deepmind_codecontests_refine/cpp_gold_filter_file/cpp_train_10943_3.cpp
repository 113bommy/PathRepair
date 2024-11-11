#include <bits/stdc++.h>
using namespace std;
int i, j, m, n, p, k, a[2005][2005], D[2005], Pow[2005], F[2005][2005], k1;
int used[2005], tree[2][2005], u1 = 0, u2;
int lowbit(int x) { return x & -x; }
void ins(int ty, int x, int c) {
  for (; x <= n; x += lowbit(x)) tree[ty][x] += c;
}
int ask(int ty, int x) {
  int sum = 0;
  for (; x; x -= lowbit(x)) sum += tree[ty][x];
  return sum;
}
int Calc(int p) {
  int ans = 0, i;
  memset(tree, 0, sizeof(tree));
  memset(used, 0, sizeof(used));
  if (p == 1) {
    for (i = 1, u1 = 0, u2 = n; i <= n; ++i) ins(1, i, 1), used[i] = 1;
  } else
    for (i = 1, u1 = n, u2 = 0; i <= n; ++i) ins(0, i, 1);
  for (i = 1; i <= n; ++i) {
    k = a[p][i];
    if (a[p - 1][i]) {
      k1 = a[p - 1][i];
      if (used[k1] == 0) {
        ins(0, k1, -1);
        ins(1, k1, 1);
        u2++;
        u1--;
        used[k1] = 1;
      }
    }
    int A1 = ask(0, k - 1), A2 = ask(1, k - 1);
    if (k1) {
      if (used[k1] == 0 && k1 < k) A1--;
      if (used[k1] == 1 && k1 < k) A2--;
    }
    if (A1) ans = (ans + 1ll * A1 * F[u1 - 1][u2] % 998244353) % 998244353;
    if (A2) ans = (ans + 1ll * A2 * F[u1][u2 - 1] % 998244353) % 998244353;
    if (used[k] == 1)
      ins(1, k, -1), u2--;
    else
      ins(0, k, -1), u1--;
    used[k] = 2;
  }
  return ans;
}
int fac[2005];
int main() {
  int ans = 0;
  fac[0] = 1;
  for (i = 1; i < 2005; ++i) fac[i] = 1ll * fac[i - 1] * i % 998244353;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  D[1] = 0;
  D[2] = 1;
  for (i = 3; i <= n; ++i)
    D[i] = 1ll * (i - 1) * (D[i - 2] + D[i - 1]) % 998244353;
  for (i = 0; i <= n; ++i) F[i][0] = D[i], F[0][i] = fac[i];
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      F[i][j] = 1ll * F[i - 1][j] * (i + j - 1) % 998244353;
      if (i >= 2)
        F[i][j] =
            (F[i][j] + 1ll * F[i - 2][j] * (i - 1) % 998244353) % 998244353;
    }
  Pow[0] = 1;
  for (i = 1; i <= n; ++i) Pow[i] = 1ll * Pow[i - 1] * D[n] % 998244353;
  for (i = 1; i <= n; ++i)
    ans = (ans + 1ll * Calc(i) * Pow[n - i] % 998244353) % 998244353;
  printf("%d\n", ans);
}
