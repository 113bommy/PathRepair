#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
vector<int> gr[200005];
int depth[200005] = {0};
int a = 0, b = 0;
stack<int> st;
void dfs(int x, int par = -1) {
  for (auto it : gr[x]) {
    if (it == par) continue;
    depth[it] = depth[x] + 1;
    dfs(it, x);
  }
}
int dfs2(int x, int par = -1) {
  st.push(x);
  if (x == b) return 1;
  for (auto it : gr[x]) {
    if (it == par) continue;
    int val = dfs2(it, x);
    if (val == 1) return 1;
  }
  st.pop();
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (gr[i].size() > 1) root = i;
  }
  depth[root] = 0;
  dfs(root);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (depth[i] > mx) {
      mx = depth[i];
      a = i;
    }
  }
  depth[a] = 0;
  dfs(a);
  mx = 0;
  for (int i = 0; i < n; i++) {
    if (depth[i] > mx) {
      mx = depth[i];
      b = i;
    }
  }
  dfs2(a);
  if ((int)st.size() == n) {
    cout << n - 1 << "\n";
    int c;
    for (int i = 0; i < n; i++) {
      if (i != a && a != b) {
        c = i;
        break;
      }
    }
    cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
    return 0;
  }
  ans = (int)st.size() - 1;
  queue<int> Q;
  int vis[n + 1];
  memset(vis, 0, sizeof(vis));
  vis[st.top()] = 1;
  st.pop();
  while (st.size() != 1) {
    int top = st.top();
    st.pop();
    vis[top] = 1;
    Q.push(top);
  }
  vis[st.top()] = 1;
  st.pop();
  while (!Q.empty()) {
    int front = Q.front();
    Q.pop();
    for (auto it : gr[front]) {
      if (vis[it] != 0) continue;
      vis[it] = vis[front] + 1;
      Q.push(it);
    }
  }
  int c;
  mx = 0;
  for (int i = 0; i < n; i++) {
    if (i == a || i == b) continue;
    if (vis[i] > mx) {
      mx = vis[i];
      c = i;
    }
  }
  cout << ans + mx - 1 << "\n";
  cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
  return 0;
}
