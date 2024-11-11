#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int sum[6][MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n, m, l, r;
  string s, temp[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      if (temp[i][j % 3] != s[j]) sum[i][j] = 1;
      if (j > 0) sum[i][j] += sum[i][j - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    int ans = 2e9;
    for (int j = 0; j < 6; j++) {
      if (i > 0)
        ans = min(ans, sum[j][r - 1] - sum[j][l - 2]);
      else
        ans = min(ans, sum[j][r - 1]);
    }
    cout << ans << endl;
  }
}
