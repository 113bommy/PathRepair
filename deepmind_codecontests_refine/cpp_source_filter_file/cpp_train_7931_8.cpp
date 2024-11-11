#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int maxn = 2e5 + 100;
const int LOG = 21;
vector<int> g[maxn];
vector<int> col(maxn, 0), depth(maxn);
vector<int> e, L(maxn), R(maxn);
int dp[LOG][maxn];
int p[maxn];
void dfs(int v, int p = -1) {
  L[v] = e.size();
  e.push_back(v);
  for (int to : g[v]) {
    if (to != p) {
      depth[to] = depth[v] + 1;
      dfs(to, v);
      e.push_back(v);
    }
  }
  R[v] = e.size() - 1;
}
void calc() {
  p[1] = 0;
  for (int x = 2; x < maxn; x++) p[x] = p[x / 2] + 1;
  for (int i = 0; i < (int)e.size(); i++) {
    dp[0][i] = depth[e[i]];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << (j - 1)) < maxn; i++) {
      dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
  }
}
int LCA(int a, int b) {
  int l = min(L[a], L[b]);
  int r = max(R[a], R[b]);
  int x = p[r - l + 1];
  return min(dp[x][l], dp[x][r - (1 << x) + 1]);
}
int dist(int v, int u) {
  int a = LCA(v, u);
  return depth[v] + depth[u] - 2 * a;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag = 0;
    for (int i = 0; i < n - 1; i++)
      if (a[i] == a[i + 1]) flag = 1;
    cout << flag + 1 << '\n';
  }
  return 0;
}
