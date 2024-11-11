#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
int n, m, u, v, k;
int p[N];
ll c[N];
vector<pair<ll, pair<int, int>>> edges;
int cnc;
int get(int i) { return i == p[i] ? i : p[i] = get(p[i]); }
bool mrg(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v) return false;
  p[v] = u;
  return true;
}
ll fast(ll b, ll e) {
  if (!e) return 1;
  if (e & 1) return b * fast(b, e - 1) % mod;
  return fast(b * b % mod, e >> 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%lld", c + i);
  set<ll> st;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    --u, --v;
    ll w = c[u] ^ c[v];
    edges.push_back(make_pair(w, make_pair(u, v)));
    st.insert(w);
  }
  ll ans = (fast(2, n) * 1ll * ((1ll << k) - st.size()) % mod) % mod;
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m;) {
    int j = i;
    cnc = n;
    for (; j < m && edges[j].first == edges[i].first; j++) {
      cnc -= mrg(edges[j].second.first, edges[j].second.second);
    }
    ans = (ans + fast(2, cnc)) % mod;
    for (int x = i; x < j; x++)
      p[edges[x].second.first] = edges[x].second.first,
      p[edges[x].second.second] = edges[x].second.second;
    i = j;
  }
  cout << ans << '\n';
  return 0;
}
