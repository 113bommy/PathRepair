#include <bits/stdc++.h>
const int MAX_N = 20;
int n, k, t;
int e[MAX_N + 1][MAX_N + 1];
int choosen[MAX_N + 1];
int mid;
int cnt;
void dfs(int x, int now_cost_sum) {
  if (now_cost_sum > mid) return;
  if (cnt >= t) return;
  if (x > n) {
    cnt++;
    return;
  }
  dfs(x + 1, now_cost_sum);
  for (int y = 1; y <= n && cnt < t; y++)
    if (!choosen[y] && e[x][y]) {
      choosen[y] = 1;
      dfs(x + 1, now_cost_sum + e[x][y]);
      choosen[y] = 0;
    }
}
int main() {
  scanf("%d%d%d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    int h, w, r;
    scanf("%d%d%d", &h, &w, &r);
    e[h][w] = r;
  }
  int low = 0, high = 1000 * n;
  while (low < high) {
    mid = (low + high) >> 1;
    cnt = 0;
    dfs(1, 0);
    if (cnt >= t)
      high = mid;
    else
      low = mid + 1;
  }
  printf("%d\n", low);
}
