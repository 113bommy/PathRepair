#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, m, k, cnt;
vector<int> adj[MAX];
vector<pair<int, int> > disl;
int visit[MAX], qua[MAX];
void dfs(int x) {
  visit[x] = cnt;
  qua[cnt]++;
  for (auto i : adj[x]) {
    if (visit[i]) continue;
    dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    adj[t1].push_back(t2);
    adj[t2].push_back(t1);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    disl.push_back({t1, t2});
  }
  for (int i = 0; i < n; i++) {
    if (visit[i]) continue;
    cnt++;
    dfs(i);
  }
  for (auto o : disl) {
    int x = o.first, y = o.second;
    if (visit[x] == visit[y]) qua[visit[x]] = 0;
  }
  int ans = -1;
  for (int i = 0; i < cnt; i++) ans = max(ans, qua[i]);
  cout << ans;
  return 0;
}
