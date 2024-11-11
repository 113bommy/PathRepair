#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    int n, m, j;
    cin >> n >> m;
    char a[n + 1][m + 1];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int c = 0;
    for (i = 0; i < m - 1; i++) {
      if (a[n - 1][i] == 'D') c++;
    }
    for (i = 0; i < n - 1; i++) {
      if (a[i][m - 1] == 'R') c++;
    }
    cout << c << endl;
  }
  return 0;
}
