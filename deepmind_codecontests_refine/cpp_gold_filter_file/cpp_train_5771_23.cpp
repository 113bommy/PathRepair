#include <bits/stdc++.h>
using namespace std;
int dp[20];
int p[20], e[20];
int c[20];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d%d", &p[i], &e[i]);
  int minx = 1e9 + 10;
  for (int i = 0; i < (1 << n); ++i) {
    int cost = 0;
    int x = 0;
    for (int j = 0; j < n; ++j)
      if (i & (1 << j)) {
        cost += e[j];
        x++;
      }
    int top = n + 1;
    for (int j = 0; j < n; ++j)
      if (i & (1 << j) && p[j] <= x)
        top--;
      else if (!(i & (1 << j)) && p[j] + 1 < x)
        top--;
    if (top <= m) minx = min(minx, cost);
  }
  if (minx == 1e9 + 10)
    printf("-1\n");
  else
    printf("%d\n", minx);
}
