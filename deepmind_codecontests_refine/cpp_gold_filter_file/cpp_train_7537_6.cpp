#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 5e2 + 5;
const double eps = 1e-9;
using namespace std;
int a[MAXN][MAXN], s[MAXN][MAXN], f[MAXN][MAXN];
int R[MAXN], R2[MAXN], g[MAXN][MAXN];
long long h[MAXN][MAXN];
void func(int &x, long long &y, int a, int b) {
  if (a > x)
    x = a, y = b;
  else if (a == x)
    y += b;
}
int main() {
  int n, m, r;
  scanf("%d", &(n)), scanf("%d", &(m)), scanf("%d", &(r));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &(a[i][j]));
      s[i][j] = s[i][j - 1] + a[i][j];
    }
  for (int i = 0, j = r; i <= r; R[i++] = j)
    for (; i * i + j * j > r * r; j--)
      ;
  for (int i = 0; i <= 2 * r; i++)
    for (int j = max(i - r, 0); j <= i && j <= r; j++)
      R2[i] = max(R2[i], R[j] + R[i - j] + 1);
  memset(g, 192, sizeof g);
  for (int i = r + 1; i + r <= n; i++)
    for (int j = r + 1; j + r <= m; j++) {
      f[i][j] = s[i][j + r] - s[i][j - r - 1];
      for (int k = 1; k <= r; k++)
        f[i][j] += s[i + k][j + R[k]] - s[i + k][j - R[k] - 1] +
                   s[i - k][j + R[k]] - s[i - k][j - R[k] - 1];
      g[i][j] = g[i][j - 1], h[i][j] = h[i][j - 1];
      func(g[i][j], h[i][j], f[i][j], 1);
    }
  int ans1 = 0;
  long long ans2 = 0;
  for (int i = r + 1; i + r <= n; i++)
    for (int j = r + 1; j + r <= m; j++)
      for (int k = r + 1, p; k <= i + 2 * r && k <= n; k++)
        if (i - k > 2 * r)
          func(ans1, ans2, f[i][j] + g[k][m - r], h[k][m - r]);
        else if (j - R2[abs(k - i)] > r)
          func(ans1, ans2, f[i][j] + g[k][j - R2[abs(k - i)]],
               h[k][j - R2[abs(k - i)]]);
  printf("%d %I64d\n", ans1, ans2);
  return 0;
}
