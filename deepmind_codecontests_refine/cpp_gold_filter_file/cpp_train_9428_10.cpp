#include <bits/stdc++.h>
using namespace std;
const long double eps = (long double)1e-9;
const long long inf = (long long)1e18;
const long double pi = acos(-1.0);
const long long mod = (long long)1e9 + 7;
const int N = 200500;
vector<int> g[N];
int n, a[N], b[N], ans[N];
void dfs(int v, int col) {
  ans[v] = col;
  for (auto to : g[v])
    if (!ans[to]) dfs(to, (col == 1 ? 2 : 1));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; i += 2) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  for (int i = 1; i <= n * 2; i++)
    if (!ans[i]) dfs(i, 1);
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans[a[i]], ans[b[i]]);
  return 0;
}
