#include <bits/stdc++.h>
using namespace std;
void add(int& x, int y) {
  x += y;
  if (x >= 998244353) x -= 998244353;
}
int f[1010][1010], g[1010][1010];
int n, k;
int a[1010];
int solve(int dis) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) f[i][j] = g[i][j] = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1;
    while (a[i] - a[mx + 1] >= dis) mx++;
    for (int j = 2; j <= k; j++) f[i][j] = g[mx][j - 1];
    for (int j = 1; j <= k; j++) {
      g[i][j] = g[i - 1][j];
      add(g[i][j], f[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) add(ans, f[i][k]);
  return ans;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int N = 100000;
  int ans = 0;
  for (int i = 1; i <= N / (k - 1) + 5; i++) add(ans, solve(i));
  printf("%d\n", ans);
}
