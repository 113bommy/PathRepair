#include <bits/stdc++.h>
using namespace std;
int col[2005][1005], ans, a, b, m, u[100005], v[100005], d[2005];
int main() {
  scanf("%d%d%d", &a, &b, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", u + i, v + i), v[i] += a, d[u[i]]++, d[v[i]]++;
  for (int i = 1; i <= a + b; i++) ans = max(ans, d[i]);
  for (int i = 1; i <= m; i++) {
    int c1, c2;
    for (c1 = 1; c1 <= ans; c1++)
      if (!col[u[i]][c1]) break;
    for (c2 = 1; c2 <= ans; c2++)
      if (!col[v[i]][c2]) break;
    col[u[i]][c1] = v[i];
    col[v[i]][c2] = u[i];
    if (c1 == c2) continue;
    for (int c0 = c2, x = v[i]; x; x = col[x][c0], c0 ^= c1 ^ c2)
      swap(col[x][c1], col[x][c2]);
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= ans; j++)
      if (col[u[i]][j] == v[i]) {
        printf("%d ", j);
        break;
      }
  return 0;
}
