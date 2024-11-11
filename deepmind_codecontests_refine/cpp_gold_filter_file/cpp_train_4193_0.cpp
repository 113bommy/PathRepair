#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char belt[n][m];
    int i, j;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) cin >> belt[i][j];
    int sum = 0;
    for (i = 0; i < n - 1; i++)
      if (belt[i][m - 1] == 'R') sum++;
    for (j = 0; j < m - 1; j++)
      if (belt[n - 1][j] == 'D') sum++;
    cout << sum << endl;
  }
  return 0;
}
