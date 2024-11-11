#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  string a[100];
  int s[100][100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'W')
        s[i][j] = 1;
      else
        s[i][j] = -1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      if (s[i][j] != 0) {
        ans = ans + 1;
        for (int k = 0; k <= i; k++)
          for (int l = 0; l <= j; l++) s[k][l] -= s[i][j];
      }
  cout << ans << endl;
}
