#include <bits/stdc++.h>
using namespace std;
void init(string str, bool dbg) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (!dbg) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
  }
}
const int MAX = (int)3e5 + 5;
const int MOD = (int)1e9 + 7;
const int LEN = (int)4e3 + 5;
int t = 1;
int n, m;
int dis[MAX];
void slv() {
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> con(m);
  for (int i = 0; i < m; i++)
    cin >> con[i].second.first >> con[i].second.second >> con[i].first;
  sort(con.begin(), con.end(), greater<pair<int, pair<int, int>>>());
  int i = 0;
  int j = 0;
  for (i = 0; i < m; i++) {
    vector<int> cur;
    cur.push_back(dis[con[i].second.second] + 1);
    for (j = i + 1; j < m; j++) {
      if (con[j].first == con[j - 1].first)
        cur.push_back(dis[con[j].second.second] + 1);
      else
        break;
    }
    j = i;
    for (int k = 0; k < cur.size(); j++, k++)
      dis[con[j].second.first] = max(dis[con[j].second.first], cur[k]);
    i = j - 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
  cout << ans << "\n";
}
int main() {
  init("", 1);
  while (t--) slv();
  return 0;
}
