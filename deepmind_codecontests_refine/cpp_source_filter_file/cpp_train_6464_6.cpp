#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[100005];
long long C[100005], L[100005];
void dfs(int u, int p = -1) {
  C[u] = 1;
  L[u] = 0;
  for (auto &t : adj[u])
    if (t.first != p) {
      int &v = t.first;
      dfs(v, u);
      C[u] += C[v];
      L[u] += L[v] + t.second;
    }
  sort(adj[u].begin(), adj[u].end(),
       [&](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.first == p) return true;
         if (b.first == p) return false;
         return C[a.first] * (L[a.first] + a.second) >
                C[b.first] * (L[b.first] + b.second);
       });
}
double M[100005];
bool used[100005];
int n;
double DP(int u, int p = -1) {
  double &ans = M[u];
  if (used[u]) return ans;
  used[u] = true;
  ans = 0;
  double total = p == -1 ? n - 1 : C[u], ac = 0;
  for (int i = p != -1; i < adj[u].size(); ++i) {
    int &v = adj[u][i].first, &l = adj[u][i].second;
    ans += C[v] / total * (ac + l + DP(v, u));
    ac += 2 * (l + L[v]);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  int u, v, t;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v >> t;
    --u, --v;
    adj[u].push_back({v, t});
    adj[v].push_back({u, t});
  }
  dfs(0);
  printf("%.7f\n", DP(0));
}
