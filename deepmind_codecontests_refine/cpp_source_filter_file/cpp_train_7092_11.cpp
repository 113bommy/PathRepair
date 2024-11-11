#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, cnt;
long long s[N], c[N], ans[N];
vector<pair<int, bool>> adj[N];
bool isLucky(long long k) {
  while (k > 0) {
    long long a = k % 10;
    if (a != 4 && a != 7) return false;
    k /= 10;
  }
  return true;
}
pair<long long, long long> dfs(long long u, long long p) {
  int l = cnt;
  long long k = 0;
  for (auto x : adj[u])
    if (x.first != p) {
      if (x.second)
        k += dfs(x.first, u).first;
      else
        k += dfs(x.first, u).second;
    }
  c[u] = k;
  cnt++;
  s[u] = cnt - l;
  return {s[u], c[u]};
}
void solve(int u, int p, bool l) {
  if (l) {
    ans[u] = s[p] - s[u];
    ans[u] += c[u];
  } else
    ans[u] = ans[p];
  for (auto x : adj[u])
    if (x.first != p) solve(x.first, u, x.second);
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (isLucky(w)) {
      adj[u].push_back({v, 1});
      adj[v].push_back({u, 1});
    } else {
      adj[u].push_back({v, 0});
      adj[v].push_back({u, 0});
    }
  }
  dfs(0, 0);
  for (auto x : adj[0]) {
    if (x.second)
      ans[0] += s[x.first];
    else
      ans[0] += c[x.first];
  }
  for (auto x : adj[0]) solve(x.first, 0, x.second);
  long long res = 0;
  for (int i = 0; i < n; i++) res += ans[i] * (ans[i] - 1);
  cout << res;
  return 0;
}
