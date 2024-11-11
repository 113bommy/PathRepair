#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int k, t;
  cin >> t;
  for (k = 0; k < t; k++) {
    long long int n, i, j, c = 0, d = 0, m;
    cin >> n >> m;
    char a[n][m];
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (i == n) {
          if (a[i][j] == 'D') c++;
        }
        if (j == m) {
          if (a[i][j] == 'R') d++;
        }
      }
    }
    cout << c + d << "\n";
  }
  return 0;
}
