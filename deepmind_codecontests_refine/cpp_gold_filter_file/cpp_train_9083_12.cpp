#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
vector<vector<int>> dp;
int k;
int l[3010], r[3010];
int n;
set<pair<int, int>> p;
int solve(int x, int y) {
  if (x > y) return 0;
  if (dp[x][y] >= 0) return dp[x][y];
  dp[x][y] = 0;
  int c = 0;
  auto it = p.lower_bound({x, 0});
  if (it == p.end()) return dp[x][y] = 0;
  int j = (*it).second;
  int z = 0;
  while (j < n && l[j] == x) {
    if (r[j] == y)
      z++;
    else if (r[j] < y)
      c = max(c, solve(l[j], r[j]) + solve(r[j] + 1, y));
    j++;
  }
  c = z + max(c, solve(x + 1, y));
  return dp[x][y] = c;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    p.clear();
    k++;
    scanf("%d", &n);
    vector<int> val;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &l[i], &r[i]);
      val.push_back(l[i]);
      val.push_back(r[i]);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for (int i = 0; i < n; i++) {
      l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
      r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
      v.push_back({l[i], r[i]});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      l[i] = v[i].first;
      r[i] = v[i].second;
    }
    for (int i = 0; i < n; i++) {
      p.insert({l[i], i});
    }
    int siz = val.size();
    dp = vector<vector<int>>(siz, vector<int>(siz, -1));
    printf("%d\n", solve(0, val.size() - 1));
  }
  return 0;
}
