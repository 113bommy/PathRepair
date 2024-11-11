#include <bits/stdc++.h>
using namespace std;
int n, m, k, cur, ans[2005], L[2005][2005], R[2005][2005], f[2005][2005],
    X[2005], Y[2005];
bool ban[2005][2005];
char c[2005];
struct Stack {
  int q[2005], v[2005], h, t;
  void clear() { h = 0, t = -1; }
  void push(int i, int x) {
    while (h <= t && v[t] >= x) t--;
    q[++t] = i, v[t] = x;
  }
  int top(int d) {
    while (q[h] < d) h++;
    return v[h];
  }
} Sl, Sr;
bool check(int u, int j) {
  Sl.clear(), Sr.clear();
  for (int i = u; i <= n; i++) {
    if (ban[i][j]) return 0;
    Sl.push(i, j - L[i][j]), Sr.push(i, R[i][j] - i);
    if (i >= u + cur && Sl.top(i - cur) + Sr.top(i - cur) + 1 > cur)
      return cur++, 1;
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", c + 1);
    for (int j = 1; j <= m; j++)
      if (c[j] == 'X') ban[i][j] = 1;
  }
  for (int i = 1; i <= k; i++) scanf("%d%d", &X[i], &Y[i]), ban[X[i]][Y[i]] = 1;
  for (int i = 1; i <= n; i++) ban[i][0] = ban[i][m + 1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (!ban[i][j])
        cur = max(
            cur,
            f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1);
    for (int j = 1; j <= m; j++) L[i][j] = ban[i][j - 1] ? j : L[i][j - 1];
    for (int j = m; j >= 1; j--) R[i][j] = ban[i][j + 1] ? j : R[i][j + 1];
  }
  ans[k] = cur;
  for (int t = k; t >= 1; t--) {
    ban[X[t]][Y[t]] = 0;
    for (int j = 1, i = X[t]; j <= m; j++)
      L[i][j] = ban[i][j - 1] ? j : L[i][j - 1];
    for (int j = m, i = X[t]; j >= 1; j--)
      R[i][j] = ban[i][j + 1] ? j : R[i][j + 1];
    int u = X[t];
    while (u > 1 && !ban[u - 1][Y[t]]) u--;
    while (check(u, Y[t]))
      ;
    ans[t - 1] = cur;
  }
  for (int i = 1; i <= k; i++) printf("%d\n", ans[i]);
}
