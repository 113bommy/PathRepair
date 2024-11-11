#include <bits/stdc++.h>
using namespace std;
int n, l = 0;
int step[100001], in[100001], sum[100001], d[100001];
void dfs(int x, int v) {
  int i, j, k;
  if (!in[x]) {
    sum[x]++, in[x] = 1, step[x] += v, d[++l] = x;
  } else
    return;
  if (x * 2 <= 100001) dfs(x * 2, v + 1);
  if (x > 1) dfs(x / 2, v + 1);
}
void init() {
  int i, j, k, ans = 1000000007, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (i = 1; i <= l; i++) in[d[i]] = 0;
    l = 0;
    scanf("%d", &x);
    dfs(x, 0);
  }
  for (i = 1; i <= 100001; i++)
    if (sum[i] == n) ans = min(ans, step[i]);
  printf("%d\n", ans);
}
void work() { int i, j, k; }
int main() {
  init();
  work();
  return 0;
}
