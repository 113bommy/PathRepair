#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[3][3][77977 << 2], a[3][3];
inline void add(int &a, int b) {
  a += b;
  if (a >= 777777777) a -= 777777777;
}
void up(int id) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) f[i][j][id] = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (a[i][j]) {
        for (int ii = 0; ii < 3; ii++)
          if (f[ii][i][id << 1]) {
            for (int jj = 0; jj < 3; jj++)
              add(f[ii][jj][id],
                  1LL * f[ii][i][id << 1] * f[j][jj][id << 1 | 1] % 777777777);
          }
      }
}
void build(int L, int R, int id) {
  if (L == R) {
    for (int i = 0; i < 3; i++) f[i][i][id] = 1;
    return;
  }
  int md = (L + R) >> 1;
  build(L, md, id << 1);
  build(md + 1, R, id << 1 | 1);
  up(id);
}
void update(int L, int R, int id, int x, int v) {
  if (L == R) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) f[i][j][id] = 0;
    if (v)
      f[v - 1][v - 1][id] = 1;
    else
      for (int i = 0; i < 3; i++) f[i][i][id] = 1;
    return;
  }
  int md = (L + R) >> 1;
  if (x <= md)
    update(L, md, id << 1, x, v);
  else
    update(md + 1, R, id << 1 | 1, x, v);
  up(id);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  build(1, n, 1);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    update(1, n, 1, x, y);
    int rt = 0;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) add(rt, f[i][j][1]);
    printf("%d\n", rt);
  }
  return 0;
}
