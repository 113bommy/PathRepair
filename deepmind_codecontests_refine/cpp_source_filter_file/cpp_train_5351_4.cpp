#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s1 = 0, s2 = 0;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        s1++;
        break;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (a[j][i] == 'S') {
        s2++;
        break;
      }
    }
  s1 = s1 * s2;
  cout << n * m - s1 << "\n";
  return 0;
}
