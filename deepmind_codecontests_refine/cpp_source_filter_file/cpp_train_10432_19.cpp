#include <bits/stdc++.h>
using namespace std;
char Map[2010][2010];
int N;
int cr[2010], cc[2010], ll[2010];
int main() {
  int i, j, k, sx, sy, ans = 0, x, y;
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) scanf("%s", Map[i] + 1);
  memset(cr, 0, sizeof(cr));
  memset(cc, 0, sizeof(cc));
  sx = 1, sy = N;
  for (i = 1; i <= N / 2; ++i) {
    int tt = cr[sx] + cc[sy];
    if (tt % 2 != Map[sx][sy] - '0') {
      ans++;
      cr[sx]++;
      cc[sy]++;
      ll[sx]++;
      ll[sy]++;
    }
    for (y = sy - 1; y > i; --y) {
      int tt = cr[sx] + cc[y];
      if (tt % 2 != Map[sx][y] - '0') {
        ans++;
        cr[sx]++;
        cc[y]++;
        ll[sx]++;
        ll[y]++;
      }
    }
    for (x = sx + 1; x < N + 1 - i; ++x) {
      int tt = cr[x] + cc[sy];
      if (tt % 2 != Map[x][sy] - '0') {
        ans++;
        cr[x]++;
        cc[sy]++;
        ll[x]++;
        ll[sy]++;
      }
    }
    sx++;
    sy--;
  }
  sx = N, sy = 1;
  memset(cr, 0, sizeof(cr));
  memset(cc, 0, sizeof(cc));
  for (i = 1; i <= N / 2; ++i) {
    int tt = cr[sx] + cc[sy];
    if (tt % 2 != Map[sx][sy] - '0') {
      ans++;
      cr[sx]++;
      cc[sy]++;
      ll[sx]++;
      ll[sy]++;
    }
    for (y = sy + 1; y < N + 1 - i; ++y) {
      int tt = cr[sx] + cc[y];
      if (tt % 2 != Map[sx][y] - '0') {
        ans++;
        cr[sx]++;
        cc[y]++;
        ll[sx]++;
        ll[y]++;
      }
    }
    for (x = sx - 1; x > i; --x) {
      int tt = cr[x] + cc[sy];
      if (tt % 2 != Map[x][sy] - '0') {
        ans++;
        cr[x]++;
        cc[sy]++;
        ll[x]++;
        ll[sy]++;
      }
    }
    sx--;
    sy++;
  }
  for (i = 1; i < N; ++i)
    if (ll[i] % 2 != Map[i][i] - '0') ans++;
  printf("%d\n", ans);
  return 0;
}
