#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ab[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> ab[i][j];
  }
  int a, b;
  cin >> a >> b;
  int c, min = 10000007;
  for (int k = 0; k + a <= n; k++) {
    for (int l = 0; l + b <= m; l++) {
      c = 0;
      for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
          if (ab[k + i][l + j] == 1) {
            c++;
          }
        }
      }
      if (c < min) {
        min = c;
      }
    }
  }
  for (int k = 0; k + b <= n; k++) {
    for (int l = 0; l + a <= m; l++) {
      c = 0;
      for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
          if (ab[k + i][l + j] == 1) {
            c++;
          }
        }
      }
      if (c < min) {
        min = c;
      }
    }
  }
  cout << endl << min << endl;
  return 0;
}
