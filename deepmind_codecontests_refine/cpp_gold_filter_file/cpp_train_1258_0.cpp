#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long linf = 4000000000000000000LL;
const long long inf = 998244353;
const long double pi = 3.1415926535;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int(second.size())) {
    freopen((second + ".in").c_str(), "r", stdin);
    if (second != "test1") freopen((second + ".out").c_str(), "w", stdout);
  }
}
int n, q;
vector<int> a;
vector<vector<pair<int, int>>> adj;
vector<long long> dp;
const int SZ = 20;
vector<vector<int>> jump;
vector<int> parent, depth;
vector<long long> ans;
vector<vector<long long>> answer;
vector<long long> best;
void dfs(int i, int p) {
  parent[i] = p;
  dp[i] = a[i];
  for (auto& x : adj[i]) {
    if (x.first == p) continue;
    depth[x.first] = depth[i] + 1;
    dfs(x.first, i);
    dp[i] += max(0LL, dp[x.first] - 2 * x.second);
  }
}
void dfs1(int i, int p, int d) {
  if (p != -1) {
    ans[i] = dp[p] - max(0LL, dp[i] - 2 * d);
    ans[i] -= d;
  }
  best[i] = a[i];
  if (p != -1) {
    best[i] += max(0LL, ans[i] + best[p] - d - a[p]);
  }
  for (auto& x : adj[i]) {
    if (x.first == p) continue;
    dfs1(x.first, i, x.second);
  }
}
void init() {
  parent.resize(n);
  depth.resize(n);
  dp.resize(n);
  ans.resize(n);
  dfs(0, -1);
  jump.resize(n, vector<int>(SZ));
  for (int i = (0); i < (n); ++i) jump[i][0] = parent[i];
  for (int i = (0); i < (SZ - 1); ++i) {
    for (int j = (0); j < (n); ++j)
      jump[j][i + 1] = (jump[j][i] == -1 ? -1 : jump[jump[j][i]][i]);
  }
  best.resize(n);
  dfs1(0, -1, -1);
  answer.resize(n, vector<long long>(SZ));
  for (int i = (0); i < (n); ++i) answer[i][0] = ans[i];
  for (int i = (0); i < (SZ - 1); ++i) {
    for (int j = (0); j < (n); ++j)
      answer[j][i + 1] =
          answer[j][i] + (jump[j][i] == -1 ? 0 : answer[jump[j][i]][i]);
  }
}
int get(int a, int b) {
  for (int j = (0); j < (SZ); ++j) {
    if (b & (1 << j)) {
      a = jump[a][j];
    }
  }
  return a;
}
int LCA(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  a = get(a, depth[a] - depth[b]);
  if (a == b) return a;
  int j = SZ;
  while (j) {
    j--;
    int ta = jump[a][j], tb = jump[b][j];
    if (ta != tb) a = ta, b = tb;
  }
  return parent[a];
}
int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[LCA(a, b)]; }
long long solve(int a, int b) {
  long long x = 0;
  for (int j = (0); j < (SZ); ++j) {
    if (b & (1 << j)) {
      x += answer[a][j];
      a = jump[a][j];
    }
  }
  return x;
}
int main() {
  setIO("");
  cin >> n >> q;
  a.resize(n);
  for (auto& x : a) cin >> x;
  adj.resize(n);
  for (int i = (0); i < (n - 1); ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[--x].push_back({--y, z});
    adj[y].push_back({x, z});
  }
  init();
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int lca = LCA(l, r);
    long long ret;
    if (depth[l] > depth[r]) swap(l, r);
    if (r == l) {
      ret = dp[l];
      ret += best[l];
      ret -= a[l];
    } else if (l == lca) {
      ret = dp[r];
      int d1 = depth[r] - depth[lca];
      ret += solve(r, d1);
      ret += best[lca];
      ret -= a[lca];
    } else {
      ret = dp[l] + dp[r];
      int d1 = depth[l] - depth[lca];
      ret += solve(l, d1);
      d1 = depth[r] - depth[lca];
      ret += solve(r, d1);
      ret -= dp[lca];
      ret += best[lca];
      ret -= a[lca];
    }
    cout << ret << '\n';
  }
}
