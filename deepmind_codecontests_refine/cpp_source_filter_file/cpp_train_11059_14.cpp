#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 400001 + 5;
ll powerMod(ll a, ll b, ll md) {
  return (!b ? 1
             : (b & 1 ? a * powerMod(a * a % md, b / 2, md) % md
                      : powerMod(a * a % md, b / 2, md) % md));
}
ll modInv(ll x) { return powerMod(x, MOD - 2, MOD); }
bool visit[MX];
vi adj[MX];
vi x;
int c[MX];
set<int> ans;
void dfs(ll node) {
  cout << node << " ";
  visit[node] = 1;
  for (auto& it : adj[node]) {
    if (!visit[node]) {
      dfs(it);
    }
  }
}
int a[30000];
void solve() {
  string second;
  cin >> second;
  int len = second.size();
  int m = -1;
  int step = 0;
  for (int i = 0; i < len; i++) {
    if (second[i] == 'L') {
      step++;
    } else if (second[i] == 'R') {
      m = max(m, step);
      step = 0;
    }
  }
  m = max(m, step);
  if (m == 1) {
    m = len;
  }
  cout << m + 1 << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
