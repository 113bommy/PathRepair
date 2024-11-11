#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 1e6 + 70;
const int INF = 2.1e9;
const int maxm = 1e6 + 70;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
int n, m, k;
int a[maxn], r[maxn], f[maxn], sz[maxn];
vector<int> G[maxn];
bool cmp(int x, int y) { return a[x] < a[y]; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  while (cin >> n) {
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) r[i] = i;
    sort(r + 1, r + n + 1, cmp);
    long long ans = 0;
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
      int u = r[i];
      long long pre = 0;
      for (int j = 0; j < G[u].size(); j++) {
        int v = find(G[u][j]);
        if (sz[v]) {
          ans += pre * sz[u] * a[u];
          pre += sz[v];
          f[v] = u;
        }
      }
      sz[u] = pre + 1;
      ans += (long long)sz[u] * a[u];
    }
    reverse(r + 1, r + n + 1);
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
      int u = r[i];
      long long pre = 0;
      for (int j = 0; j < G[u].size(); j++) {
        int v = find(G[u][j]);
        if (sz[v]) {
          ans -= pre * sz[v] * a[u];
          pre += sz[v];
          f[v] = u;
        }
      }
      sz[u] = pre + 1;
      ans -= (long long)sz[u] * a[u];
    }
    cout << ans << endl;
  }
  return 0;
}
