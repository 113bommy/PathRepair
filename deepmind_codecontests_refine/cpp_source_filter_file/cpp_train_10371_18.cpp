#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
double p[100][100];
double w[100][100];
double e[100][100];
void dfs(int score, int l, int r, int rt) {
  if (l == r) {
    w[rt][l] = 1;
    e[rt][l] = score;
    return;
  }
  int mid = (l + r) >> 1;
  dfs(score / 2, l, mid, rt << 1);
  dfs(score / 2, mid + 1, r, rt << 1 | 1);
  for (int i = l; i <= mid; i++)
    for (int j = mid + 1; j <= r; j++)
      w[rt][i] += w[rt << 1][i] * w[rt << 1 | 1][j] * p[i][j];
  for (int i = mid + 1; i <= r; i++)
    for (int j = l; j <= mid; j++)
      w[rt][i] += w[rt << 1 | 1][i] * w[rt << 1][j] * p[i][j];
  for (int i = l; i <= mid; i++)
    for (int j = mid + 1; j <= r; j++)
      e[rt][i] =
          max(e[rt][i], w[rt][i] * score + e[rt << 1][i] + e[rt << 1 | 1][j]);
  for (int i = mid + 1; i <= r; i++)
    for (int j = l; j <= mid; j++)
      e[rt][i] =
          max(e[rt][i], w[rt][i] * score + e[rt << 1 | 1][i] + e[rt << 1][j]);
}
int main() {
  int n, t;
  cin >> n;
  n = 1 << n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) scanf("%d", &t), p[i][j] = 0.01 * t;
  }
  dfs(n / 2, 1, n, 1);
  printf("%.10lf", *max_element(e[1], e[1] + n + 1));
  return 0;
}
