#include <bits/stdc++.h>
using namespace std;
const int up = 300010;
struct eg {
  int u, v, nx, id;
  char x;
} gp[(up << 1) + 10];
int n, m, dm, st, cnt, hd[up + 10];
inline void psh(int u, int v, int id, char x) {
  ++cnt;
  gp[cnt].u = u, gp[cnt].v = v, gp[cnt].id = id, gp[cnt].x = x,
  gp[cnt].nx = hd[u], hd[u] = cnt;
};
char ans[up + 10];
bool bd[up + 10];
void dfs(int v, int &rs) {
  ++rs;
  bd[v] = 1;
  int i, j;
  for (i = hd[v]; i; i = gp[i].nx)
    if (!bd[gp[i].v]) {
      if (gp[i].x) ans[gp[i].id] = gp[i].x;
      dfs(gp[i].v, rs);
    }
};
void dfx(int v, int &rs) {
  ++rs;
  bd[v] = 1;
  int i, j;
  for (i = hd[v]; i; i = gp[i].nx) {
    if (gp[i].x)
      ans[gp[i].id] = gp[i].x == '+' ? '-' : '+';
    else if (!bd[gp[i].v])
      dfx(gp[i].v, rs);
  }
};
void cl() {
  int i, j, k, d, a, b;
  scanf("%d %d %d", &n, &m, &st);
  for (dm = cnt = 0, memset(hd, 0, sizeof(hd)), i = 0; i < m; ++i) {
    scanf("%d %d %d", &k, &a, &b);
    if (k == 1)
      psh(a, b, i, 0);
    else {
      psh(a, b, dm, '+'), psh(b, a, dm, '-');
      ++dm;
    }
  }
  memset(bd, 0, sizeof(bd)), memset(ans, 0, sizeof(ans));
  dfs(st, a = 0);
  printf("%d\n", a);
  for (i = 0; i < dm; ++i)
    if (!ans[i]) ans[i] = '-';
  for (i = 0; i < dm; putchar(ans[i++]))
    ;
  putchar('\n');
  memset(bd, 0, sizeof(bd)), memset(ans, 0, sizeof(ans));
  dfx(st, a = 0);
  printf("%d\n", a);
  for (i = 0; i < dm; ++i)
    if (!ans[i]) ans[i] = '-';
  for (i = 0; i < dm; putchar(ans[i++]))
    ;
  putchar('\n');
};
int main() {
  cl();
  return 0;
};
