#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long mat[2 * n + 1][2 * n + 1];
  for (long long i = 0; i < 2 * n + 1; i++) {
    for (long long j = 0; j < 2 * n + 1; j++) {
      mat[i][j] = n - abs(n - i) - abs(n - j);
    }
  }
  for (long long i = 0; i < 2 * n + 1; i++) {
    for (long long j = 0; j < 2 * n + 1; j++) {
      if (mat[i][j] >= 0) {
        if (mat[i][j] != 0) cout << mat[i][j] << " ";
        if (mat[i][j] == 0 && j < n) {
          cout << mat[i][j] << " ";
        }
        if (mat[i][j] == 0 && j >= n) {
          cout << mat[i][j];
          continue;
        }
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
  return 0;
}
