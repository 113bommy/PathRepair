#include <bits/stdc++.h>
using namespace std;
namespace std {
template <>
struct hash<pair<long long, long long>> {
  size_t operator()(const pair<long long, long long>& pr) const {
    hash<long long> llhsh;
    return llhsh(pr.first) + llhsh(pr.second);
  }
};
}  // namespace std
const int N = 100100;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
pair<long long, long long> dp[N];
unordered_map<pair<long long, long long>, pair<long long, long long>> mp;
struct truck {
  long long v, c, l, r;
};
truck t[N];
int n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    dp[i] = {-INFLL, 0};
    cin >> t[i].v >> t[i].c >> t[i].l >> t[i].r;
  }
  for (int i = 1; i <= n; ++i) {
    if (t[i].l == 0) {
      dp[i] = {0, 0};
    } else {
      pair<long long, long long> idt = {t[i].l + t[i].r + t[i].c,
                                        t[i].r + t[i].c};
      if (mp.count(idt)) {
        auto [va, j] = mp[idt];
        dp[i] = max(dp[i], {va + t[i].v, j});
      }
    }
    if (dp[i].first >= 0) {
      pair<long long, long long> idx = {t[i].l + t[i].r + t[i].c, t[i].r};
      pair<long long, long long> val = {dp[i].first, i};
      if (!mp.count(idx)) {
        mp[idx] = {-INFLL, 0};
      }
      mp[idx] = max(mp[idx], val);
    }
  }
  pair<long long, long long> best = {-INFLL, 0};
  for (int i = 1; i <= n; ++i) {
    if (t[i].r == 0) {
      best = max(best, {dp[i].first, i});
    }
  }
  if (best.first < 0) {
    cout << "0\n\n";
    return 0;
  }
  int q = best.second;
  vector<int> res;
  while (q) {
    res.push_back(q);
    q = dp[q].second;
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  for (auto& x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
