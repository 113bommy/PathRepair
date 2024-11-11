#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5, MOD = 1e9 + 7, MAXLG = log2(MAX) + 1;
const long long inf = 1e18 + 5;
int arr[MAX];
long long a[MAX], b[MAX];
vector<int> g[MAX];
bool vis[MAX], vis_2[MAX];
stack<int> st;
void dfs(int u) {
  vis[u] = true;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  st.push(u);
}
void dfs_2(int u) {
  vis_2[u] = true;
  for (int v : g[u]) {
    if (!vis[v] && !vis_2[v]) dfs(v);
  }
  st.push(u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    if (b[i] != -1) {
      g[i].push_back(b[i]);
    }
  }
  vector<int> baki, seq;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i <= n; i++) vis[i] = false;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (a[u] < 0) {
      baki.push_back(u);
      continue;
    }
    vis[u] = true;
    ans += a[u];
    seq.push_back(u);
    if (b[u] != -1) a[b[u]] += a[u];
  }
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int x : baki) {
    if (b[x] == -1 || vis[b[x]]) {
      ans += a[x];
      vis[x] = true;
      seq.push_back(x);
      continue;
    }
    g[b[x]].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    if (!vis_2[i]) dfs_2(i);
  }
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    ans += a[u];
    seq.push_back(u);
  }
  cout << ans << "\n";
  for (int x : seq) cout << x << " ";
  cout << "\n";
}
