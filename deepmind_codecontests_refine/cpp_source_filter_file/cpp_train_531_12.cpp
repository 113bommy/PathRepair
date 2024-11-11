#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int f[105][105], s[105][105], fu[105][105];
void update() {
  for (int i = 0; i < k; i++) {
    s[i][0] = f[i][0];
    for (int j = 1; j < k; j++) s[i][j] = s[i][j - 1] + f[i][j];
  }
}
inline int cnt(int i, int j1, int j2) {
  int res = s[i][j2];
  if (j1 > 0) res -= s[i][j1 - 1];
  return res;
}
void go() {
  int c = k / 2;
  int bestf = 1000000;
  int besti, bestj;
  for (int i = 0; i < k; i++)
    for (int j = 0; j + m <= k; j++) {
      if (cnt(i, j, j + m - 1) == 0) {
        int q = abs(c - i) + fu[j][j + m - 1];
        if (q < bestf) {
          besti = i;
          bestj = j;
          bestf = q;
        }
      }
    }
  if (bestf == 1000000)
    printf("-1\n");
  else {
    printf("%d %d %d\n", besti + 1, bestj + 1, bestj + m);
    for (int j = bestj; j < bestj + m; j++) f[besti][j] = 1;
    update();
  }
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++)
    for (int j = i; j < k; j++) {
      int t = 0;
      for (int q = i; q <= j; q++) t += abs(k / 2 - q);
      fu[i][j] = t;
    }
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    go();
  }
}
int main() {
  solve();
  return 0;
}
