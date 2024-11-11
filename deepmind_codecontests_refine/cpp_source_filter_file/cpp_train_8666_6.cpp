#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n;
int curTime;
int distHidden;
int depthNode[MAXN];
int tin[MAXN], tout[MAXN];
vector<int> adj[MAXN];
vector<int> depth[MAXN];
vector<int> q;
void init() {
  curTime = 0;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    depth[i].clear();
  }
}
void query(int& dist, int& node) {
  cout << "? " << (int)q.size();
  while (!q.empty()) {
    cout << " " << q.back();
    q.pop_back();
  }
  cout << endl;
  fflush(stdout);
  cin >> dist >> node;
}
void DFS(int cur, int p, int d) {
  depthNode[cur] = d;
  tin[cur] = ++curTime;
  depth[d].push_back(cur);
  for (int i = 0; i < (int)adj[cur].size(); i++)
    if (adj[cur][i] != p) DFS(adj[cur][i], cur, d + 1);
  tout[cur] = curTime;
}
bool test(int k, int& node) {
  if (depth[k].empty()) return false;
  for (int i = 0; i < (int)depth[k].size(); i++) q.push_back(depth[k][i]);
  int d;
  query(d, node);
  return (d == distHidden);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; i++) {
      int U, V;
      scanf("%d %d", &U, &V);
      adj[U].push_back(V);
      adj[V].push_back(U);
    }
    int c;
    for (int i = 1; i <= n; i++) q.push_back(i);
    query(distHidden, c);
    DFS(c, c, 0);
    int l = 0;
    int r = n - 1;
    int node1 = c;
    int auxNode;
    while (l < r) {
      int m = (l + r) / 2;
      if (l == r - 1) m = r;
      if (test(m, auxNode)) {
        l = m;
        node1 = auxNode;
      } else
        r = m - 1;
    }
    int node2;
    int depthNode2 = distHidden - depthNode[node1];
    if (depthNode2 == 0)
      node2 = c;
    else {
      for (int i = 0; i < (int)depth[depthNode2].size(); i++) {
        int cur = depth[depthNode2][i];
        if (tin[cur] > tin[node1] || tout[node1] > tout[cur]) q.push_back(cur);
      }
      int d;
      query(d, node2);
    }
    cout << "! " << node1 << " " << node2 << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s[0] == 'I') exit(0);
  }
}
