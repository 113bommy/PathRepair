#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 0, m = 0, res = 2;
  cin >> n >> m;
  vector<string> ch(n);
  for (int i = 0; i < n; ++i) cin >> ch[i];
  vector<vector<bool> > poss(n, vector<bool>(m, false));
  poss[0][0] = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (ch[i][j] == '#') continue;
      if (i > 0 && poss[i - 1][j]) poss[i][j] = true;
      if (j > 0 && poss[i][j - 1]) poss[i][j] = true;
    }
  if (!poss[n - 1][m - 1])
    res = 0;
  else {
    vector<vector<bool> > possrev(n, vector<bool>(m, false));
    poss[n - 1][m - 1] = true;
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j) {
        if (ch[i][j] == '#') continue;
        if (i + 1 < n && possrev[i + 1][j]) possrev[i][j] = true;
        if (j + 1 < m && possrev[i][j + 1]) possrev[i][j] = true;
      }
    for (int i = 1; i + 2 < (n + m); ++i) {
      int ct = 0;
      for (int j = 0; j < n; ++j) {
        int diff = i - j;
        if (diff >= 0 && diff < m && poss[j][diff] && possrev[j][diff]) ++ct;
      }
      if (ct == 1) {
        res = 1;
        break;
      }
    }
  }
  cout << res;
}
