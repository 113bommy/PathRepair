#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long m;
  cin >> n >> m;
  bool arr[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) arr[i][j] = false;
  long sol = -1;
  for (long i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    arr[x - 1][y - 1] = true;
    bool ans = false;
    if (ans) continue;
    for (int j = x - 3; j < x; j++) {
      for (int k = y - 3; k < y; k++) {
        if (j < 0 || k < 0 || j + 2 >= n || k + 2 >= n) continue;
        bool val = true;
        for (int a = 0; a < 3; a++) {
          for (int b = 0; b < 3; b++) {
            val = val && arr[j + a][k + b];
          }
        }
        ans = ans || val;
      }
    }
    if (ans) {
      sol = i + 1;
    }
  }
  cout << sol << endl;
  return 0;
}
