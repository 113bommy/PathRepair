#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
long long vis[N], down[N], cnt[N], up[N];
vector<pair<long long, long long> > adj[N];
long long f(long long x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
void dfs(long long r) {
  vis[r] = 1;
  down[r] = 0;
  cnt[r] = 1;
  for (auto it : adj[r]) {
    long long v, w;
    v = it.first;
    w = it.second;
    if (!vis[v]) {
      dfs(v);
      if (w)
        down[r] += cnt[v];
      else
        down[r] += down[v];
      cnt[r] += cnt[v];
    }
  }
}
void dfs2(long long r) {
  vis[r] = 1;
  for (auto it : adj[r]) {
    long long v, w;
    v = it.first;
    w = it.second;
    if (!vis[v]) {
      if (w)
        up[v] = cnt[1] - cnt[v];
      else
        up[v] = up[r] + down[r] - down[v];
      dfs2(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, u, v, w, i, ans = 0;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> u >> v >> w;
    w = f(w);
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  dfs(1);
  memset(vis, 0, sizeof vis);
  dfs2(1);
  for (i = 1; i <= n; i++) {
    ans += down[i] * (down[i] - 1);
    ans += up[i] * (up[i] - 1);
    ans += up[i] * down[i] * 2;
  }
  cout << ans;
}
