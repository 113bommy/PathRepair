#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int a[62][62];
int mini[62][62];
int rou[62][62][62];
int main() {
  cout << setprecision(9);
  cin >> n >> m >> r;
  memset(mini, 0x3f, sizeof(mini));
  memset(rou, 0x3f, sizeof(rou));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cin >> a[j][k];
      }
    }
    for (int l = 0; l < n; l++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          a[j][k] = min(a[j][k], a[j][l] + a[l][k]);
        }
      }
    }
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) mini[j][k] = min(mini[j][k], a[j][k]);
  }
  for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++) rou[0][j][k] = mini[j][k];
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          rou[i][j][k] = min(rou[i][j][k], rou[i - 1][j][l] + rou[0][l][k]);
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    int s, t, k;
    cin >> s >> t >> k;
    if (k >= 60)
      cout << rou[60][s - 1][t - 1] << endl;
    else
      cout << rou[k][s - 1][t - 1] << endl;
  }
  return 0;
}
