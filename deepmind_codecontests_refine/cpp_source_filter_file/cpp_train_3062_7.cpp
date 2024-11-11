#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[100005];
int A, B, L, R, x, p[805], dp[2][100005], n, m, i, j;
int cmp(node i, node j) { return i.y > j.y || i.y == j.y && i.x > j.x; }
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + m + 1, cmp);
  B = 1;
  A = 0;
  L = 1;
  for (i = 0; i <= 800; i++) p[i] = i * (i + 1) / 2;
  for (i = n; i >= 1; i--) {
    R = L - 1;
    while (a[R + 1].y == i) R++;
    x = L;
    dp[B][0] = dp[A][0] + 3 * (R - L + 1);
    for (j = 0; j <= min(800, n - i); j++) {
      while (x <= R && n - j <= a[x].x) x++;
      dp[B][0] = min(dp[B][0], dp[A][j] + p[j + 1] + 2 + 3 * (R - x + 1));
    }
    x = L;
    for (j = 1; j <= min(800, n - i + 1); j++) {
      while (x <= R && n - j < a[x].x) x++;
      dp[B][j] = min(dp[B][j - 1], dp[A][j - 1] + 3 * (R - x + 1));
    }
    swap(A, B);
    L = R + 1;
  }
  cout << dp[A][0];
  return 0;
}
