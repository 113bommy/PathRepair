#include <bits/stdc++.h>
using namespace std;
int s, t;
int psum[100005];
vector<int> pos[2][2];
int cost[100005];
long long dp[100005];
int chosen[100005];
int mx;
bool ok(int c) {
  dp[0] = 0;
  chosen[0] = 0;
  for (int i = (1); i <= (s); i += (1)) {
    dp[i] = dp[i - 1];
    chosen[i] = chosen[i - 1];
    if (cost[i] < 1000000000 && i >= t) {
      long long nc = dp[i - t] + cost[i] - c;
      if (nc < dp[i] || (nc == dp[i] && chosen[i - t] + 1 > chosen[i])) {
        dp[i] = nc;
        chosen[i] = chosen[i - t] + 1;
      }
    }
  }
  return (chosen[s] >= mx);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> s >> S >> t;
  for (int i = (1); i <= (s); i += (1)) {
    psum[i] = psum[i - 1] + (S[i - 1] == '?');
    if (S[i - 1] != '?') pos[S[i - 1] - 'a'][i & 1].push_back(i);
  }
  for (int i = (1); i <= (s - t + 1); i += (1)) {
    auto &v = pos[0][~i & 1];
    int p = lower_bound(v.begin(), v.end(), i) - v.begin();
    auto &v2 = pos[1][i & 1];
    int q = lower_bound(v2.begin(), v2.end(), i) - v2.begin();
    int ed = i + t - 1;
    if ((p != v.size() && v[p] <= ed) || (q != v2.size() && v2[q] <= ed))
      cost[ed] = 1000000000;
    else
      cost[ed] = psum[ed] - psum[i - 1];
  }
  chosen[0] = 0;
  for (int i = (1); i <= (s); i += (1)) {
    chosen[i] = chosen[i - 1];
    if (i >= t && cost[i] < 1000000000)
      chosen[i] = max(chosen[i], chosen[i - t] + 1);
  }
  mx = chosen[s];
  int l = 0, r = t;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m))
      r = m - 1;
    else
      l = m + 1;
  }
  ok(t);
  printf("%lld\n", dp[s] + 1LL * t * mx);
  return 0;
}
