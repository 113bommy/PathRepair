#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll a[200005], b[200005];
int sz[200005];
vector<int> adj[200005];
vector<int> v, w;
void f(int i, int p) {
  if (a[i] < 0) w.push_back(i);
  for (int x : adj[i]) {
    if (x == p) continue;
    f(x, i);
  }
}
void solve() {
  ll i, j;
  ll n;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      sz[b[i]]++;
      adj[b[i]].push_back(i);
    }
  }
  queue<int> q;
  for (i = 1; i <= n; i++)
    if (sz[i] == 0) q.push(i);
  ll ans = 0;
  while (q.size()) {
    int cur = q.front();
    q.pop();
    if (a[cur] >= 0) {
      v.push_back(cur);
      ans += a[cur];
    }
    if (b[cur] != -1) {
      if (a[cur] >= 0) a[b[cur]] += a[cur];
      if (--sz[b[cur]] == 0) q.push(b[cur]);
    }
  }
  for (i = 1; i <= n; i++)
    if (b[i] == -1) f(i, 0);
  for (auto x : w) ans += a[x];
  cout << ans << '\n';
  for (auto x : v) cout << x << ' ';
  for (auto x : w) cout << x << ' ';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
