#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MAXN = 5 + 5000;
constexpr int MINF = -(MAXN * MAXN);
int n, m, k;
int a[MAXN], b[MAXN], c[MAXN], g[MAXN], memo[MAXN][MAXN];
vector<int> l[MAXN];
int dp(int idx, int w) {
  if (w < a[idx]) return MINF;
  if (idx == n) return 0;
  int& ans = memo[idx][w];
  if (~ans) return ans;
  w += b[idx];
  ans = dp(1 + idx, w);
  int imp = 0;
  for (int i = (int)0; i < (int)l[idx].size(); ++i) {
    imp += c[l[idx][i]];
    ans = max(ans, imp + dp(1 + idx, w - i - 1));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    g[i] = -1;
  }
  for (int i = (int)0; i < (int)m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[v] = max(g[v], u);
  }
  for (int i = (int)0; i < (int)n; ++i) {
    if (g[i] == -1) {
      g[i] = i;
    }
    l[g[i]].push_back(i);
  }
  for (int i = (int)0; i < (int)n; ++i) {
    sort(l[i].begin(), l[i].end(),
         [](const int& p, const int& q) -> bool { return c[p] > c[q]; });
  }
  memset(memo, -1, sizeof memo);
  cout << max(-1, dp(0, k)) << '\n';
  return 0;
}
