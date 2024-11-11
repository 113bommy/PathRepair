#include <bits/stdc++.h>
using namespace std;
char b[110][110];
int vis[110][110];
int main() {
  int n, m;
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      for (k = 0; k < m; k++) {
        if (b[i][j] == b[i][k] && k != j) {
          vis[i][j] = 1;
          vis[i][k] = 1;
        }
      }
      for (k = 0; k < n; k++) {
        if (b[i][j] == b[k][j] && k != i) {
          vis[k][j] = 1;
          vis[i][j] = 1;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (vis[i][j] != 1) cout << b[i][j];
    }
  }
  printf("\n");
  return 0;
}
