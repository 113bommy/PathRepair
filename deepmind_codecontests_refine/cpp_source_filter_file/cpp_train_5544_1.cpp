#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
int N, M;
vector<vector<int> > adj;
vector<bool> seen, finished;
stack<int> st;
int pos = -1;
void dfs(int v, int p = -1) {
  seen[v] = true;
  st.push(v);
  for (auto u : adj[v]) {
    if (u == p) continue;
    if (finished[u]) continue;
    if (seen[u] && !finished[u]) {
      pos = u;
      return;
    }
    dfs(u, v);
    if (pos != -1) return;
  }
  finished[v] = true;
  st.pop();
}
vector<int> color;
int cnt = 0;
bool ng = false;
void dfs2(int v, int c) {
  if (ng) return;
  color[v] = c;
  if (c == 1) cnt++;
  for (auto u : adj[v]) {
    if (color[u] != -1) {
      if (color[u] == c) ng = true;
      continue;
    }
    dfs2(u, 1 - c);
  }
}
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int K;
  cin >> N >> M >> K;
  adj.resize(N);
  seen.resize(N);
  finished.resize(N);
  color.resize(N, -1);
  for (int i = 0; i < (int)(M); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < (int)(N); i++)
    if (!finished[i]) {
      dfs(i);
      if (pos != -1) break;
    }
  if (pos == -1) {
    cout << "1\n";
    dfs2(0, 0);
    vector<int> ans;
    if (cnt > (K + 1) / 2) {
      for (int i = 0; i < (int)(N); i++)
        if (color[i] == 1) ans.push_back(i + 1);
    } else {
      for (int i = 0; i < (int)(N); i++)
        if (color[i] == 0) ans.push_back(i + 1);
    }
    for (int i = 0; i < (int)((K + 1) / 2); i++) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << "\n";
    return 0;
  }
  vector<int> cycle;
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    cycle.push_back(v);
    if (v == pos) break;
  }
  int L = cycle.size();
  map<int, int> Mp;
  for (int i = 0; i < (int)(L); i++) Mp[cycle[i]] = i;
  vector<int> ans;
  int idx = 0;
  while (idx < L) {
    ans.push_back(cycle[idx]);
    int next = idx;
    for (auto u : adj[cycle[idx]]) {
      if (idx == 0 && u == cycle[L - 1]) continue;
      if (ans.size() < 3 && u == cycle[0]) continue;
      if (u == cycle[0]) {
        next = L;
        break;
      } else {
        chmax(next, Mp[u]);
      }
    }
    idx = next;
  }
  if (ans.size() > K) {
    cout << "1\n";
    for (int i = 0; i < (int)((K + 1) / 2); i++) {
      if (i > 0) cout << " ";
      cout << ans[i * 2];
    }
    cout << "\n";
  } else {
    cout << "2\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)(ans.size()); i++) {
      if (i > 0) cout << " ";
      cout << ans[i] + 1;
    }
    cout << "\n";
  }
  return 0;
}
