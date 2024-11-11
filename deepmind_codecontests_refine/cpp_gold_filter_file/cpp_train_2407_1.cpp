#include <bits/stdc++.h>
using namespace std;
int bo[1000000], boo[1000000], n, root, f[1000000], f1[1000000], len,
    hea[1000000], nex[1000000], wen[1000000];
struct arr {
  int x, y;
} a[1000000][2];
void add(int x, int y) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  hea[x] = len;
}
void dfs(int x, int y) {
  boo[x] = bo[x] > 1;
  for (int i = hea[x]; i; i = nex[i])
    if (wen[i] != y) {
      dfs(wen[i], x);
      if (bo[x] == 2 && boo[wen[i]] == 0) boo[x] = 0;
    }
}
void dfs1(int x, int y) {
  a[x][0] = {x, 0};
  a[x][1] = {0, 0};
  f1[x] = x;
  f[x] = boo[x];
  for (int i = hea[x]; i; i = nex[i]) {
    int z = wen[i];
    if (z != y) {
      dfs1(z, x);
      arr t = a[z][0];
      t.y += 1;
      if (f[z] + boo[x] > f[x]) {
        f[x] = f[z] + boo[x];
        f1[x] = f1[z];
      } else {
        if (f[z] + boo[x] == f[x] && boo[z] > 0 &&
            a[f1[x]][1].y + a[f1[x]][0].y <= a[f1[z]][1].y + a[f1[z]][0].y)
          f1[x] = f1[z];
      }
      if (a[x][0].y < t.y) {
        a[x][1] = a[x][0];
        a[x][0] = t;
      } else {
        if (a[x][1].y < t.y) a[x][1] = t;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
    bo[x]++;
    bo[y]++;
    if (bo[x] >= 3) root = x;
    if (bo[y] >= 3) root = y;
  }
  dfs(root, 0);
  int x, ans1, ans2, ans3, ans4;
  dfs1(root, 0);
  x = f1[root], ans1 = a[f1[root]][0].x, ans3 = a[f1[root]][1].x;
  dfs1(x, 0);
  ans2 = a[f1[x]][0].x, ans4 = a[f1[x]][1].x;
  printf("%d %d\n%d %d", ans1, ans2, ans3, ans4);
}
