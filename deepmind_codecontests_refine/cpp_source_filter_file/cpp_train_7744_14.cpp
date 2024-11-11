#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T Read(T Type) {
  T x = 0, f = 1;
  char a = getchar();
  while (!('0' <= a && a <= '9')) {
    if (a == '-') f = -1;
    a = getchar();
  }
  while (('0' <= a && a <= '9')) {
    x = (x << 1) + (x << 3) + (a ^ '0');
    a = getchar();
  }
  return x * f;
}
const int MAXN = 4010, inf = 1000000000;
int sum[MAXN][MAXN], dp[MAXN][810];
inline int count(int i, int j) {
  return sum[i][i] - sum[i][j - 1] - sum[j - 1][i] + sum[j - 1][j - 1];
}
inline void dfs(int k, int l, int r, int opl, int opr) {
  if (l > r) return;
  int mid = l + r >> 1;
  int minl = inf, id;
  for (int i = opl; i <= min(opr, mid); i++) {
    int cur = dp[i - 1][k - 1] + count(mid, i);
    if (cur < minl) minl = cur, id = i;
  }
  dp[mid][k] = minl;
  dfs(k, l, mid - 1, opl, id);
  dfs(k, mid + 1, r, id, opr);
}
int main() {
  int n = Read(1), k = Read(1);
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= n; j++) {
      int v = Read(1);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v;
    }
  for (register int i = 1; i <= n; i++) dp[i][0] = inf;
  for (register int i = 1; i <= k; i++) dfs(i, 1, n, 1, n);
  printf("%intd", dp[n][k] / 2);
  return 0;
}
