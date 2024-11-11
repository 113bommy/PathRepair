#include <bits/stdc++.h>
using namespace std;
char **g;
int n, m;
struct nodes {
  nodes *u, *r, *d, *l;
  char dir;
};
nodes **dl;
template <class T>
void getarr(T **&a) {
  a = (T **)malloc((n + 10) * sizeof(T *));
  for (int i = 0; i < n + 10; i++) {
    a[i] = (T *)malloc((m + 10) * sizeof(T));
  }
}
void del(nodes *p) {
  p->u->d = p->d;
  p->d->u = p->u;
  p->r->l = p->l;
  p->l->r = p->r;
}
int to[300];
void init() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i != 0 && j != 0)
        dl[i][j].dir = to[g[i][j]];
      else
        dl[i][j].dir = -1;
      if (i > 0)
        dl[i][j].u = &dl[i - 1][j];
      else
        dl[i][j].u = &dl[n][j];
      if (j > 0)
        dl[i][j].l = &dl[i][j - 1];
      else
        dl[i][j].l = &dl[i][m];
      if (i < m)
        dl[i][j].d = &dl[i + 1][j];
      else
        dl[i][j].d = &dl[0][j];
      if (j < m)
        dl[i][j].r = &dl[i][j + 1];
      else
        dl[i][j].r = &dl[i][0];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '.') del(&dl[i][j]);
    }
  }
}
int solve(int x, int y) {
  nodes *ptr = &dl[x][y];
  int cc = 0;
  while (ptr->dir != -1) {
    del(ptr);
    cc++;
    switch (ptr->dir) {
      case 0:
        ptr = ptr->u;
        break;
      case 1:
        ptr = ptr->r;
        break;
      case 2:
        ptr = ptr->d;
        break;
      case 3:
        ptr = ptr->l;
        break;
    }
  }
  return cc;
}
int main() {
  to['U'] = 0;
  to['R'] = 1;
  to['D'] = 2;
  to['L'] = 3;
  scanf("%d%d", &n, &m);
  getarr(g);
  getarr(dl);
  for (int i = 1; i <= n; i++) {
    scanf("%s", g[i] + 1);
  }
  int ans1 = -1, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] != '.') {
        init();
        int ret = solve(i, j);
        if (ans1 < ret) {
          ans1 = ret;
          ans2 = 1;
        } else if (ans1 == ret) {
          ans2++;
        }
      }
    }
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
