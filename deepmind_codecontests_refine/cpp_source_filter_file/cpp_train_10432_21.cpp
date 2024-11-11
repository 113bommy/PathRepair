#include <bits/stdc++.h>
using namespace std;
int n, res;
char p[2005][2005];
int treev[2005][2005];
int trees[2005][2005];
int v[2005];
int s[2005];
void update(int x, int y) {
  x++;
  int x1 = x;
  y++;
  int y1 = y;
  v[x]++;
  s[y]++;
  while (x1 <= n) {
    trees[x1][y] += 1;
    x1 = x1 + (x1 & (-x1));
  }
  while (y1 <= n) {
    treev[y1][x] += 1;
    y1 = y1 + (y1 & (-y1));
  }
}
int query(int x, int y) {
  x++;
  int x1 = x;
  y++;
  int y1 = y;
  int sumv = 0;
  int sums = 0;
  while (x1 > 0) {
    sums = sums + trees[x1][y];
    x1 = x1 - (x1 & (-x1));
  }
  while (y1 > 0) {
    sums = sums + treev[y1][x];
    y1 = y1 - (y1 & (-y1));
  }
  if (x < y) return sums + v[x] - sumv;
  if (x > y) return sumv + s[y] - sums;
  if (x == y) return v[x] + s[y];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", p[i]);
  memset(treev, 0, sizeof treev);
  memset(trees, 0, sizeof trees);
  memset(v, 0, sizeof v);
  memset(s, 0, sizeof s);
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= n - 1 - i; j++) {
      int x = j;
      int y = i + j;
      int tr = query(x, y);
      if ((tr % 2 == 1 && p[x][y] == '0') || (tr % 2 == 0 && p[x][y] == '1')) {
        update(x, y);
        res++;
      }
      if (x == y) continue;
      x = i + j;
      y = j;
      tr = query(x, y);
      if ((tr % 2 == 1 && p[x][y] == '0') || (tr % 2 == 0 && p[x][y] == '1')) {
        update(x, y);
        res++;
      }
    }
  printf("%d\n", res);
  return 0;
}
