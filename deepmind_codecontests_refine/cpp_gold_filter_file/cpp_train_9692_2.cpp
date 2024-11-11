#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  char c[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == 'B') {
        int pos = j;
        while (pos <= m && c[i][pos] == 'B') ++pos;
        if (pos == j)
          cout << i << " " << j;
        else {
          pos = (pos - j) / 2;
          cout << i + pos << " " << j + pos;
        }
        return 0;
      }
    }
  }
  return 0;
}
