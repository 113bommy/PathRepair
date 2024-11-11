#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, count = 0;
  char c;
  cin >> n;
  char v[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> c;
      v[i][j] = c;
    }
  }
  for (i = 1; i < n - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (v[i][j] == 'X') {
        if (v[i + 1][j + 1] == 'X' && v[i - 1][j - 1] == 'X' &&
            v[i + 1][j - 1] == 'X' && v[i - 1][j + 1] == 'X') {
          count++;
        }
      }
    }
  }
  cout << count;
  return 0;
}
