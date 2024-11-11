#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m, i, j;
  cin >> n >> m;
  char a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '.') a[i][j] = 'D';
    }
  }
  bool poss = true;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        if (i - 1 >= 0) {
          if (a[i - 1][j] == 'W') poss = false;
        }
        if (j - 1 >= 0) {
          if (a[i][j - 1] == 'W') poss = false;
        }
        if (j + 1 < m) {
          if (a[i][j + 1] == 'W') poss = false;
        }
        if (i + 1 < n) {
          if (a[i + 1][j] == 'W') poss = false;
        }
      }
    }
  }
  if (poss) {
    cout << "Yes\n";
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  } else
    cout << "No\n";
}
