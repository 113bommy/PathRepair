#include <bits/stdc++.h>
using namespace std;
int n, tot, wh = 1;
char s[1000005];
int type[1000005], zhi[1000005], lc[1000005], rc[1000005];
int f[1000005][3];
void build(int &x) {
  x = ++tot;
  if (s[wh] == '(') {
    wh++;
    build(lc[x]);
    wh++;
    if (s[wh] == '&')
      type[x] = 1;
    else if (s[wh] == '|')
      type[x] = 2;
    else if (s[wh] == '^')
      type[x] = 3;
    wh++;
    build(rc[x]);
    wh++;
  } else if (s[wh] == '0' || s[wh] == '1' || s[wh] == '?') {
    type[x] = 0;
    if (s[wh] == '0')
      zhi[x] = 0;
    else if (s[wh] == '1')
      zhi[x] = 1;
    else
      zhi[x] = 2;
  }
}
void dfs(int x) {
  if (type[x] == 0) {
    if (zhi[x] == 0)
      f[x][0] = 1;
    else if (zhi[x] == 1)
      f[x][1] = 1;
    else
      f[x][2] = 1;
    return;
  }
  dfs(lc[x]);
  dfs(rc[x]);
  int l = lc[x], r = rc[x];
  for (int i = 0; i < 3; i++) {
    if (!f[l][i]) continue;
    int z1, f1;
    if (i == 0)
      z1 = 0, f1 = 0;
    else if (i == 1)
      z1 = 1, f1 = 1;
    else
      z1 = 0, f1 = 1;
    for (int j = 0; j < 3; j++) {
      if (!f[r][j]) continue;
      int z2, f2;
      if (j == 0)
        z2 = 0, f2 = 0;
      else if (j == 1)
        z2 = 1, f2 = 1;
      else
        z2 = 0, f2 = 1;
      if (type[x] == 1) {
        int t1 = z1 & z2, t2 = f1 & f2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
        t1 = z1 & f2, t2 = f1 & z2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
      } else if (type[x] == 2) {
        int t1 = z1 | z2, t2 = f1 | f2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
        t1 = z1 & f2, t2 = f1 | z2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
      } else if (type[x] == 3) {
        int t1 = z1 ^ z2, t2 = f1 ^ f2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
        t1 = z1 ^ f2, t2 = f1 ^ z2;
        if (t1 == t2)
          f[x][t1] = 1;
        else
          f[x][2] = 1;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int root;
  build(root);
  dfs(root);
  if (f[root][2])
    puts("YES");
  else
    puts("NO");
  return 0;
}
