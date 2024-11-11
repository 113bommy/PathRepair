#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int data = 0, m = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') {
    m = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = (data << 1) + (data << 3) + (ch ^ 48);
    ch = getchar();
  }
  return (m) ? data : -data;
}
int f[3105][3105], P[3105], pre[3105][3105], Inv[3105], Ifac[3105], rc[3105],
    Fac, n, D, Ans;
vector<int> son[3105];
void dfs(int u) {
  int sz = son[u].size();
  for (int i = 0; i < sz; i++) {
    int v = son[u][i];
    dfs(v);
  }
  for (int i = 1; i <= 3000; i++) f[u][i] = 1;
  for (int i = 0; i < sz; i++) {
    int v = son[u][i];
    for (int j = 1; j <= 3000; j++)
      f[u][j] = 1ll * f[u][j] * pre[v][j] % 1000000007;
  }
  for (int j = 1; j <= 3000; j++)
    pre[u][j] = (pre[u][j - 1] + f[u][j]) % 1000000007;
  return;
}
inline int Pow(int T, int js) {
  int S = 1;
  while (js) {
    if (js & 1) S = 1ll * S * T % 1000000007;
    T = 1ll * T * T % 1000000007;
    js >>= 1;
  }
  return S;
}
void Interp() {
  Fac = 1;
  for (int i = 0; i <= n; i++) Fac = 1ll * Fac * (D - i) % 1000000007;
  Inv[0] = Inv[1] = 1;
  for (int i = 2; i <= n; i++)
    Inv[i] =
        1ll * (1000000007 - 1000000007 / i) * Inv[1000000007 % i] % 1000000007;
  Ifac[0] = 1;
  for (int i = 1; i <= n; i++)
    Ifac[i] = 1ll * Ifac[i - 1] * Inv[i] % 1000000007;
  for (int i = 0; i <= n; i++) rc[i] = (i & 1) ? 1000000007 - 1 : 1;
  Ans = 0;
  for (int i = 1; i <= n; i++) {
    int Ret = 1;
    Ret = 1ll * rc[i] * P[i] % 1000000007;
    Ret = 1ll * Ret * Ifac[n - i] % 1000000007 * Ifac[i] % 1000000007;
    Ret = 1ll * Ret * Pow(D - i, 1000000007 - 2) % 1000000007;
    Ans = (Ans + Ret) % 1000000007;
  }
  printf("%lld\n", 1ll * Fac * Ans % 1000000007);
  return;
}
int main() {
  n = gi();
  D = gi();
  for (int i = 2, u; i <= n; i++) u = gi(), son[u].push_back(i);
  dfs(1);
  P[0] = 0;
  for (int i = 1; i <= 3000; i++) P[i] = (P[i - 1] + f[1][i]) % 1000000007;
  if (D <= 3000)
    printf("%d\n", P[D]);
  else
    Interp();
  return 0;
}
