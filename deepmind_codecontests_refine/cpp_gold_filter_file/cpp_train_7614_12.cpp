#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
int mat[MAXN][MAXN];
int rm[MAXN][MAXN];
int rn[MAXN];
int cn[MAXN];
int main() {
  int n, m, h;
  scanf("%d%d%d", &n, &m, &h);
  for (int j = 1; j <= m; ++j) {
    scanf("%d", &rn[j]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &cn[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &rm[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (rm[i][j] == 1) {
        mat[i][j] = min(cn[i], rn[j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}
