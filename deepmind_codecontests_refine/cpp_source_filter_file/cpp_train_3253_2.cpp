#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int kMaxN = 6e5;
vi adj[kMaxN];
bool is_used[kMaxN];
int curtm[kMaxN];
int xyz[kMaxN];
int xy;
int FindOrder(int v) {
  ++xy;
  for (int s : adj[v]) {
    if (!is_used[s]) {
      continue;
    }
    xyz[curtm[s]] = xy;
  }
  for (int i = 1;; ++i) {
    if (!xyz[i]) {
      debug() << " ["
              << "v"
                 ": "
              << (v) << "] "
              << " ["
              << "i"
                 ": "
              << (i) << "] ";
      return i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vi> order(n + 1);
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    order[c].push_back(i);
  }
  vi ans;
  for (int tm = 1; tm <= n; ++tm) {
    for (int v : order[tm]) {
      if (FindOrder(v) != tm) {
        cout << "-1\n";
        return 0;
      }
      curtm[v] = tm;
      is_used[v] = true;
      ans.push_back(v);
    }
  }
  for (int v : ans) {
    cout << v << " ";
  }
  cout << "\n";
}
