#include <bits/stdc++.h>
using namespace std;
int n, m, v, q;
int x, y;
int matrix[11][11];
int prefixSum[11][11];
int main() {
  cin >> n >> m >> v >> q;
  for (int i = 1; i <= v; i++) {
    cin >> x >> y;
    matrix[x][y] = 1;
  }
  prefixSum[1][1] = matrix[1][1];
  for (int i = 2; i <= n; i++) {
    prefixSum[i][1] = prefixSum[i - 1][1] + matrix[i][1];
  }
  for (int i = 2; i <= m; i++) {
    prefixSum[1][i] = prefixSum[1][i - 1] + matrix[1][i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                        prefixSum[i - 1][j - 1] + matrix[i][j];
    }
  }
  int rez = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i; k <= n; k++) {
        for (int p = j; p <= m; p++) {
          int br = prefixSum[k][p];
          bool bound = false;
          if ((i - 1) >= 1) {
            br -= prefixSum[i - 1][p];
          } else {
            bound = true;
          }
          if ((j - 1) >= 1) {
            br -= prefixSum[k][j - 1];
          } else {
            bound = true;
          }
          if (!bound) br += prefixSum[i - 1][j - 1];
          if (br >= q) rez++;
        }
      }
    }
  }
  cout << rez << "\n";
}
