#include <bits/stdc++.h>
#pragma comment(linker, "/stack:100000000")
using namespace std;
const int MOD = 777777777;
const int N = 77777;
bool w[3][3];
int t[4 * N][3][3];
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= b;
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int(i) = 0; (i) < (3); (i)++) t[v][i][i] = 1;
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    for (int(i) = 0; (i) < (3); (i)++)
      for (int(j) = 0; (j) < (3); (j)++) {
        t[v][i][j] = 0;
        for (int(x) = 0; (x) < (3); (x)++)
          for (int(y) = 0; (y) < (3); (y)++) {
            if (w[x][y]) {
              add(t[v][i][j],
                  (long long)t[2 * v][i][x] * t[2 * v + 1][y][j] % MOD);
            }
          }
      }
  }
}
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    for (int(i) = 0; (i) < (3); (i)++)
      for (int(j) = 0; (j) < (3); (j)++) t[v][i][j] = 0;
    if (val >= 0) {
      t[v][val][val] = 1;
    } else {
      for (int(i) = 0; (i) < (3); (i)++) t[v][i][i] = 1;
    }
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(2 * v, tl, tm, pos, val);
    } else {
      update(2 * v + 1, tm + 1, tr, pos, val);
    }
    for (int(i) = 0; (i) < (3); (i)++)
      for (int(j) = 0; (j) < (3); (j)++) {
        t[v][i][j] = 0;
        for (int(x) = 0; (x) < (3); (x)++)
          for (int(y) = 0; (y) < (3); (y)++) {
            if (w[x][y]) {
              add(t[v][i][j],
                  (long long)t[2 * v][i][x] * t[2 * v + 1][y][j] % MOD);
            }
          }
      }
  }
}
int main() {
  int n, m, id, x;
  scanf("%d %d", &n, &m);
  for (int(i) = 0; (i) < (3); (i)++)
    for (int(j) = 0; (j) < (3); (j)++) {
      scanf("%d", &x);
      w[i][j] = x;
    }
  build(1, 0, n - 1);
  for (int(i) = 0; (i) < (m); (i)++) {
    scanf("%d %d", &id, &x);
    --id, --x;
    update(1, 0, n - 1, id, x);
    int res = 0;
    for (int(j) = 0; (j) < (3); (j)++)
      for (int(k) = 0; (k) < (3); (k)++) add(res, t[1][j][k]);
    printf("%d\n", res);
  }
  return 0;
}
