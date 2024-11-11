#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050, maxm = 200050;
inline int read() {
  int s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
int n, m, Q;
struct edge {
  int x, y;
} e[maxm];
struct que {
  int id, l, r, s, t;
} qu[maxm];
int dp[maxn][maxn], ans[maxm];
bool cmpl(que q1, que q2) { return q1.l > q2.l; }
inline void chkmin(int &a, int b) { a = a < b ? a : b; }
signed main() {
  n = read();
  m = read();
  Q = read();
  for (int i = 1; i <= m; i++) {
    e[i].x = read();
    e[i].y = read();
  }
  for (int i = 1; i <= Q; i++) {
    qu[i].id = i;
    qu[i].l = read();
    qu[i].r = read();
    qu[i].s = read();
    qu[i].t = read();
  }
  sort(qu + 1, qu + 1 + Q, cmpl);
  memset(dp, 0x3f, sizeof(dp));
  int tim = m + 1;
  for (int i = 1; i <= Q; i++) {
    while (tim > qu[i].l) {
      tim--;
      int x = e[tim].x, y = e[tim].y;
      dp[x][y] = dp[y][x] = tim;
      for (int j = 1; j <= n; j++) {
        int xj = dp[x][j], yj = dp[y][j];
        chkmin(dp[x][j], yj);
        chkmin(dp[y][j], xj);
      }
    }
    if (dp[qu[i].s][qu[i].t] <= qu[i].r) {
      ans[qu[i].id] = 1;
    }
  }
  for (int i = 1; i <= Q; i++) {
    if (ans[i])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
