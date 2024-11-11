#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 0xcccccccccccccccLL;
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << ' ' << p.second;
}
int n, m;
vector<P> G[500100];
array<int, 2> dist[500100];
PQG<P> q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    G[v].emplace_back(u, t);
  }
  fill(dist, dist + n - 1, (array<int, 2>){INF, INF});
  q.emplace(0, n - 1);
  while (!q.empty()) {
    auto [d, id] = q.top();
    q.pop();
    int type = 0;
    if (id >= n) {
      id -= n;
      type = 1;
    }
    if (dist[id][type] != d) continue;
    if (d < dist[id][type ^ 1]) continue;
    for (P ne : G[id]) {
      if (chmin(dist[ne.first][ne.second], d + 1)) {
        q.emplace(d + 1, ne.first + ne.second * n);
      }
    }
  }
  if (dist[0][0] == INF and dist[0][1] == INF)
    cout << -1 << endl;
  else
    cout << max(dist[0][0], dist[0][1]) << endl;
  for (int i = 0; i < n; ++i) cout << (dist[i][0] < dist[i][1]);
  cout << endl;
}
