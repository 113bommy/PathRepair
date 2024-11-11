#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000 + 3;
const long long MOD = 998244353;
int Li[MAX], Mine[MAX], vis[MAX], paisi;
vector<int> g[MAX];
void dfs(int u) {
  vis[u] = 1;
  if (paisi == -1 and Mine[u]) paisi = u;
  for (int x : g[u]) {
    if (!vis[x]) dfs(x);
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  int k1;
  cin >> k1;
  while (k1--) {
    int x;
    cin >> x;
    Mine[x] = 1;
  }
  int k2, root, node;
  cin >> k2;
  while (k2--) {
    int y;
    cin >> y;
    Li[y] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (Li[i]) {
      cout << "A " << i << endl;
      cin >> root;
      break;
    }
  }
  paisi = -1;
  dfs(root);
  cout << "B " << paisi << endl;
  cin >> node;
  if (Li[node])
    cout << "C " << paisi << endl;
  else
    cout << "C -1" << endl;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    Li[i] = Mine[i] = vis[i] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
