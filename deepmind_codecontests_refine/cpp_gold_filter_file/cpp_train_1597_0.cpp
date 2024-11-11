#include <bits/stdc++.h>
int n, l, k;
bool vis[200][201][201] = {{{0}}};
double rcd[200][201][201];
struct my_struct {
  bool operator<(const my_struct &c) const { return st > c.st; }
  int p, st;
} con[200];
int Min(int a, int b) { return a < b ? a : b; }
double dp(int t, int wl, int sp) {
  if (t == n) {
    if (wl >= l)
      return 1;
    else
      return 0;
  }
  if (vis[t][wl][sp]) return rcd[t][wl][sp];
  double win = 0;
  if (con[t].st == -1) {
    win += ((double)100 - con[t].p) / 100 * dp(t + 1, wl, sp);
    if (sp > 0) win += (double)con[t].p / 100 * dp(t + 1, wl + 1, sp - 1);
  } else {
    win += ((double)100 - con[t].p) / 100 * dp(t + 1, wl, sp);
    win += (double)con[t].p / 100 * dp(t + 1, wl + 1, Min(200, sp + con[t].st));
  }
  vis[t][wl][sp] = 1;
  return rcd[t][wl][sp] = win;
}
int main() {
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 0; i < n; i++) scanf("%d", &con[i].p);
  for (int i = 0; i < n; i++) scanf("%d", &con[i].st);
  std::sort(con, con + n);
  double ans = dp(0, 0, k);
  printf("%.12lf\n", ans);
}
