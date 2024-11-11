#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MOD = 1000000007;
vector<int> edges[MAXN], childs[MAXN];
int ou[MAXN], dp[MAXN];
int add(long long a, long long b) { return (a + b) % MOD; }
int mul(long long a, long long b) { return (a * b) % MOD; }
void dfs(int v, int fat) {
  dp[v] = 1;
  for (int i = 0; i < edges[v].size(); i++) {
    int u = edges[v][i];
    if (u != fat) {
      childs[v].push_back(u);
      dfs(u, v);
      dp[v] = mul(dp[v], add(dp[u], 1));
    }
  }
}
void dfs2(int v) {
  vector<int> lf(childs[v].size());
  vector<int> rg(childs[v].size());
  if ((int)childs[v].size() > 0) {
    lf[0] = 1;
    rg[(int)childs[v].size() - 1] = 1;
  }
  for (int i = 0; i < (int)childs[v].size() - 1; i++)
    lf[i + 1] = mul(lf[i], add(dp[childs[v][i]], 1));
  for (int i = (int)childs[v].size() - 2; i >= 0; i--)
    rg[i] = mul(rg[i + 1], add(dp[childs[v][i]], 1));
  for (int i = 0; i < childs[v].size(); i++) {
    int u = childs[v][i];
    ou[u] = add(mul(mul(lf[i], rg[i]), ou[v]), 1);
    dfs2(u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    edges[p].push_back(i);
    edges[i].push_back(p);
  }
  dfs(0, -1);
  ou[0] = 1;
  dfs2(0);
  for (int i = 0; i < n; i++) cout << mul(ou[i], dp[i]) << " ";
  cout << endl;
}
