#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 123, MAXN = 2e5 + 47;
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) in >> i;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T, class D>
istream& operator>>(istream& in, vector<pair<T, D>>& a) {
  for (auto& i : a) in >> i.first >> i.second;
  return in;
}
template <class T, class D>
ostream& operator<<(ostream& out, vector<pair<T, D>>& a) {
  for (auto& i : a) out << i.first << " " << i.second << endl;
  return out;
}
vector<vector<long long>> g, rg;
vector<long long> used, k;
signed main() {
  setlocale(LC_ALL, "rus");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  g.resize(n);
  rg.resize(n);
  used.resize(n);
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  long long kek;
  cin >> kek;
  k.resize(kek);
  cin >> k;
  for (auto& i : k) --i;
  queue<long long> q;
  vector<long long> dist(n);
  used[k.back()] = 1;
  q.push(k.back());
  while (!q.empty()) {
    long long v = q.front();
    q.pop();
    for (auto& i : rg[v])
      if (!used[i]) {
        used[i] = 1;
        dist[i] = dist[v] + 1;
        q.push(i);
      }
  }
  long long ans1 = 0, ans2 = 0;
  for (long long i = 0; i < k.size() - 1; ++i) {
    long long d = dist[k[i]];
    long long d2 = dist[k[i + 1]];
    long long mn = INF;
    for (auto& j : g[k[i]])
      if (j != k[i + 1]) mn = min(mn, dist[j]);
    if (mn < d2) ++ans1, ++ans2;
    if (mn == d2) ++ans2;
  }
  cout << ans1 << " " << ans2;
}
