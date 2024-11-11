#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, val[N], L[N], R[N], color[N], cmd, x, ID, v;
vector<int> adj[N];
struct fenwick {
  int fen[N];
  fenwick() { memset(fen, 0, sizeof fen); }
  void add(int i, int x) {
    for (++i; i <= n; i += i & -i) fen[i] += x;
  }
  void add(int i, int j, int x) {
    add(i, x);
    add(j + 1, -x);
  }
  int sum(int i) {
    int s = 0;
    for (++i; i > 0; i -= i & -i) s += fen[i];
    return s;
  }
} fen[2];
void dfs(int u, int par = -1) {
  L[u] = ID++;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    color[v] = color[u] ^ 1;
    if (par != v) {
      dfs(v, u);
    }
  }
  R[u] = ID - 1;
}
int a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> val[i];
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    fen[color[i]].add(L[i], L[i], val[i]);
  }
  while (m--) {
    cin >> cmd >> x;
    --x;
    if (cmd == 1) {
      cin >> v;
      fen[color[x]].add(L[x], R[x], v);
      fen[!color[x]].add(L[x], R[x], -v);
    } else {
      cout << fen[color[x]].sum(L[x]) << '\n';
    }
  }
  cout << flush;
}
