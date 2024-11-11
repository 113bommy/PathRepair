#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
map<int, set<int, greater<int>>> mp;
map<pair<long long, long long>, int> cnt;
pair<int, int> res[100005];
int n;
long long dp[100005][205];
int vis[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m, k;
  cin >> n >> m >> k;
  int s[k + 1], t[k + 1], w[k + 1], d[k + 1];
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < k; i++) {
    cin >> s[i] >> t[i] >> d[i] >> w[i];
    v.push_back({s[i], {1, i}});
    v.push_back({t[i] + 1, {0, i}});
    vis[s[i]]++;
    vis[t[i] + 1]--;
  }
  sort(v.begin(), v.end());
  int sz = v.size();
  for (int i = 0; i < sz;) {
    int j = i;
    while (j < sz && v[i].first == v[j].first) {
      int in = v[j].second.second;
      if (v[j].second.first == 1) {
        cnt[{w[in], d[in]}]++;
        mp[w[in]].insert(d[in]);
      } else {
        cnt[{w[in], d[in]}]--;
        if (cnt[{w[in], d[in]}] == 0) {
          mp[w[in]].erase(d[in]);
        }
        if (mp[w[in]].size() == 0) mp.erase(w[in]);
      }
      j++;
    }
    if (mp.size() == 0) {
      i = j;
      continue;
    }
    auto it = mp.rbegin();
    int c = it->first;
    auto it2 = (it->second).begin();
    int d1 = *it2;
    res[v[i].first] = {c, d1};
    i = j;
  }
  for (int i = 2; i <= n; i++) vis[i] += vis[i - 1];
  for (int i = 2; i <= n; i++) {
    if (res[i].first == 0 && vis[i] != 0) res[i] = res[i - 1];
  }
  for (int i = n; i >= 1; i--)
    for (int j = 0; j <= m; j++) {
      long long x = INT_MAX, y = INT_MAX;
      if (j != 0) x = (i < n) ? dp[i + 1][j - 1] : 0;
      if (i < n && res[i].first == 0)
        y = dp[i + 1][j];
      else if (res[i].second + 1 > n)
        y = res[i].first;
      else
        y = res[i].first + dp[res[i].second + 1][j];
      dp[i][j] = min(x, y);
    }
  cout << dp[1][m] << endl;
}
