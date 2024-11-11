#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)200 + 7;
const int INF = (int)1e9 + 7;
int n, m, k;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
string name[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> name[i];
    for (int t = 1; t <= m; t++) {
      cin >> a[i][t] >> b[i][t] >> c[i][t];
    }
  }
  int ans = 0;
  for (int f = 1; f <= n; f++) {
    for (int s = f + 1; s <= n; s++) {
      vector<pair<int, int>> all;
      for (int i = 1; i <= m; i++) {
        all.push_back(make_pair(b[s][i] - a[f][i], i));
      }
      sort(all.begin(), all.end());
      reverse(all.begin(), all.end());
      int profit = 0;
      int sz = k;
      for (int i = 0; i < all.size(); i++) {
        if (all[i].first <= 0) break;
        int id = all[i].second;
        int amount = c[f][id];
        int take = min(amount, sz);
        sz -= take;
        profit += all[i].first * take;
      }
      ans = max(ans, profit);
    }
  }
  cout << ans;
  return 0;
}
