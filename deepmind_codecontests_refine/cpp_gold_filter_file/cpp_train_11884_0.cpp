#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll modpow(ll a, ll b, ll mod = (ll)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int DEBUG = 1;
const int mxn = 100, mxm = 2500, oo = 1e9;
int n, m;
int p[mxn];
bool sgnFlip;
vi adj[mxn];
int a[mxm], b[mxm], c[mxm];
void flip() {
  for (int i = 0; i < n; i++) swap(adj[i], adj[i + n]);
  for (int e = 0; e < m; e++) a[e] += n, b[e] -= n;
}
void flipSign() {
  for (int i = 0; i < m; i++) c[i] *= -1;
}
int fi(int v) {
  int e = adj[v][p[v]];
  return (a[e] ^ b[e] ^ v) - (sgnFlip * n);
}
void solve() {
  cin >> n;
  m = 0;
  for (int i = 0; i < 2 * n; i++) adj[i].clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[m] = i;
      b[m] = j + n;
      adj[a[m]].push_back(m);
      adj[b[m]].push_back(m);
      cin >> c[m++];
    }
  }
  cout << "B" << endl;
  fflush(stdin);
  string cmd;
  cin >> cmd;
  if (cmd == "D") flipSign();
  int s;
  cin >> s;
  s--;
  sgnFlip = s >= n;
  if (sgnFlip) flip();
  s %= n;
  auto cmp = [](int a, int b) { return c[a] < c[b]; };
  for (int i = 0; i < n; i++) sort(begin(adj[i]), end(adj[i]), cmp);
  for (int i = 0; i < n; i++) p[i] = 0, p[i + n] = -oo;
  bool found = 1;
  while (found) {
    for (int i = 0; i < n; i++) {
      int e = adj[i][p[i]];
      int w = a[e] ^ b[e] ^ i;
      (p[w]) = max((p[w]), (c[e]));
    }
    found = 0;
    for (int i = 0; i < n; i++) {
      int e = adj[i][p[i]];
      int w = a[e] ^ b[e] ^ i;
      if (p[w] != c[e]) p[i]++, found = 1;
    }
  }
  s++;
  do {
    if (s == -1) break;
    s = (--s) % n;
    cout << fi(s) + 1 << endl;
    fflush(stdin);
  } while (cin >> s);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
