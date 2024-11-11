#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, ans = 0;
int a[200][200];
char b[200][200];
int k, t;
char ch;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> b[i][j];
  for (i = n; i >= 1; i--)
    for (j = m; j >= 1; j--)
      if (b[i][j] == 'W') {
        int dif = 1 - a[i][j];
        if (dif == 0) continue;
        for (k = i; k >= 1; k--)
          for (t = j; t >= 1; t--) a[k][t] += dif;
        ans++;
      } else {
        int dif = -1 - a[i][j];
        if (dif == 0) continue;
        for (k = i; k >= 1; k--)
          for (t = j; t >= 1; t--) a[k][t] += dif;
        ans++;
      }
  cout << ans;
  return 0;
}
