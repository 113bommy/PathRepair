#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g, gg;
int skolkoinv[223456];
char used[223456];
char isT[1234567];
int p[1234567];
void dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (!used[to]) {
      dfs(to);
      skolkoinv[v] += skolkoinv[to];
    }
  }
  if (isT[v]) ++skolkoinv[v];
}
void dfs2(int v) {
  used[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (skolkoinv[to] && !used[to]) {
      dfs2(to);
      p[to] = v;
      gg[v].push_back(to);
      gg[to].push_back(v);
    }
  }
}
int dist[1234567];
int dist2[1234567];
void dfs3(int v) {
  used[v] = 1;
  for (int i = 0; i < gg[v].size(); ++i) {
    int to = gg[v][i];
    if (!used[to]) {
      dist[to] = dist[v] + 1;
      dfs3(to);
    }
  }
}
void dfs5(int v) {
  used[v] = 1;
  for (int i = 0; i < gg[v].size(); ++i) {
    int to = gg[v][i];
    if (!used[to]) {
      dist2[to] = dist2[v] + 1;
      dfs3(to);
    }
  }
}
void dfs4(int v) {
  used[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (!used[to]) {
      dist[to] = dist[v] + 1;
      dfs4(to);
    }
  }
}
char isKilled[1234567];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> need;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    need.push_back(t);
    isT[t] = 1;
  }
  if (m == 1) {
    cout << need[0] << " " << 0;
    return 0;
  }
  if (m == 2) {
    cout << min(need[0], need[1]) << " ";
    dfs4(min(need[0], need[1]));
    cout << dist[max(need[0], need[1])];
    return 0;
  }
  gg.resize(n + 1);
  dfs(need[0]);
  for (int i = 1; i <= n; ++i) used[i] = 0;
  dfs2(need[0]);
  set<pair<int, int> > st;
  for (int i = 1; i <= n; ++i)
    if (gg[i].size()) st.insert(make_pair(gg[i].size(), i));
  int ans = 0;
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) dp[i] = gg[i].size();
  int needv = -1;
  int needv1 = -1;
  while (st.size() >= 2) {
    if (st.size() == 2) {
      needv = st.begin()->second;
      st.erase(st.begin());
      needv1 = st.begin()->second;
      st.clear();
      break;
    }
    vector<int> v;
    while (st.size() && st.begin()->first <= 1) {
      v.push_back(st.begin()->second);
      isKilled[st.begin()->second] = 1;
      st.erase(st.begin());
    }
    for (int i = 0; i < v.size(); ++i) {
      int cur = v[i];
      for (int j = 0; j < gg[cur].size(); ++j) {
        int curto = gg[cur][j];
        if (dp[curto]) {
          st.erase(make_pair(dp[curto], curto));
          --dp[curto];
          if (!isKilled[curto]) st.insert(make_pair(dp[curto], curto));
        }
      }
    }
  }
  int answer = 0;
  for (int i = 1; i <= n; ++i) answer += gg[i].size();
  for (int i = 1; i <= n; ++i) used[i] = 0;
  if (st.size() == 1) {
    needv = st.begin()->second;
    dfs3(needv);
    sort(need.begin(), need.end());
    int i1 = -1, l1 = -1;
    for (int i = 0; i < m; ++i)
      if (dist[need[i]] > l1) l1 = dist[need[i]], i1 = need[i];
    cout << i1 << " " << answer - 2 * l1 << "\n";
    return 0;
  } else {
    dfs3(needv);
    for (int i = 1; i <= n; ++i) used[i] = 0;
    dfs5(needv1);
    int r = -1;
    int t = 0;
    sort(need.begin(), need.end());
    for (int i = 0; i < m; ++i)
      if (r < dist[need[i]]) r = dist[need[i]];
    for (int i = 0; i < m; ++i) {
      if (dist[need[i]] == r || dist2[need[i]] == r) {
        cout << need[i] << " " << answer - 2 * r + 1 << "\n";
        return 0;
      }
    }
  }
  return 0;
}
