#include <bits/stdc++.h>
using namespace std;
char mx[(1 << 19)][19], w[(1 << 19)];
int mxIndex[(1 << 19)][19];
int n, query;
void rmqinit() {
  int i, j, m, t;
  memset(mx, 0, sizeof(mx));
  for (i = 0; i < n; i++) {
    mx[i][0] = w[i];
    mxIndex[i][0] = i;
  }
  m = (int)(log((double)n) / log(2.0));
  for (j = 1; j <= m; j++) {
    t = 1 << (j - 1);
    for (i = 0; i + t <= n; i++) {
      mx[i][j] =
          (mx[i][j - 1] > mx[i + t][j - 1] ? mx[i][j - 1] : mx[i + t][j - 1]);
      mxIndex[i][j] = (w[mxIndex[i][j - 1]] >= w[mxIndex[i + t][j - 1]]
                           ? mxIndex[i][j - 1]
                           : mxIndex[i + t][j - 1]);
    }
  }
}
int rmq(int l, int r) {
  int m = (int)(log(double(r - l + 1)) / log(2.0)), t2, index2;
  t2 =
      (mx[l][m] > mx[r - (1 << m) + 1][m] ? mx[l][m] : mx[r - (1 << m) + 1][m]);
  index2 = w[mxIndex[l][m]] >= w[mxIndex[r - (1 << m) + 1][m]]
               ? mxIndex[l][m]
               : mxIndex[r - (1 << m) + 1][m];
  return index2;
}
int main() {
  int i, idx;
  while (scanf("%s", w) != EOF) {
    n = strlen(w);
    idx = -1;
    rmqinit();
    while (idx < n) {
      idx = rmq(idx + 1, n - 1);
      if (idx == n - 1) {
        printf("%c", w[idx]);
        break;
      }
      printf("%c", w[idx]);
    }
    puts("");
  }
  return 0;
}
