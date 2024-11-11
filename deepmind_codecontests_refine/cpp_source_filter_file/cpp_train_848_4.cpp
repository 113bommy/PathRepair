#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 5e5 + 10;
const int MOD = 1e9 + 7;
const ll infLL = 1e18;
const ld eps = 1e-6;
vi adj[mxN];
int n, m;
void solve() {
  cin >> n >> m;
  vector<bool> alive(3 * n, true);
  vi v;
  for (auto i = (0); i < (m); i++) {
    int e1, e2;
    cin >> e1 >> e2;
    e1--;
    e2--;
    if (alive[e1] && alive[e2]) {
      v.push_back(i);
      alive[e1] = 0, alive[e2] = 0;
    }
  }
  if ((int)v.size() >= n) {
    cout << "Matching\n";
    v.resize(n);
    for (auto x : v) {
      cout << x + 1 << ' ';
    }
    cout << "\n";
  } else {
    cout << "Indset\n";
    vi res;
    for (auto i = (0); i < (3 * n); i++) {
      if (alive[i]) res.push_back(i);
    }
    res.resize(n);
    for (auto x : res) cout << x << ' ';
    cout << "\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
