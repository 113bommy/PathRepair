#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0 && a[i][j] != '-')
        a[i][j] = 'W';
      else if ((i + j) % 2 == 1 && a[i][j] != '-')
        a[i][j] = 'B';
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
