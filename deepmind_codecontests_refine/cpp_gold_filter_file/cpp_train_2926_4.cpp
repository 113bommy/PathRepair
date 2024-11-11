#include <bits/stdc++.h>
using namespace std;
const int N = 300000, C = 19;
int n, a[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i + n] = a[i + 2 * n] = a[i];
  }
}
int lg[N + 9];
int l[N + 9][C], r[N + 9][C];
int pl[N + 9][C], pr[N + 9][C];
void Get_plr() {
  if (n == 1) return;
  for (int i = 2; i <= n * 3; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n * 3; ++i) {
    l[i][0] = max(i - a[i], 1);
    r[i][0] = min(i + a[i], n * 3);
    pl[i][0] = pr[i][0] = i;
  }
  for (int i = 1; i < C; ++i)
    for (int j = 1; j + (1 << i) - 1 <= n * 3; ++j) {
      int x = pl[j][i - 1], y = pl[j + (1 << i - 1)][i - 1];
      pl[j][i] = l[x][0] < l[y][0] ? x : y;
      x = pr[j][i - 1];
      y = pr[j + (1 << i - 1)][i - 1];
      pr[j][i] = r[x][0] > r[y][0] ? x : y;
    }
}
int Query_pl(int u, int v) {
  int t = lg[v - u + 1], x = pl[u][t], y = pl[v - (1 << t) + 1][t];
  return l[x][0] < l[y][0] ? x : y;
}
int Query_pr(int u, int v) {
  int t = lg[v - u + 1], x = pr[u][t], y = pr[v - (1 << t) + 1][t];
  return r[x][0] > r[y][0] ? x : y;
}
void Get_lr() {
  if (n == 1) return;
  for (int i = 1; i < C; ++i)
    for (int j = 1; j <= n * 3; ++j) {
      int x = Query_pl(l[j][i - 1], r[j][i - 1]),
          y = Query_pr(l[j][i - 1], r[j][i - 1]);
      l[j][i] = min(l[x][i - 1], l[y][i - 1]);
      r[j][i] = max(r[x][i - 1], r[y][i - 1]);
    }
}
int ans[N + 9];
void Get_ans() {
  if (n == 1) return;
  for (int i = n + 1; i <= n << 1; ++i) {
    int x = i, y = i;
    ans[i - n] = 0;
    for (int j = C - 1; j >= 0; --j) {
      int le = min(l[x][j], l[y][j]), ri = max(r[x][j], r[y][j]);
      if (ri - le + 1 >= n) continue;
      x = Query_pl(le, ri);
      y = Query_pr(le, ri);
      ans[i - n] += 1 << j;
    }
    ++ans[i - n];
  }
}
void work() {
  Get_plr();
  Get_lr();
  Get_ans();
}
void outo() {
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
