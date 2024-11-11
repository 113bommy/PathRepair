#include <bits/stdc++.h>
using namespace std;
const int t = 1e9 + 7;
struct item {
  int a;
  int b;
  int c;
  int numb;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<item> > w(n, vector<item>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      cin >> w[i][j].a >> w[i][j].b >> w[i][j].c;
      w[i][j].numb = j;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<pair<int, int> > profit(m);
      for (int h = 0; h < m; h++) {
        profit[h].first = w[j][h].b - w[i][h].a;
        profit[h].second = h;
      }
      sort(profit.rbegin(), profit.rend());
      int sz = k;
      int sum = 0;
      int d = 0;
      while (d < m && sz > 0) {
        sum += min(sz, w[i][profit[d].second].c) * max(0, profit[d].first);
        if (profit[d].first > 0) sz -= min(sz, w[i][profit[d].second].c);
        d++;
      }
      ans = max(ans, sum);
    }
  }
  cout << ans;
  return 0;
}
