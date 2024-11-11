#include <bits/stdc++.h>
using namespace std;
const int N = 512;
const int mod = 1e9 + 7;
void ADD(int &x, int y) { (x += y) >= mod ? x -= mod : 0; }
void DEC(int &x, int y) { (x -= y) < 0 ? x += mod : 0; }
char s[N], c[N];
int n, m, id = 1, f[N], dp[N][1 << 16], st[16][5];
vector<int> G[N];
void OR(int *a, int n, int op) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++)
        if (op == 1)
          ADD(a[j + k + i], a[j + k]);
        else
          DEC(a[j + k + i], a[j + k]);
}
void AND(int *a, int n, int op) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++)
        if (op == 1)
          ADD(a[j + k], a[j + k + i]);
        else
          DEC(a[j + k], a[j + k + i]);
}
void trans(int *a, int *b, int *c, void (*fun)(int *, int, int)) {
  static int C[1 << 16], A[1 << 16], B[1 << 16];
  for (int i = 0; i <= m - 1; ++i) A[i] = a[i], B[i] = b[i];
  fun(A, m, 1);
  fun(B, m, 1);
  for (int i = 0; i <= m - 1; ++i) C[i] = (long long)A[i] * B[i] % mod;
  fun(C, m, -1);
  for (int i = 0; i <= m - 1; ++i) ADD(c[i], C[i]);
}
void dfs(int u) {
  if (!G[u].size()) {
    if (c[u] == '?') {
      for (int i = 0; i <= 3; ++i)
        for (int j = 0; j <= 1; ++j) {
          int v = 0;
          for (int k = 0; k <= n - 1; ++k)
            if (st[k][i] ^ j) v ^= 1 << k;
          dp[u][v]++;
        }
    } else {
      int v = 0, i = c[u] >= 'a' ? c[u] - 'a' : c[u] - 'A', j = c[u] >= 'a';
      for (int k = 0; k <= n - 1; ++k)
        if (st[k][i] ^ j) v ^= 1 << k;
      dp[u][v] = 1;
    }
    return;
  }
  int ls = G[u][0], rs = G[u][1];
  dfs(ls);
  dfs(rs);
  if (c[u] != '&') trans(dp[ls], dp[rs], dp[u], OR);
  if (c[u] != '|') trans(dp[ls], dp[rs], dp[u], AND);
}
int main() {
  scanf("%s%d", s + 1, &n);
  m = 1 << n;
  int p = 1;
  for (int i = 1; s[i]; i++) {
    if (s[i] == '(')
      G[p].push_back(++id), f[id] = p, p = id;
    else if (s[i] == ')')
      p = f[p];
    else
      c[p] = s[i];
  }
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= 4; ++j) scanf("%d", st[i] + j);
  int v = 0;
  for (int i = 0; i <= n - 1; ++i)
    if (st[i][4]) v ^= 1 << i;
  dfs(1);
  printf("%d\n", dp[1][v]);
  return 0;
}
