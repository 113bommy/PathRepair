#include <bits/stdc++.h>
using namespace std;
const int N = 22, inf = 1e9 + 7;
int n, p, all, dp[1 << N], f[1 << N], ans[N][2];
struct node {
  int l, r, t, id;
  bool operator<(const node& u) const { return l < u.l; }
} a[N];
void dfs(int id, int s) {
  while (s) {
    ans[a[f[s]].id][0] = id;
    ans[a[f[s]].id][1] = dp[s] - a[f[s]].t;
    s -= (1 << f[s]);
  }
}
void out() {
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d%d\n", ans[i][0], ans[i][1]);
}
int main() {
  scanf("%d%d", &n, &p);
  all = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
    a[i].id = i, a[i].r += a[i].l - 1;
  }
  sort(a, a + n);
  dp[0] = 1;
  for (int s = 1, res; s <= all; s++) {
    res = inf;
    for (int i = 0; i < n; i++)
      if (s & (1 << i)) {
        int x = dp[s ^ (1 << i)], len = a[i].t;
        for (int j = 0; j < n; j++) {
          if (x >= a[j].l && x <= a[j].r) x = a[j].r + 1;
          if (x < a[j].l && x + len >= a[j].l && (s & (1 << j))) x = a[j].r + 1;
        }
        if (a[i].l > x + len && x + len < res) res = x + len, f[s] = i;
      }
    dp[s] = res;
  }
  if (p == 1)
    if (dp[all] < inf)
      dfs(1, all), out();
    else
      puts("NO");
  else {
    bool ff = 0;
    for (int s = 0; s <= all && !ff; s++)
      if (dp[s] < inf && dp[all ^ s] < inf) ff = 1, dfs(1, s), dfs(2, all ^ s);
    if (ff)
      out();
    else
      puts("NO");
  }
  return 0;
}
