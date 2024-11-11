#include <bits/stdc++.h>
using namespace std;
const int MAXK = 22, MAXN = 2e5 + 10;
int n, k, t, tl, ans, dp[(1 << MAXK) + 100], add[MAXK + 2][MAXK + 2],
    lst[MAXK + 10];
vector<pair<int, int> > vec;
string s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> t;
  cin >> s;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    dp[1 << i] += x;
  }
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) cin >> add[i][j];
  memset(lst, -1, sizeof(lst));
  for (int i = 0; i < n; i++) {
    int rn = s[i] - 'A', mask = 0;
    tl |= (1 << rn);
    vec.clear();
    for (int j = 0; j < k; j++) {
      if (lst[j] != -1) vec.push_back({lst[j], j});
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int> >());
    for (int j = 0; j < vec.size(); j++) {
      int c = vec[j].second, val = add[c][rn];
      if (c == rn) {
        dp[mask] += val, dp[mask | (1 << c)] -= val;
        break;
      } else
        dp[mask] += val, dp[mask | (1 << c) | (1 << rn)] += val,
            dp[mask | (1 << c)] -= val, dp[mask | (1 << rn)] -= val,
            mask |= (1 << c);
    }
    lst[rn] = i;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < (1 << k); j++)
      if (j >> i & 1) dp[j] += dp[j ^ (1 << i)];
  }
  for (int i = 0; i < (1 << k); i++) {
    if (tl | i == tl && i != tl) {
      ans += (dp[i] <= t);
    }
  }
  cout << ans;
  return 0;
}
