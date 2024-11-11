#include <bits/stdc++.h>
using namespace std;
int M[100][100];
int Q[10000][4];
int main() {
  int n, m, q, c, i, j;
  while (scanf("%d %d %d", &n, &m, &q) == 3) {
    memset(M, 0, sizeof M);
    for (int k = 0; k < q; ++k) {
      scanf("%d", &Q[k][0]);
      switch (Q[k][0]) {
        case 1:
          scanf("%d", &Q[k][1]);
          break;
        case 2:
          scanf("%d", &Q[k][1]);
          break;
        case 3:
          scanf("%d %d %d", &Q[k][1], &Q[k][2], &Q[k][3]);
          break;
      }
    }
    for (int k = q - 1; k >= 0; --k) {
      switch (Q[k][0]) {
        case 1:
          i = Q[k][1] - 1;
          swap(M[i][m - 1], M[i][0]);
          for (int z = n - 1; z > 1; --z) swap(M[i][z], M[i][z - 1]);
          break;
        case 2:
          j = Q[k][1] - 1;
          swap(M[n - 1][j], M[0][j]);
          for (int z = m - 1; z > 1; --z) swap(M[z][j], M[z - 1][j]);
          break;
        case 3:
          M[Q[k][1] - 1][Q[k][2] - 1] = Q[k][3];
          break;
      }
    }
    for (i = 0; i < n; ++i) {
      printf("%d", M[i][0]);
      for (j = 1; j < m; ++j) printf(" %d", M[i][j]);
      puts("");
    }
  }
  return 0;
}
