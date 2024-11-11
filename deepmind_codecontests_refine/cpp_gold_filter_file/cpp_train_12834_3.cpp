#include <bits/stdc++.h>
using namespace std;
void dbvar() { cerr << "]" << endl; }
template <class H, class... T>
void dbvar(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  dbvar(t...);
}
const int INF = (int)(1e9);
const long long int INFL = (long long int)(1e18);
const long double pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
long long int power(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int val = power(n, m / 2);
  if (m % 2 == 0)
    return (val * val);
  else
    return ((val * val) * n);
}
long long int powermod(long long int n, long long int m, long long int _MOD) {
  if (m == 0) return 1;
  long long int val = powermod(n, m / 2, _MOD);
  val %= _MOD;
  if (m % 2 == 0)
    return (val * val) % _MOD;
  else
    return (((val * val) % _MOD) * n) % _MOD;
}
void solve() {
  int n, m;
  long long int k;
  cin >> n >> m >> k;
  vector<unordered_set<int> > G(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  set<pair<int, int> > s;
  for (int i = 0; i < n; i++) s.insert(make_pair(G[i].size(), i));
  while ((int)s.size()) {
    auto it = *s.begin();
    if (it.first >= k) {
      cout << 1 << ' ' << s.size() << '\n';
      for (auto it : s) cout << it.second + 1 << ' ';
      cout << '\n';
      return;
    }
    if (it.first == k - 1 && m >= k * (k - 1) / 2) {
      bool check = true;
      vector<int> guys(G[it.second].begin(), G[it.second].end());
      for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k - 1; j++)
          if (G[guys[i]].count(guys[j]) == 0) check = false;
      }
      if (check) {
        cout << 2 << '\n';
        for (auto v : guys) cout << v + 1 << ' ';
        cout << it.second + 1 << '\n';
        return;
      }
    }
    s.erase(it);
    m -= it.first;
    for (auto v : G[it.second]) {
      s.erase(make_pair(G[v].size(), v));
      G[v].erase(it.second);
      s.insert(make_pair(G[v].size(), v));
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
