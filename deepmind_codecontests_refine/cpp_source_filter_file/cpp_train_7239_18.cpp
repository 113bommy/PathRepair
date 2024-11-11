#include <bits/stdc++.h>
using namespace std;
struct edge {
  int l, h, a;
  edge(int _l = 0, int _h = 0, int _a = 0) {
    l = _l;
    h = _h;
    a = _a;
  }
};
int n, m;
edge matr[6][6];
int dp[6][6][26][21][16][11][6];
bool iscapable(int s, int t, int fl) {
  return matr[s][t].l <= fl && fl <= matr[s][t].h;
}
int func(int id, int jd, int *f) {
  for (int i = 0; i + 1 < n; i++) {
    if (f[i] >= 5 * (n - i - 1)) return -2;
  }
  if (id == n - 1) return 0;
  if (dp[id][jd][f[0]][f[1]][f[2]][f[3]][f[4]] == -1) {
    int *p = &dp[id][jd][f[0]][f[1]][f[2]][f[3]][f[4]], t;
    *p = -2;
    if (jd == n - 1) {
      if (iscapable(id, jd, f[id])) {
        if (f[id] == 0)
          *p = 0;
        else
          *p = matr[id][jd].a + f[id] * f[id];
        t = f[id];
        f[id] = 0;
        if (func(id + 1, id + 1, f) == -2)
          *p = -2;
        else
          *p += func(id + 1, id + 1, f);
        f[id] = t;
      } else {
        *p = -2;
      }
    } else {
      for (int i = 0; i <= f[id]; i++) {
        if (iscapable(id, jd, i)) {
          int v;
          if (i == 0)
            v = 0;
          else
            v = matr[id][jd].a + i * i;
          f[jd] += i;
          f[id] -= i;
          if (func(id, jd + 1, f) == -2)
            v = -2;
          else
            v += func(id, jd + 1, f);
          f[jd] -= i;
          f[id] += i;
          if (v > *p) *p = v;
        }
      }
    }
  }
  return dp[id][jd][f[0]][f[1]][f[2]][f[3]][f[4]];
}
int main() {
  int s, f, l, h, a;
  int i;
  int fl[10];
  scanf("%d", &n);
  m = n * (n - 1) / 2;
  for (i = 0; i < m; i++) {
    scanf("%d%d%d%d%d", &s, &f, &l, &h, &a);
    s--;
    f--;
    matr[s][f] = edge(l, h, a);
  }
  for (i = 0; i < 10; i++) {
    fl[i] = 0;
  }
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < 26; i++) {
    fl[0] = i;
    if (func(0, 1, fl) != -2) break;
  }
  if (i == 26)
    printf("-1 -1\n");
  else
    printf("%d %d\n", i, func(0, 1, fl));
  return 0;
}
