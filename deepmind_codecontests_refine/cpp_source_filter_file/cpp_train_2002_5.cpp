#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long ans = 0, n, m, k;
  cin >> n >> m >> k;
  int i, j;
  vector<vector<char> > O(n + 1, vector<char>(n + 1));
  vector<vector<int> > A(n + 1, vector<int>(m + 1));
  vector<vector<int> > B(n + 1, vector<int>(m + 1));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> O[i][j];
    }
  for (i = 2; i < n; i++)
    for (j = 1; j < m - 1; j++)
      if (O[i][j] == '1' && O[i][j - 1] == '1' && O[i][j + 1] == '1' &&
          O[i - 1][j] == '1' && O[i + 1][j] == '1')
        A[i][j + 1] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) A[i][j] = A[i][j] + A[i][j - 1];
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) B[i][j] = B[i - 1][j] + A[i][j];
  }
  j = 1;
  for (int d = 1; d <= n; d++) {
    for (int z = 1; z <= n; z++) {
      j = 1;
      for (i = 1; i <= m; i++) {
        while (j <= m &&
               B[z - 1][j - 1] + B[d][i] - B[z - 1][i] - B[d][j - 1] < k)
          j++;
        if (j > m) {
          break;
        }
        ans += m - j + 1;
      }
    }
  }
  cout << ans;
  return 0;
}
