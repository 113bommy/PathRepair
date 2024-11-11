#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 50;
const long long oo = 1e18;
const int mod = 1e9 + 7;
int n, m, a[N], ans, v;
bool vis[N], f[N];
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int i = 0; i < n; i++) {
    int x = (1 << i);
    if (u * x) {
      if (f[u ^ x]) dfs((u ^ x) ^ v);
      dfs(u ^ x);
    }
  }
}
int main() {
  cin >> n >> m;
  v = (1 << n) - 1;
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
    f[a[i]] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (!vis[a[i]]) {
      ans++;
      dfs(v ^ a[i]);
    }
  }
  cout << ans << endl;
}
