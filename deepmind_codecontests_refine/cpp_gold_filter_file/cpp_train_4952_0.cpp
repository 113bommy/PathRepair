#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
long long colors[200005];
vector<long long> Graph[200005];
set<long long> ss;
bool visited[200005];
void dfs(long long n) {
  visited[n] = true;
  ss.insert(n);
  for (long long i = 0; i < Graph[n].size(); i++) {
    if (!visited[Graph[n][i]]) {
      dfs(Graph[n][i]);
    }
  }
}
long long count_colors() {
  map<long long, long long> mp;
  for (auto elem : ss) {
    long long val = mp.count(colors[elem]);
    if (val == 0) {
      mp[colors[elem]] = 1;
    } else {
      mp[colors[elem]]++;
    }
  }
  long long mx_cnt = 0;
  for (auto elem : mp) {
    mx_cnt = max(mx_cnt, elem.second);
  }
  return ss.size() - mx_cnt;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> colors[i];
  }
  for (long long i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    Graph[l - 1].push_back(r - 1);
    Graph[r - 1].push_back(l - 1);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (!visited[i]) {
      ss.clear();
      dfs(i);
      ans += count_colors();
    }
  }
  cout << ans;
}
