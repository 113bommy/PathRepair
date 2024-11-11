#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int numWhite = 0;
    char arr[n][m];
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) {
        cin >> arr[j][k];
        numWhite += (arr[j][k] == '.');
      }
    if (x * 2 <= y) {
      cout << numWhite * x << endl;
      continue;
    }
    int big_tiles = 0;
    int used[n][m];
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) used[j][k] = 0;
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m - 1; k++) {
        if (arr[j][k] == '.' && arr[j][k + 1] == '.' && !used[j][k]) {
          used[j][k] = 1;
          used[j][k + 1] = 1;
          big_tiles++;
        }
      }
    cout << (numWhite - 2 * big_tiles) * x + big_tiles * y << endl;
  }
}
