#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * c != b * d) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int res[a][b];
      int start = 0, end = d - 1;
      for (int col = 0; col < b; col++) {
        for (int row = 0; row < a; row++) {
          if (start <= end) {
            if (row >= start && row <= end) {
              res[row][col] = 1;
            } else
              res[row][col] = 0;
          } else {
            if (row > end && row < start) {
              res[row][col] = 0;
            } else
              res[row][col] = 1;
          }
        }
        start = end + 1;
        end = (start + d - 1) % a;
      }
      for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
          cout << res[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
}
