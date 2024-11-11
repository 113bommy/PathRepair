#include <bits/stdc++.h>
using namespace std;
int m[100][100];
int b[100][32];
int res[100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 32; ++j) {
      for (int k = 0; k < n; ++k) {
        if (m[i][k] != -1) {
          if (m[i][k] && (1 << j)) {
            b[i][j] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 31; ++j) {
      res[i] += (b[i][j] * (1 << j));
    }
  }
  cout << res[0];
  for (int i = 1; i < n; ++i) cout << ' ' << res[i];
  return 0;
}
