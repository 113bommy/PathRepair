#include <bits/stdc++.h>
using namespace std;
long long int cnt = 0;
int mod = 1000000007;
int main() {
  int t;
  cin >> t;
  ;
  while (t--) {
    int m;
    cin >> m;
    ;
    vector<vector<int> > mat(2, vector<int>(m));
    vector<int> col(m, 0), row(m, 0);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
        ;
        if (i == 1 && j > 0) {
          col[j] += col[j - 1] + mat[i][j];
        }
        if (i == 1 && j == 0) {
          col[j] = mat[i][j];
        }
        if (i == 0) {
          if (j == 0)
            row[j] = mat[i][j];
          else
            row[j] += row[j - 1] + mat[i][j];
        }
      }
    }
    int sum = 0, ans = INT_MAX;
    for (int i = 0; i < m; i++) {
      if (i > 0 && max(row[m - 1] - row[i], col[i - 1]) < ans) {
        ans = max(row[m - 1] - row[i], col[i - 1]);
      } else if (i == 0) {
        if (i > 0 && row[m - 1] - row[0] < ans) {
          ans = row[m - 1] - row[0];
        }
      }
    }
    cout << (ans == INT_MAX ? 0 : ans) << "\n";
    ;
  }
}
