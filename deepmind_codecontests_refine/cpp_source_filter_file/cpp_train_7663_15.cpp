#include <bits/stdc++.h>
using namespace std;
long long n;
long long po[500005];
long long mod = 1e9 + 7;
long long first[500005], second[500005];
vector<vector<long long> > adj(500005);
long long rx(long long first) { return first; }
long long ry(long long second) { return n + second; }
map<long long, long long> ax, ay;
map<long long, long long> cx, cy;
long long vis[500005];
long long lin = 0, poin = 0;
void dfs(long long node, long long par) {
  if (vis[node]) return;
  vis[node] = 1;
  lin++;
  for (auto ch : adj[node]) {
    if (ch == par) continue;
    poin++;
    dfs(ch, node);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  po[0] = 1;
  for (long long i = 1; i < 500005; i++) {
    po[i] = po[i - 1] + po[i - 1];
    if (po[i] >= mod) po[i] -= mod;
  }
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> first[i] >> second[i];
    ax[first[i]]++;
    ay[second[i]]++;
  }
  long long cur = 0;
  for (auto j : ax) {
    cx[j.first] = cur++;
  }
  for (auto j : ay) {
    cy[j.second] = cur++;
  }
  for (long long i = 0; i < n; i++) {
    first[i] = cx[first[i]];
    second[i] = cy[second[i]];
    second[i] = ry(second[i]);
    adj[first[i]].push_back(second[i]);
    adj[second[i]].push_back(first[i]);
  }
  long long ans = 1;
  for (long long i = 0; i < 500005; i++) {
    if (vis[i]) continue;
    poin = 0;
    lin = 0;
    dfs(i, -1);
    if (lin > poin) {
      ans *= po[lin] - 1;
      if (ans >= mod) ans %= mod;
    } else {
      ans *= po[lin];
      if (ans >= mod) ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
