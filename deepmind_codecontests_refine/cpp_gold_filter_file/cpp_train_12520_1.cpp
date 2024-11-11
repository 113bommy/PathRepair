#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
const long long Mod = 1000000007;
vector<int> g[maxn];
long long siz[maxn];
long long a[maxn];
long long b[maxn];
int cnt;
int n;
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    siz[u] += siz[v];
  }
  for (int v : g[u]) {
    if (v == fa) continue;
    a[++cnt] = 1ll * siz[v] * (n - siz[v]);
  }
  return;
}
bool cmp(long long a, long long b) { return a > b; }
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int u, v;
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cnt = 0;
    dfs(1, 0);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(a + 1, a + cnt + 1, cmp);
    sort(b + 1, b + m + 1, cmp);
    for (int i = 1; i <= cnt; i++) {
      a[i] = a[i] % Mod;
    }
    long long ans = 0;
    if (m > cnt) {
      long long d = 1ll;
      long long pos = m - cnt + 1;
      for (int i = 1; i <= pos; i++) {
        d = 1ll * d * b[i] % Mod;
      }
      ans = (1ll * ans + 1ll * a[1] * d % Mod) % Mod;
      for (int i = 2; i <= cnt; i++) {
        ans = (1ll * ans + 1ll * a[i] * b[i + pos - 1] % Mod) % Mod;
      }
    } else {
      for (int i = 1; i <= cnt; i++) {
        if (i > m) {
          ans = (1ll * ans + 1ll * a[i] % Mod) % Mod;
        } else {
          ans = (1ll * ans + 1ll * a[i] * b[i] % Mod) % Mod;
        }
      }
    }
    cout << (ans % Mod + Mod) % Mod << endl;
  }
  return 0;
}
