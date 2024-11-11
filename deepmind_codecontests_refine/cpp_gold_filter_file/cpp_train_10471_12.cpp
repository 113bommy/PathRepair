#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e14;
long long int mod = 1e9 + 7;
char en = '\n';
struct TwoSAT {
  static const int MAXV = 2e5 + 5;
  int n, cnt;
  vector<int> g[MAXV], rg[MAXV];
  bool vis[MAXV];
  int order[MAXV], color[MAXV];
  void init(int curn) {
    n = curn;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      rg[i].clear();
    }
  }
  void add(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int u, int c) {
    color[u] = c;
    for (auto it : g[u])
      if (color[it] == -1) dfs(it, c);
  }
  int solve(vector<int> &ans) {
    int cl = 0;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
      if (color[i] == -1) dfs(i, cl++);
    for (int i = 0; i < n; i += 2)
      if (color[i] == color[i ^ 1]) return 0;
    return 1;
  }
} sat;
long long int arr[200005];
vector<long long int> arr2[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  sat.init(2 * m);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    while (x--) {
      long long int y;
      cin >> y;
      y--;
      arr2[y].push_back(i);
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      long long int p0 = 2 * arr2[i][0], p1 = 2 * arr2[i][0] + 1;
      long long int q0 = 2 * arr2[i][1], q1 = 2 * arr2[i][1] + 1;
      sat.add(p0, q1);
      sat.add(q0, p1);
    } else {
      long long int p0 = 2 * arr2[i][0], p1 = 2 * arr2[i][0] + 1;
      long long int q0 = 2 * arr2[i][1], q1 = 2 * arr2[i][1] + 1;
      sat.add(p0, q0);
      sat.add(p1, q1);
    }
  }
  vector<int> ans;
  int val = sat.solve(ans);
  if (val)
    cout << "YES" << en;
  else
    cout << "NO" << en;
  return 0;
}
