#include <bits/stdc++.h>
using namespace std;
int k, n[15], a[15][5005], pre[1 << 15];
long long s[15], S;
map<long long, pair<int, int> > M;
bool vs[15][5005], dp[1 << 15];
vector<pair<int, int> > res[1 << 15];
int main() {
  cin >> k;
  memset(s, 0, sizeof(s));
  for (int i = 0; i <= k - 1; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      M[a[i][j]] = {i, j};
      s[i] += a[i][j];
    }
    S += s[i];
  }
  if (S % k != 0) {
    cout << "NO";
    return 0;
  }
  memset(vs, false, sizeof(vs));
  memset(dp, false, sizeof(dp));
  for (int i = 0; i <= k - 1; i++) {
    for (int j = 0; j < n[i]; j++)
      if (!vs[i][j]) {
        int i1 = i, j1 = j, bitmask = 0;
        vector<pair<int, int> > v;
        bool err = false;
        while (true) {
          bitmask |= (1 << i1);
          long long need = (S / k) - (s[i1] - a[i1][j1]);
          v.push_back(pair<int, int>(i1, j1));
          if (M.count(need) == 0) {
            err = true;
            break;
          }
          int i2 = M[need].first, j2 = M[need].second;
          if ((bitmask >> i2) & 1) {
            if (i2 != i || j2 != j) {
              err = true;
              break;
            }
            v.push_back(pair<int, int>(i2, j2));
            for (int c = 0; c < v.size(); c++)
              vs[v[c].first][v[c].second] = true;
            break;
          }
          i1 = i2;
          j1 = j2;
        }
        if (err) continue;
        res[bitmask] = v;
        dp[bitmask] = true;
        pre[bitmask] = bitmask;
      }
  }
  for (int i = 0; i < (1 << k); i++)
    for (int j = i; j > 0; j = (j - 1) & i)
      if (dp[i ^ j] && dp[j]) {
        dp[i] = true;
        pre[i] = j;
      }
  if (!dp[(1 << k) - 1])
    cout << "No";
  else {
    cout << "Yes" << endl;
    pair<int, int> ans[15];
    int cur = (1 << k) - 1;
    while (cur > 0) {
      int t = pre[cur];
      for (int i = 0; i < res[t].size() - 1; i++) {
        int i1 = res[t][i + 1].first;
        int j1 = res[t][i + 1].second;
        int tmp = a[i1][j1];
        int now = res[t][i].first;
        ans[i1] = pair<int, int>(tmp, now);
      }
      cur ^= t;
    }
    for (int i = 0; i <= k - 1; i++)
      cout << ans[i].first << " " << ans[i].second + 1 << endl;
  }
}
