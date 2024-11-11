#include <bits/stdc++.h>
using namespace ::std;
using lint = long long;
void output2(vector<vector<lint>> v) {
  for (lint i = 0; i < lint(v.size()); ++i) {
    for (lint j = 0; j < lint(v[i].size()); ++j) {
      cout << v[i][j] << " ";
    }
    cout << '\n';
  }
}
void output(vector<lint> v) {
  for (lint i = 0; i < lint(v.size()); ++i) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  lint n, p, q;
  cin >> n >> p >> q;
  vector<tuple<lint, lint, lint>> a(n);
  vector<pair<lint, lint>> v(n);
  for (lint i = 0; i < lint(n); ++i) cin >> v[i].first;
  for (lint i = 0; i < lint(n); ++i) cin >> v[i].second;
  for (lint i = 0; i < lint(n); ++i) {
    a[i] = make_tuple(v[i].first, v[i].second, i);
  }
  sort((a).begin(), (a).end());
  reverse((a).begin(), (a).end());
  vector<lint> idx(n);
  for (lint i = 0; i < lint(n); ++i) idx[i] = get<2>(a[i]);
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  vector<vector<lint>> dp(n + 1, vector<lint>(p + 1, -(1LL << 60)));
  dp[0][0] = 0;
  for (lint i = lint(1); i < lint(n + 1); ++i)
    for (lint j = 0; j < lint(p + 1); ++j) {
      if (j) dp[i][j] = dp[i - 1][j - 1] + v[i - 1].first;
      if ((i - j) <= q)
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i - 1].second);
    }
  lint ans = 0;
  multiset<lint> s;
  lint b_cnt = -1;
  for (lint i = 0; i < lint(n); ++i) {
    if (n - i > p + q) {
      s.insert(v[n - 1 - i].second);
      continue;
    }
    auto itr = s.rbegin();
    lint cnt = 0;
    for (lint j = 0; j < lint(q - (n - i - p)); ++j) {
      cnt += (*itr);
      ++itr;
    }
    if (ans < dp[n - i][p] + cnt) {
      ans = max(ans, dp[n - i][p] + cnt);
      b_cnt = n - i - p;
    }
    s.insert(v[n - 1 - i].second);
  }
  lint now_i = p, now_j = b_cnt;
  vector<lint> ans_a, ans_b;
  for (lint i = 0; i < lint(p + b_cnt); ++i) {
    if (now_i == 0 ||
        dp[now_i + now_j - 1][now_i - 1] + v[now_i + now_j - 1].first !=
            dp[now_i + now_j][now_i]) {
      ans_b.push_back(idx[now_i + now_j - 1] + 1);
      now_j--;
    } else {
      ans_a.push_back(idx[now_i + now_j - 1] + 1);
      now_i--;
    }
  }
  multiset<pair<lint, lint>> s2;
  for (lint i = lint(p + b_cnt + 1); i < lint(n + 1); ++i) {
    s2.emplace(v[i - 1].second, i);
  }
  auto itr = s2.rbegin();
  for (lint i = 0; i < lint(q - b_cnt); ++i) {
    ans_b.emplace_back(idx[(*itr).second - 1] + 1);
    itr++;
  }
  cout << ans << '\n';
  sort((ans_a).begin(), (ans_a).end());
  sort((ans_b).begin(), (ans_b).end());
  output(ans_a);
  output(ans_b);
}
