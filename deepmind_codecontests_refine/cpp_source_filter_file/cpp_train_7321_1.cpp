#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
long long n, m;
pair<pair<long long, long long>, long long> sell[100500];
pair<long long, long long> buy[100500];
vector<long long> g[100500];
long long used[100500];
long long mt[100500];
long long timer = 0;
bool try_kuhn(long long v) {
  if (used[v] == timer) return false;
  used[v] = timer;
  for (long long i = 0; i < g[v].size(); i++) {
    long long to = g[v][i];
    if (mt[to] == -1 || try_kuhn(to)) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
vector<pair<long long, long long> > answer;
map<long long, long long> ret;
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++)
    cin >> sell[i].first.first >> sell[i].first.second, sell[i].second = i;
  sort(sell, sell + n);
  reverse(sell, sell + n);
  for (long long i = 0; i < n; i++) ret[sell[i].first.second] = i;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> buy[i].first >> buy[i].second;
    map<long long, long long>::iterator j = ret.find(buy[i].second);
    if (j != ret.end() && sell[j->second].first.first <= buy[i].first)
      g[j->second].push_back(i);
    j = ret.find(buy[i].second + 1);
    if (j != ret.end() && sell[j->second].first.first <= buy[i].first)
      g[j->second].push_back(i);
  }
  memset(mt, -1, sizeof mt);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    timer++;
    bool w = try_kuhn(i);
    if (w) ans += sell[i].first.first;
  }
  for (long long i = 0; i < m; i++)
    if (mt[i] != -1) answer.push_back(make_pair(sell[mt[i]].second, i));
  cout << ans << endl;
  cout << answer.size() << endl;
  for (long long i = 0; i < answer.size(); i++)
    cout << answer[i].second + 1 << ' ' << answer[i].first + 1 << endl;
}
