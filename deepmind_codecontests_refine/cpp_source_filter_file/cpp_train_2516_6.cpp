#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long md = 1000 * 1000 * 1000 + 7;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long mul(long long a, long long b, long long c, long long d) {
  return (((((a * b) % md) * c) % md) * d) % md;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, i, in, out;
  cin >> n;
  vector<pair<int, int> > p;
  int lim;
  for (i = 0; i < n; ++i) {
    cin >> out >> in;
    if (!i)
      lim = out;
    else
      lim = min(lim, out);
    p.push_back(make_pair(in, out));
  }
  sort(p.begin(), p.end());
  map<int, pair<long long, long long> > dp;
  set<int> s;
  s.insert(p[n - 1].first);
  dp[p[n - 1].first] = make_pair(1ll, 0ll);
  for (i = n - 2; i >= 0; --i) {
    int in = p[i].first, out = p[i].second;
    auto it = s.lower_bound(out);
    if (it == s.end()) {
      if (dp.count(in)) {
        if (dp[in].second)
          dp[in] = make_pair(1ll, 0ll);
        else
          dp[in].first++;
      } else
        dp[in] = make_pair(1ll, 0ll);
    } else {
      if (dp.count(in)) {
        if (dp[in].second > dp[*it].second + *it - out)
          dp[in] = make_pair(dp[*it].first, dp[*it].second + *it - out);
        else if (dp[in].second == dp[*it].second + *it - out)
          dp[in].first += dp[*it].first;
      } else
        dp[in] = make_pair(dp[*it].first, dp[*it].second + *it - out);
    }
    dp[in].first %= md;
    int next = *s.begin();
    if (next == in) continue;
    if (dp[next].second + next >= dp[in].second + in) s.insert(in);
    if (dp[next].second + next == dp[in].second + in)
      dp[in].first += dp[next].first;
    dp[in].first %= md;
  }
  long long space = 0, ans;
  for (auto y : dp) {
    in = y.first;
    long long num = y.second.first, room = y.second.second;
    if (in >= lim) continue;
    if (!space)
      space = room + in, ans = num;
    else {
      if (space < room + in) ans = num;
      space = min(space, room + in);
    }
  }
  cout << ans;
  return 0;
}
