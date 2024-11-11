#include <bits/stdc++.h>
using namespace std;
struct EDGE {
  int x, y;
  EDGE(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
} e[7 * 7];
int en, ex[8][8], qq[100010], qn;
vector<int> ee[100010];
bool hh(int x, int y) {
  for (int i = 0; i < (((int)(ee[x]).size())); ++i) {
    if (ee[x][i] == y) return 1;
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n <= 7) {
    for (int i = (1); i < (n + 1); ++i)
      for (int j = (i + 1); j < (n + 1); ++j) e[en++] = EDGE(i, j);
    for (int i = 0; i < (m); ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      ex[x][y] = ex[y][x] = 1;
    }
    for (int i = 0; i < (1 << en); ++i) {
      int j, cnt = 0, deg[8] = {};
      for (j = 0; j < en; j++) {
        if (((i >> j) & 1)) {
          cnt++;
          if (ex[e[j].x][e[j].y]) break;
          deg[e[j].x]++;
          deg[e[j].y]++;
        }
      }
      if (j == en && cnt == m) {
        int k;
        for (int k = 1; k <= n; k++) {
          if (deg[k] > 2) break;
        }
        if (k > n) {
          for (k = 0; k < en; k++) {
            if ((i >> k) & 1) printf("%d %d\n", e[k].x, e[k].y);
          }
          return 0;
        }
      }
    }
    puts("-1");
  } else {
    for (int i = 0; i < (m); ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      ee[x].push_back(y);
      ee[y].push_back(x);
    }
    for (int i = 0; i < (n); ++i) qq[i] = i + 1;
    while (1) {
      random_shuffle(qq, qq + n);
      qq[n] = qq[0];
      int i = 0;
      for (i = 0; i < m; i++) {
        if (hh(qq[i], qq[i + 1])) break;
      }
      if (i == m) {
        for (int i = 0; i < (m); ++i) printf("%d %d\n", qq[i], qq[i + 1]);
        return 0;
      }
    }
  }
  return 0;
}
