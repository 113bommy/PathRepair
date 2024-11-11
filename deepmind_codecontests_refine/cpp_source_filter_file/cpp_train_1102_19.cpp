#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(2001, vector<int>(2001, 0));
class dsu {
 public:
  int n;
  vector<int> par;
  dsu(int N) {
    n = N;
    par = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int get_super_parent(int x) {
    if (par[x] != x) par[x] = get_super_parent(par[x]);
    return par[x];
  }
  bool same(int a, int b) { return get_super_parent(a) == get_super_parent(b); }
  void merge(int a, int b) {
    int p1 = get_super_parent(a);
    int p2 = get_super_parent(b);
    par[p1] = p2;
  }
};
bool preliminaryTest(vector<vector<int>> &grid, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        if (grid[i][j] != 0) return false;
      } else {
        if (grid[i][j] == 0 || grid[i][j] != grid[j][i]) return false;
      }
    }
  }
  return true;
}
vector<pair<int, int>> adj[2001];
bool comparator(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }
void constructTree(int n) {
  vector<vector<int>> s;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> temp(3, 0);
      temp = {grid[i][j], i, j};
      s.push_back(temp);
    }
  }
  sort(s.begin(), s.end(), comparator);
  int edge = 0;
  dsu d(n);
  for (auto x : s) {
    if (edge == n - 1) {
      break;
    }
    if (!d.same(x[1], x[2])) {
      int u = x[1];
      int v = x[2];
      adj[u].push_back({v, x[0]});
      adj[v].push_back({u, x[0]});
      d.merge(u, v);
      edge++;
    }
  }
}
void dfs(int node, int par, int og, int dist, bool *flag, int *visited) {
  (*visited)++;
  if (dist != grid[node][og]) (*flag) = false;
  for (auto child : adj[node]) {
    if (child.first == par) continue;
    dfs(child.first, node, og, dist + child.second, flag, visited);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  cout << fixed << setprecision(10);
  while (tc--) {
    long double a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      cout << (long double)1 << endl;
      continue;
    } else if (a == 0) {
      cout << (long double)1 / (long double)2;
      continue;
    } else if (b == 0) {
      cout << (long double)1 << endl;
      continue;
    }
    long double ta = 2 * a * b;
    long double y_pred = 4 * b;
    if (y_pred <= a) {
      long double trigA = 2 * b * b;
      long double remA = ta - trigA;
      cout << (remA) / (ta) << endl;
    } else {
      long double trigA = (a * a) / 8.0;
      trigA += (b - a / 4) * a;
      cout << (ta - trigA) / ta << endl;
    }
  }
}
