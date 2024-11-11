#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long N = 300005;
long long n, l, x[N / 3], d[N / 3], t[N / 3], p[N / 3], dist[N], e, pr[N];
vector<pair<long long, long long>> adj[N];
map<long long, long long> m, rev;
map<pair<long long, long long>, long long> m1, ramp;
void dij() {
  for (long long i = 1; i < e + 1; i++) dist[i] = 1e18;
  dist[1] = 0;
  set<pair<long long, long long>> s;
  s.insert({0, 1});
  while (!s.empty()) {
    long long x = s.begin()->second, d = s.begin()->first;
    s.erase(s.begin());
    for (long long i = 0; i < adj[x].size(); i++)
      if (dist[adj[x][i].first] >= d + adj[x][i].second)
        dist[adj[x][i].first] = d + adj[x][i].second, pr[adj[x][i].first] = x,
        s.insert({dist[adj[x][i].first], adj[x][i].first});
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> l;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> d[i] >> t[i] >> p[i];
    m[x[i]] = 1, m[x[i] + d[i]] = 1, m[x[i] - p[i]] = 1;
    if (m1.find({x[i] - p[i], x[i] + d[i]}) == m1.end() ||
        m1[{x[i] - p[i], x[i] + d[i]}] > p[i] + t[i]) {
      m1[{x[i] - p[i], x[i] + d[i]}] = p[i] + t[i];
      ramp[{x[i] - p[i], x[i] + d[i]}] = i + 1;
    }
  }
  m[0] = 1;
  m[l] = 1;
  while (m.begin()->first < 0) m.erase(m.begin());
  long long c = 1;
  for (auto it : m) m[it.first] = c, rev[c] = it.first, c++;
  for (long long i = 0; i < n; i++) {
    if (x[i] - p[i] >= 0)
      adj[m[x[i] - p[i]]].push_back({m[x[i] + d[i]], p[i] + t[i]});
  }
  auto it1 = m.rbegin();
  e = it1->second;
  for (auto it = m.rbegin(); it != m.rend(); it++) {
    if (it == m.rbegin()) continue;
    adj[it1->second].push_back({it->second, it1->first - it->first});
    adj[it->second].push_back({it1->second, it1->first - it->first});
    it1 = it;
  }
  dij();
  cout << dist[e] << '\n';
  vector<long long> ans;
  c = e;
  while (pr[c] != 0) {
    long long c1 = pr[c];
    if (m1.find({rev[c1], rev[c]}) != m1.end()) {
      if (rev[c] - rev[c1] > m1[{rev[c1], rev[c]}])
        ans.push_back(ramp[{rev[c1], rev[c]}]);
    }
    c = c1;
  }
  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  return 0;
}
