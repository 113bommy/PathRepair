#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, K;
vector<int> adj[100001];
int depth[100001];
int anc[100001][20];
int IN[100001], OUT[100001], TIME = 0;
void dfs(int node, int par) {
  IN[node] = TIME;
  TIME++;
  anc[node][0] = par;
  for (int x : adj[node])
    if (x != par) {
      depth[x] = depth[node] + 1;
      dfs(x, node);
    }
  OUT[node] = TIME;
  TIME++;
}
int lca(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int diff = depth[b] - depth[a];
  for (int i = 19; i >= 0; i--)
    if (((1 << i) & diff) != 0) b = anc[b][i];
  if (a == b) return a;
  for (int i = 19; i >= 0; i--)
    if (anc[a][i] != anc[b][i]) {
      a = anc[a][i];
      b = anc[b][i];
    }
  return anc[a][0];
}
int dis(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
int edges = 0;
set<pair<int, int>> st;
int getPrev(int node) {
  set<pair<int, int>>::iterator it = st.lower_bound({IN[node], node});
  if (it == st.begin())
    return st.rbegin()->second;
  else {
    it--;
    return it->second;
  }
}
int getNext(int node) {
  set<pair<int, int>>::iterator it = st.lower_bound({IN[node], node});
  it++;
  if (it == st.end())
    return st.begin()->second;
  else
    return it->second;
}
void insertNode(int node) {
  st.insert({IN[node], node});
  int n1 = getPrev(node);
  int n2 = getNext(node);
  edges -= dis(n1, n2);
  edges += dis(n1, node);
  edges += dis(node, n2);
}
void deleteNode(int node) {
  int n1 = getPrev(node);
  int n2 = getNext(node);
  edges += dis(n1, n2);
  edges -= dis(n1, node);
  edges -= dis(node, n2);
  st.erase({IN[node], node});
}
int main() {
  cin >> N >> K;
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 1);
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= N; j++) anc[j][i] = anc[anc[j][i - 1]][i - 1];
  int r = 0, ans = 0;
  for (int i = 1; i <= N; i++) {
    while (edges / 2 + 1 <= K && r <= N) {
      ans = max(ans, r - i + 1);
      r++;
      insertNode(r);
    }
    deleteNode(i);
  }
  cout << ans << endl;
  return 0;
}
