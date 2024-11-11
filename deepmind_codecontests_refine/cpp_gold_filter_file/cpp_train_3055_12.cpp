#include <bits/stdc++.h>
using namespace std;
int mod;
struct EDGE {
  int to, nxt;
} box[101000 * 2];
int h[101000], top, f1[101000], f2[101000];
void add(int u, int v) {
  box[top].to = v;
  box[top].nxt = h[u];
  h[u] = top++;
}
int dp[610][610];
int dfs(int a, int b) {
  if (dp[a][b] + 1) return dp[a][b];
  int p = h[a];
  dp[a][b] = 0;
  while (p != -1) {
    dp[a][b] = (dp[a][b] + dfs(box[p].to, b)) % mod;
    p = box[p].nxt;
  }
  return dp[a][b];
}
long long ni(long long i) {
  int n = mod - 2;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * i % mod;
    i = i * i % mod;
    n >>= 1;
  }
  return res;
}
int ss[610], sn[610], c1, c2;
int mat[610][610];
int main() {
  int n, m;
  scanf("%d%d%d", &n, &m, &mod);
  memset(dp, -1, sizeof(dp));
  memset(h, -1, sizeof(h));
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    f1[a] = 1;
    f2[b] = 1;
    add(a, b);
  }
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] == -1) dfs(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!f1[i]) sn[c1++] = i;
    if (!f2[i]) ss[c2++] = i;
  }
  for (int i = 0; i < c1; i++) {
    for (int j = 0; j < c1; j++) {
      mat[i][j] = dp[ss[i]][sn[j]];
    }
  }
  long long ans = 1;
  for (int j = 0; j < c1; j++) {
    int r;
    for (r = j; r < c1; r++) {
      if (mat[r][j]) break;
    }
    if (r == c1) {
      ans = 0;
      break;
    }
    for (int k = j; k < c1; k++) swap(mat[j][k], mat[r][k]);
    if (r != j) ans = -ans;
    for (int i = 0; i < c1; i++) {
      if (i == j) continue;
      long long a = mat[i][j], b = mat[j][j];
      for (int k = 0; k < c1; k++) {
        mat[i][k] = (mat[i][k] * b - mat[j][k] * a) % mod;
      }
      ans = ans * ni(b) % mod;
    }
  }
  for (int i = 0; i < c1; i++) ans = (ans * mat[i][i]) % mod;
  printf("%I64d\n", (ans + mod) % mod);
}
