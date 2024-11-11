#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 7;
pair<int, int> ans[lim];
pair<int, int> pmin(pair<int, int> a, pair<int, int> b) {
  int sa = a.first + a.second;
  int sb = b.first + b.second;
  if (sa == sb)
    return (a.first <= b.first ? a : b);
  else
    return (sa < sb ? a : b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(ans, ans + n + 1, pair<int, int>{1e9, 1e9});
  ans[4] = pair<int, int>{1, 0};
  ans[7] = pair<int, int>{0, 1};
  for (int i = 8; i <= n; ++i)
    ans[i] = pmin({ans[i - 4].first + 1, ans[i - 4].second},
                  {ans[i - 7].first, ans[i - 7].second + 1});
  if (ans[n].first > 1e8 || ans[n].second > 1e8)
    cout << -1;
  else
    cout << string(ans[n].first, '4') << string(ans[n].second, '7');
  return 0;
}
