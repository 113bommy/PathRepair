#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 50;
const long long mod = 1e9 + 7;
unordered_map<long long, int> mp;
int a[18][maxn];
int vis[18], k[18];
int s[18], sum;
pair<int, int> p[maxn * 18];
int G[maxn * 18];
vector<pair<int, int> > ans[1 << 16];
int dp[1 << 16];
void solve(int sta) {
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  vector<pair<int, int> > tmp;
  int S = (1 << p[sta].first - 1);
  q.push(sta);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == sta && vis[p[u].first]) {
      dp[S] = 1;
      ans[S] = tmp;
      return;
    }
    if (vis[p[u].first]) return;
    vis[p[u].first] = 1;
    if (G[u]) {
      int v = G[u];
      q.push(v);
      S |= (1 << p[v].first - 1);
      tmp.push_back({a[p[v].first][p[v].second], p[u].first});
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    for (int j = 1; j <= k[i]; j++) {
      cin >> a[i][j];
      s[i] += a[i][j];
      sum += a[i][j];
      mp[a[i][j]] = ++cnt;
      p[cnt] = {i, j};
    }
  }
  if (sum % n) {
    cout << "No" << endl;
    return 0;
  }
  sum /= n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k[i]; j++) {
      long long v = sum - (s[i] - a[i][j]);
      if (!mp.count(v)) continue;
      int cur = mp[v];
      if (p[cur].first == i && p[cur].second != j) continue;
      G[mp[a[i][j]]] = cur;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    solve(i);
  }
  int S = (1 << n) - 1;
  for (int i = 1; i <= S; i++) {
    if (!dp[i]) {
      for (int j = (i - 1) & i; j; j = (j - 1) & i) {
        if (dp[j] && dp[i ^ j]) {
          dp[i] = 1;
          ans[i] = ans[j];
          for (auto tmp : ans[i ^ j]) ans[i].push_back(tmp);
          break;
        }
      }
    }
  }
  if (dp[S] == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  sort(ans[S].begin(), ans[S].end(), [](pair<int, int> &a, pair<int, int> &b) {
    return p[mp[a.first]].first < p[mp[b.first]].first;
  });
  for (auto i : ans[S]) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
