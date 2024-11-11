#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, ct = 0, m, n, t, x, y, z;
  double a, b, c, d;
  char p, q, r, s;
  char gr[200][300];
  int ismarked[200][300];
  string str, s1, s2, s3;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> gr[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      p = gr[i][j];
      ct = 0;
      for (x = 0; x < n; x++) {
        if (gr[x][j] == p && x != i) {
          ct = 1;
          ismarked[x][j] = 1;
        }
      }
      for (y = 0; y < m; y++) {
        if (gr[i][y] == p && y != j) {
          ct = 1;
          ismarked[i][x] = 1;
        }
      }
      if (ct == 1) ismarked[i][j] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ismarked[i][j] == 0) {
        cout << gr[i][j];
      }
    }
  }
  return 0;
}
