#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 110000;
const int M = 5000;
const int oo = 10000 * 10000 * 10;
int n;
int r;
int val[N];
vector<int> e[N];
int lef[N] = {0};
long long dp[N] = {0};
bool visited[N];
bool cmp(int i, int j) { return dp[i] > dp[j]; }
int f[N] = {0};
void cal(int u) {
  int i, j, k;
  dp[u] = 0;
  lef[u] = val[u] - 1;
  if (u == r) ++lef[u];
  for (i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == f[u]) continue;
    if (dp[v] == -1) {
      f[v] = u;
      cal(v);
    }
  }
  sort(e[u].begin(), e[u].end());
  for (i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == f[u]) continue;
    if (lef[u]) {
      --lef[u];
      dp[u] += 2 + dp[v];
    }
  }
  for (i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (v == f[u]) continue;
    int add = (lef[u] < lef[v] ? lef[u] : lef[v]);
    dp[u] += add * 2;
    lef[u] -= add;
    lef[v] -= add;
  }
}
void solve() {
  int i, j, k;
  memset(dp, -1, sizeof(dp));
  cal(r);
  long long ans = dp[r];
  printf("%lld\n", ans);
}
int main() {
  int i, j, cas = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &val[i]);
  for (i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  scanf("%d", &r);
  solve();
  return 0;
}
