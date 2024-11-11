#include <bits/stdc++.h>
using pii = std::pair<int, int>;
inline void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<pii> vec, stk, res;
  for (int i = 0; i < n - 1; ++i)
    if (s[i] == s[i + 1]) vec.emplace_back(i, s[i] - 'a');
  int cnt[26] = {}, dom = -1, d = 0, m = vec.size(), lst = 0;
  for (int i = 0; i < vec.size(); ++i) cnt[vec[i].second]++;
  for (int i = 0; i < 26; ++i)
    if (2 * cnt[i] >= m) dom = i;
  auto check = [&](int a, int b, int dom) {
    return a != b && (dom == -1 || a == dom || b == dom);
  };
  for (int i = 0; i < vec.size(); ++i) {
    int c = vec[i].second, p = vec[i].first - d;
    if (!stk.empty() && check(c, stk.back().second, dom)) {
      --cnt[c], --cnt[stk.back().second], m -= 2;
      int l = stk.back().first, r = p;
      res.emplace_back(l + 1, r), d += r - l, stk.pop_back();
      for (int i = 0; i < 26; ++i)
        if (2 * cnt[i] >= m) dom = i;
    } else
      stk.emplace_back(p, c);
  }
  for (int i = 0; i < stk.size(); ++i) {
    res.emplace_back(0, stk[i].first - lst);
    d += stk[i].first - lst + 1, lst = stk[i].first + 1;
  }
  res.emplace_back(0, n - d - 1), printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) solve();
  return 0;
}
