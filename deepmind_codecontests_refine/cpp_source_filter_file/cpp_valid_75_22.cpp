#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
vector<int> dta[N];
vector<pair<int, int> > vec;
int check(int v) {
  for (auto p : vec)
    if (v < p.first)
      return 0;
    else
      v += p.second;
  return 1;
}
int solve(void) {
  int l = 1, r = 1000000000, m, ans = r;
  while (l <= r) {
    m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1, k; i <= n; i++) {
      cin >> k;
      for (int j = 0, inn; j < k; j++) {
        cin >> inn;
        dta[i].push_back(inn);
      }
      for (int j = 0; j < dta[i].size(); j++) dta[i][j] -= j - 1;
      vec.emplace_back(*max_element(dta[i].begin(), dta[i].end()),
                       dta[i].size());
    }
    sort(vec.begin(), vec.end());
    cout << solve() << endl;
    for (int i = 1; i <= n; i++) dta[i].clear();
    vec.clear();
  }
  return 0;
}
