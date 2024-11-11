#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll MULMOD(ll a, ll b, ll n) {
  if (b == 0) return 0;
  ll tmp = MULMOD(a, b >> 1, n);
  if (b & 1) return (tmp * 2 % n + a) % n;
  return tmp * 2 % n;
}
using vi = vector<int>;
using pi = pair<int, int>;
using vii = vector<pi>;
int n, m, k;
vi d[300005];
vi W[300005];
ll s[300005];
vi ind[300005];
vi ans;
const ll Max = 1e15;
void dijkstra() {
  for (int i = 1; i <= n; ++i) s[i] = Max;
  priority_queue<pi, vector<pi>, greater<pi> > pq;
  pq.push(pi(0, 1));
  s[1] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    ll du = pq.top().first;
    pq.pop();
    if (du != s[u]) continue;
    for (int i = 0; i < d[u].size(); ++i) {
      int v = d[u][i];
      ll w = W[u][i];
      if (w + du < s[v]) {
        s[v] = w + du;
        pq.push(pi(s[v], v));
      }
    }
  }
}
int c[300005];
void dfs(int pos) {
  if (c[pos]) return;
  c[pos] = 1;
  for (int i = 0; i < d[pos].size(); ++i) {
    if (k == 0) continue;
    int v = d[pos][i];
    ll w = W[pos][i];
    if (w + s[pos] == s[v] && !c[v]) {
      --k;
      ans.push_back(ind[pos][i]);
      dfs(v);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    ll w;
    cin >> x >> y >> w;
    d[x].push_back(y);
    d[y].push_back(x);
    W[x].push_back(w);
    W[y].push_back(w);
    ind[x].push_back(i);
    ind[y].push_back(i);
  }
  dijkstra();
  dfs(1);
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i << ' ';
  return 0;
}
