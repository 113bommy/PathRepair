#include <bits/stdc++.h>
using namespace std;
int fa[9090909 * 2];
int ud[9090909 * 2];
int os[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
inline int enc(int x, int y) { return x * 6006 + y; }
int gf(int a) {
  int f = a;
  while (fa[f] != f) f = fa[f];
  while (a != f) {
    int o = fa[a];
    fa[a] = f;
    a = o;
  }
  return f;
}
void merge(int a, int b) {
  a = gf(a), b = gf(b);
  fa[a] = b;
}
int s0[8], s1[8], n0, n1;
int main() {
  int r, c, n;
  scanf("%d%d%d", &r, &c, &n);
  for (int i = 0; i < 9090909 * 2; i++) fa[i] = i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (ud[enc(x, y)]) continue;
    int en = enc(x, y);
    n0 = n1 = 0;
    for (int j = 0; j < 8; j++) {
      int dx = x + os[j][0];
      int dy = y + os[j][1];
      int ed = enc(dx, dy + (dy == 0 ? c * 2 : 0));
      if (ud[ed]) s0[n0++] = gf(ed);
      ed = enc(dx, dy + c - (dy == c + 1 ? 2 * c : 0));
      if (ud[ed]) s1[n1++] = gf(ed);
    }
    int ic = c == 1;
    for (int j = 0; j < n0 && !ic; j++)
      for (int k = 0; k < n1 && !ic; k++)
        if (s0[j] == s1[k]) ic = 1;
    if (ic) continue;
    for (int j = 0; j < n0; j++) merge(s0[j], en);
    ud[en] = 1;
    en = enc(x, y + c);
    for (int j = 0; j < n1; j++) merge(s1[j], en);
    ud[en] = 1;
    ans++;
  }
  printf("%d", ans);
  return 0;
}
