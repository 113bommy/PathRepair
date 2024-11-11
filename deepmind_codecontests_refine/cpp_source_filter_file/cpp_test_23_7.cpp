#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int pos[N][N], ls[N], rs[N], siz[N];
int build(int l, int r) {
  if (l == r) return l;
  int x = pos[l][r];
  if (x - 1 >= l) ls[x] = build(l, x - 1);
  if (x + 1 <= r) rs[x] = build(x + 1, r);
  return x;
}
int n, m;
long long a[N], dp[N][N];
void dfs(int x) {
  siz[x] = 1;
  if (ls[x]) dfs(ls[x]), siz[x] += siz[ls[x]];
  if (rs[x]) dfs(rs[x]), siz[x] += siz[rs[x]];
  if ((!ls[x]) && (!rs[x])) return;
  if (!ls[x]) {
    for (int i = 0; i <= siz[rs[x]]; i++) {
      dp[x][i] = max(dp[x][i], dp[rs[x]][i] + (a[rs[x]] - a[x]) * i * (m - i));
      dp[x][i + 1] =
          max(dp[x][i + 1], dp[rs[x]][i] + (a[rs[x]] - a[x]) * i * (m - i));
    }
    return;
  }
  if (!rs[x]) {
    for (int i = 0; i <= siz[ls[x]]; i++) {
      dp[x][i] = max(dp[x][i], dp[ls[x]][i] + (a[ls[x]] - a[x]) * i * (m - i));
      dp[x][i + 1] =
          max(dp[x][i + 1], dp[ls[x]][i] + (a[ls[x]] - a[x]) * i * (m - i));
    }
    return;
  }
  for (int i = 0; i <= siz[ls[x]]; i++)
    for (int j = 0; j <= siz[rs[x]]; j++) {
      long long add =
          (a[ls[x]] - a[x]) * i * (m - i) + (a[rs[x]] - a[x]) * j * (m - j);
      dp[x][i + j] = max(dp[x][i + j], dp[ls[x]][i] + dp[rs[x]][j] + add);
      dp[x][i + j + 1] =
          max(dp[x][i + j + 1], dp[ls[x]][i] + dp[rs[x]][j] + add);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    pos[i][i] = i;
    for (int j = i + 1; j <= n; j++)
      pos[i][j] = a[pos[i][j - 1]] < a[j] ? pos[i][j - 1] : j;
  }
  build(1, n);
  dfs(pos[1][n]);
  printf("%d", dp[pos[1][n]][m]);
  return 0;
}
