#include <bits/stdc++.h>
using namespace std;
map<pair<string, int>, vector<pair<string, int> > > g;
int n;
string s, sr;
pair<string, int> pa[1000];
vector<pair<string, int> > que;
int a, ar;
map<string, int> ans;
void bfs() {
  map<string, int> now;
  for (int i = 0; i < que.size(); ++i) {
    for (auto it = g[que[i]].begin(); it != g[que[i]].end(); ++it) {
      if (ans[it->first] == 0) {
        now[it->first] = max(now[it->first], it->second);
      }
    }
  }
  que.clear();
  for (auto it = now.begin(); it != now.end(); ++it) {
    ans[it->first] = it->second;
    que.push_back({it->first, it->second});
  }
  if (que.size() != 0) bfs();
}
int main() {
  cin >> n;
  int tmpn;
  for (int i = 0; i < n; ++i) {
    cin >> s >> a;
    pa[i].first = s;
    pa[i].second = a;
    cin >> tmpn;
    for (int j = 0; j < tmpn; ++j) {
      cin >> sr >> ar;
      g[pa[i]].push_back({sr, ar});
    }
    if (i != n - 1) cin >> s;
  }
  que.push_back(pa[0]);
  ans[pa[0].first] = pa[0].second;
  bfs();
  ans.erase(pa[0].first);
  cout << ans.size() << "\n";
  for (auto it = ans.begin(); it != ans.end(); ++it) {
    cout << it->first << " " << it->second << "\n";
  }
  return 0;
}
