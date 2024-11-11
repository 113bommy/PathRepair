#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  vector<string> s;
  vector<vector<int> > cnt;
  cin >> n >> m;
  s.assign(m, "");
  cnt.assign(m, vector<int>());
  for (int i = 0; i < cnt.size(); i++) cnt[i].assign(n, 0);
  for (int i = 0; i < m; i++) cin >> s[i];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++)
        if (k != i && s[k][j] == s[i][j]) {
          cnt[i][j]--;
          cnt[k][j]--;
        }
      for (int k = 0; k < n; k++)
        if (k != j && s[i][k] == s[i][j]) {
          cnt[i][j]--;
          cnt[i][k]--;
        }
    }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (cnt[i][j] == 0) cout << s[i][j];
  return 0;
}
