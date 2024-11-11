#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'W') {
        if (a[i][j - 1] == 'P' or a[i][j + 1] == 'P' or a[i + 1][j] == 'P' or
            a[i - 1][j] == 'P')
          count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
