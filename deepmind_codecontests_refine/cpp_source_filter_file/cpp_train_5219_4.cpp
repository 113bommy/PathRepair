#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 3e5 + 1;
long long bp(long long a, int b) {
  if (!b) return 1;
  if (b & 1) return (a * bp(a, b - 1)) % mod;
  return bp((a * a) % mod, b / 2);
}
bool ok;
bool u[N], p[N];
int cnt[2];
vector<int> g[N];
void dfs(int v) {
  u[v] = 1;
  ++cnt[p[v]];
  for (auto to : g[v]) {
    if (u[to]) {
      if (p[v] == p[to]) {
        ok = 1;
        return;
      }
      continue;
    }
    p[to] = p[v] ^ 1;
    dfs(to);
    if (ok) return;
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (!u[i]) {
        ok = 0;
        cnt[0] = 0;
        cnt[1] = 0;
        dfs(i);
        if (ok) {
          ans = 0;
          break;
        } else {
          if (cnt[0] + cnt[1] > 1) {
            ans += bp(2, cnt[1]) + bp(2, cnt[0]);
          } else
            ans += 3;
          ans %= mod;
        }
      }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      u[i] = 0;
    }
  }
  return 0;
}
