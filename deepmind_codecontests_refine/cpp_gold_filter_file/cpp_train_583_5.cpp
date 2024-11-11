#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 79;
class res {
 public:
  int c[2][2];
  void one_vertex() {
    c[0][0] = 1;
    c[0][1] = c[1][0] = c[1][1] = 0;
  }
  void empty() {
    c[1][0] = 1;
    c[0][0] = c[0][1] = c[1][1] = 0;
  }
  void add_child(res& a) {
    int nw[2][2];
    nw[0][0] = c[0][0] * a.c[1][0];
    nw[0][1] = c[0][0] * (a.c[0][0] + a.c[1][1]) + c[0][1] * a.c[1][0];
    nw[1][0] = c[0][0] * a.c[0][0] + c[1][0] * a.c[1][0];
    nw[1][1] = c[0][0] * a.c[0][1] + c[0][1] * a.c[0][0] +
               c[1][0] * (a.c[0][0] + a.c[1][1]) + c[1][1] * a.c[1][0];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) c[i][j] = nw[i][j];
  }
};
res merge_two_trees(res& a, res& b) {
  res v;
  v.c[0][0] = a.c[0][0] * b.c[0][0];
  v.c[0][1] = a.c[0][1] * b.c[0][0] + a.c[0][0] * b.c[0][1];
  v.c[1][0] = a.c[1][0] * b.c[0][0] + a.c[0][0] * b.c[1][0];
  v.c[1][1] = a.c[0][0] * b.c[1][1] + a.c[0][1] * b.c[1][0] +
              a.c[1][0] * b.c[0][1] + a.c[1][1] * b.c[0][0];
  return v;
}
vector<res> dp(maxn);
vector<int> s(maxn, 1);
vector<vector<int> > g(maxn);
void calculate_subtrees(int u, int p) {
  dp[u].one_vertex();
  for (int i = 0; i < g[u].size(); i++) {
    if (g[u][i] == p)
      g[u].erase(g[u].begin() + i), i--;
    else {
      calculate_subtrees(g[u][i], u);
      s[u] += s[g[u][i]];
      dp[u].add_child(dp[g[u][i]]);
    }
  }
}
long long ans = 0;
int n;
void calculate_everything(int u, int p, res& r) {
  if (p != -1) {
    if (r.c[1][0] && dp[u].c[1][0])
      ans += (n - s[u]) * 1ll * s[u];
    else
      ans += (r.c[0][0] + r.c[1][1]) * 1ll * (dp[u].c[0][0] + dp[u].c[1][1]);
  }
  vector<res> pf(g[u].size() + 1), sf(g[u].size() + 1);
  pf[0].one_vertex(), sf[g[u].size()].one_vertex();
  for (int i = 1; i <= g[u].size(); i++)
    pf[i] = pf[i - 1], pf[i].add_child(dp[g[u][i - 1]]);
  for (int i = g[u].size() - 1; i >= 0; i--)
    sf[i] = sf[i + 1], sf[i].add_child(dp[g[u][i]]);
  for (int i = 0; i < g[u].size(); i++) {
    res nw = merge_two_trees(pf[i], sf[i + 1]);
    nw.add_child(r);
    calculate_everything(g[u][i], u, nw);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0, a, b; i < n - 1; i++)
    cin >> a >> b, g[--a].push_back(--b), g[b].push_back(a);
  if (n & 1) {
    cout << "0\n";
    return 0;
  }
  calculate_subtrees(0, -1);
  res r;
  r.empty();
  calculate_everything(0, -1, r);
  cout << ans << "\n";
  return 0;
}
