#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  char q[n + 1][m + 1];
  q[0][0] = '.';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> q[i][j];
    }
  }
  long long c = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (q[i][j] == 'P' && q[i][j + 1] == 'W' ||
          q[i][j] == 'W' && q[i][j + 1] == 'P') {
        c++;
        q[i][j + 1] = '.';
        q[i][j] = '.';
      }
      if (q[i][j] == 'P' && q[i - 1][j] == 'W' ||
          q[i][j] == 'W' && q[i - 1][j] == 'P') {
        c++;
        q[i][j] = '.';
        q[i - 1][j] = '.';
      }
    }
  }
  cout << c << endl;
  return 0;
}
