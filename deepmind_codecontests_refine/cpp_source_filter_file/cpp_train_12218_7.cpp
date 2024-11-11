#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  char a[100][100];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int ii = i; ii < n; ii++) {
        for (int jj = j; jj < m; jj++) {
          bool pp = 1;
          for (int k = i; k <= ii; k++) {
            for (int kk = j; kk <= jj; kk++) {
              if (a[i][j] == '1') {
                pp = 0;
              }
            }
          }
          if (pp) {
            ans = max(ans, 2 * (ii - i + 1 + jj - j + 1));
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
