#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long rand(long long x, long long y) {
  return rng() % (y + 1 - x) + x;
}
string inline to_string(char c) {
  string second(1, c);
  return second;
}
template <typename T>
inline T gcd(T a, T b) {
  return a == 0 ? llabs(b) : gcd(b % a, a);
}
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using spi = pair<ll, pi>;
using dpi = pair<pi, pi>;
long long LLINF = 1e18;
int INF = 1e9 + 1e6;
int n, m, k, A[(500006)];
vector<int> v[(500006)], ppl[(500006)];
struct ufds_ {
  pi p[(500006)];
  ll sz[(500006)];
  stack<int> stk;
  ufds_() {
    for (ll i = 0; i <= ll((500006) - 1); ++i) p[i] = pi(i, 0), sz[i] = 1;
    while (stk.size()) stk.pop();
  }
  pi find(int x) {
    if (p[x].first == x)
      return pi(x, 0);
    else {
      pi tmp = find(p[x].first);
      return pi(tmp.first, tmp.second ^ p[x].second);
    }
  }
  bool merge(int x, int y) {
    pi a = find(x), b = find(y);
    if (a.first == b.first) return a.second ^ b.second;
    if (sz[a.first] > sz[b.first]) swap(a, b);
    stk.emplace(a.first);
    p[a.first] = pi(b.first, a.second == b.second);
    sz[b.first] += sz[a.first];
    return 1;
  }
  void roll() {
    while (stk.size()) {
      ll x = stk.top();
      stk.pop();
      sz[p[x].first] -= sz[x];
      p[x] = pi(x, 0);
    }
  }
} u;
bool gone[(500006)];
ll ans, grps;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (ll i = 1; i <= ll(n); ++i) cin >> A[i], ppl[A[i]].emplace_back(i);
  for (ll i = 1; i <= ll(m); ++i) {
    int a, b;
    cin >> a >> b;
    v[a].emplace_back(b), v[b].emplace_back(a);
  }
  for (ll i = 1; i <= ll(n); ++i)
    for (auto j : v[i])
      if (A[i] == A[j]) {
        gone[A[i]] |= !u.merge(i, j);
      }
  while (u.stk.size()) u.stk.pop();
  ans = (ll)k * (k - 1) / 2, grps = k;
  for (ll i = 1; i <= ll(k); ++i) {
    if (gone[i]) {
      --grps;
      ans -= grps;
      continue;
    }
    vector<pi> g;
    for (auto j : ppl[i]) {
      for (auto k : v[j])
        if (!gone[A[k]] && A[k] > i) g.emplace_back(k, j);
    }
    sort((g).begin(), (g).end(),
         [](pi x, pi y) { return A[x.first] < A[y.first]; });
    for (ll j = 0; j <= ll(ll(g.size()) - 1); ++j) {
      int k = j + 1;
      while (k < ll(g.size()) && A[g[k].first] == A[g[j].first]) ++k;
      bool can = 1;
      for (ll l = j; l <= ll(k - 1); ++l) {
        can &= u.merge(g[l].first, g[l].second);
      }
      ans -= !can;
      u.roll();
      j = k;
    }
  }
  cout << ans << '\n';
}
