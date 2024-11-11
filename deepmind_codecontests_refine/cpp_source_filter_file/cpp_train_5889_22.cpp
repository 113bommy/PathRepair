#include <bits/stdc++.h>
using namespace std;
int dim[1001][1001];
int hori[1001][1001];
int verti[1001][1001];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> dim[i][j];
      hori[i][j] += dim[i][j];
      verti[j][i] += dim[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      hori[i][j] = hori[i][j] + hori[i][j - 1];
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      verti[j][i] = verti[j][i] + verti[j][i - 1];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!dim[i][j]) {
        if (hori[i][j] != 0) {
          count++;
        }
        if (hori[i][m - 1] - hori[i][j] != 0) {
          count++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!dim[j][i]) {
        if (verti[i][j] != 0) {
          count++;
        }
        if (verti[i][n - 1] - verti[i][j] != 0) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}
