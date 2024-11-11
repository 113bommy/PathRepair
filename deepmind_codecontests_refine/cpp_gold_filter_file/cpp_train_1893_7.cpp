#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1;
  while (test_cases--) {
    int n;
    cin >> n;
    int c[n][n];
    int max1 = 1e5;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        if (i == j) {
          c[i][j] = 0;
          continue;
        }
        if (s.at(j) == '1') {
          c[i][j] = 1;
        } else
          c[i][j] = max1;
      }
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        }
      }
    }
    int p1 = p[0] - 1;
    int pos1 = 0;
    vector<int> ans;
    ans.push_back(p[0]);
    for (int i = 0; i < m; i++) {
      if (c[p1][p[i] - 1] < (i - pos1)) {
        ans.push_back(p[i - 1]);
        p1 = p[i - 1] - 1;
        pos1 = i - 1;
        i--;
      }
    }
    ans.push_back(p[m - 1]);
    int s = ans.size();
    cout << s << "\n";
    for (int i = 0; i < s; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
