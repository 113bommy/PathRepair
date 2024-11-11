#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
double d[maxn][maxn][2][2];
bool vis[maxn][maxn][2][2];
int n, h, x[maxn], L[maxn], R[maxn];
double p;
double dp(int l, int r, int a, int b) {
  double& ans = d[l][r][a][b];
  if (vis[l][r][a][b]) return ans;
  vis[l][r][a][b] = 1;
  if (l > r) return 0;
  ans += p / 2 * (min(h, x[l] - x[l - 1] - a * h) + dp(l + 1, r, 0, b));
  ans += (1 - p) / 2 * (min(h, x[r + 1] - x[r] - b * h) + dp(l, r - 1, a, 0));
  int tr = min(r, R[l]);
  int tl = max(l, L[r]);
  if (tl == l)
    ans += p / 2 * (x[r] - x[tl] + min(h, x[tl] - x[tl - 1] - a * h));
  else
    ans += p / 2 * (x[r] - x[tl] + h + dp(l, tl - 1, a, 1));
  if (tr == r)
    ans += (1 - p) / 2 * (x[tr] - x[l] + min(h, x[tr + 1] - x[tr] - b * h));
  else
    ans += (1 - p) / 2 * (x[tr] - x[l] + h + dp(tr + 1, r, 1, b));
  return ans;
}
int main() {
  scanf("%d %d %lf", &n, &h, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", x + i);
  sort(x + 1, x + 1 + n);
  x[0] = x[1] - 2 * h;
  x[n + 1] = x[n] + 2 * h;
  L[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (x[i] - x[i - 1] >= h)
      L[i] = i;
    else
      L[i] = L[i - 1];
  }
  R[n] = n;
  for (int i = n - 1; i >= 1; --i) {
    if (x[i + 1] - x[i] >= h)
      R[i] = i;
    else
      R[i] = R[i + 1];
  }
  memset(vis, 0, sizeof vis);
  printf("%.9lf\n", dp(1, n, 0, 0));
  return 0;
}
