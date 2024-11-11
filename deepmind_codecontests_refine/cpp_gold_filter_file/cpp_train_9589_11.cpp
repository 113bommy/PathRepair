#include <bits/stdc++.h>
const int MAX_N = 1e5 + 5;
const int LOG = 20;
int n, l, p[MAX_N][LOG], h[MAX_N], ans;
long long s, w[MAX_N];
std::vector<int> adj[MAX_N];
int solve(int x) {
  w[x] += w[p[x][0]];
  int min = h[x] = h[p[x][0]] + 1;
  for (int y : adj[x]) min = std::min(min, solve(y));
  if (min == h[x]) {
    int cnt = 0, ind = x;
    for (int step = LOG - 1; step >= 0; --step)
      if (cnt + (1 << step) <= l && w[x] - w[p[ind][step]] <= s) {
        cnt += 1 << step;
        ind = p[ind][step];
      }
    min = h[ind];
    ++ans;
  }
  return min;
}
int main() {
  scanf("%d%d%lld", &n, &l, &s);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", w + i);
    if (w[i] > s) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 2; i <= n; ++i) {
    scanf("%d", p[i]);
    adj[p[i][0]].push_back(i);
  }
  for (int k = 1; k < LOG; ++k)
    for (int i = 1; i <= n; ++i) p[i][k] = p[p[i][k - 1]][k - 1];
  solve(1);
  printf("%d\n", ans);
  return 0;
}
