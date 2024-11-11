#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  char c[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (c[i][j] == 'X' && c[i - 1][j - 1] == 'X' && c[i - 1][j + 1] == 'X' &&
          c[i + 1][j + 1] == 'X' && c[i + 1][j - 1] == 'X')
        ans++;
    }
  }
  cout << ans;
  return 0;
}
