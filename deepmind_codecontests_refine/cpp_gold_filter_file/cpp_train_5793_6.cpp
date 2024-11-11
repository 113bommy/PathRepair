#include <bits/stdc++.h>
using namespace std;
int n, m, mmax, f[30], dp[1 << 23];
pair<int, int> pre[1 << 23];
vector<int> res;
int main() {
  cin >> n >> m;
  if (m == n * (n - 1) / 2 || !m) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    f[x] |= (1 << (y - 1));
    f[y] |= (1 << (x - 1));
  }
  mmax = (1 << n) - 1;
  for (int i = 1; i <= n; i++) f[i] |= (1 << (i - 1));
  for (int i = 0; i <= mmax; i++) dp[i] = 1 << 27;
  dp[0] = 0;
  for (int i = 0; i < mmax; i++)
    for (int j = 1; j <= n; j++)
      if (i & (1 << (j - 1)) || !i) {
        if (dp[i] + 1 < dp[i | f[j]]) {
          dp[i | f[j]] = dp[i] + 1;
          pre[i | f[j]] = pair<int, int>(i, j);
        }
      }
  int temp = mmax;
  do {
    res.push_back(pre[temp].second);
    temp = pre[temp].first;
  } while (temp != 0);
  reverse(res.begin(), res.end());
  cout << dp[mmax] << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  return 0;
}
