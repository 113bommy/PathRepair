#include <bits/stdc++.h>
using namespace std;
int g[1000006];
int sum[1000006][10];
int dfs(int k) {
  if (g[k] != -1) return g[k];
  int t = k, tmp = 1;
  while (t) {
    if (t % 10 != 0) tmp *= t % 10;
    t /= 10;
  }
  g[k] = dfs(tmp);
  return g[k];
}
int Q, l, r, k;
int main() {
  memset(g, -1, sizeof(g));
  for (int i = 1; i <= 10; ++i) g[i] = i;
  for (int i = 11; i <= 1000000; ++i) {
    dfs(i);
  }
  for (int i = 1; i <= 1000000; ++i) {
    for (int j = 1; j <= 9; ++j) {
      sum[i][j] = sum[i - 1][j];
    }
    sum[i][g[i]]++;
  }
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", sum[r][k] - sum[l - 1][k]);
  }
  return 0;
}
