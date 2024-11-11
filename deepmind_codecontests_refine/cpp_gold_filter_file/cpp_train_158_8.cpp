#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void dout(string name, int idx, T arg) {
  cerr << name << " = " << to_string(arg);
}
template <typename T1, typename... T2>
void dout(string names, int idx, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " = " << to_string(arg) << ", ";
  dout(names.substr(names.find(',') + 2), idx + 1, args...);
}
const long long inf = (long long)1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, L, beg, end;
  cin >> n >> m >> L >> beg >> end;
  vector<vector<pair<int, long long>>> g(n);
  vector<int> deleted(m);
  vector<array<pair<int, int>, 2>> where(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    if (w == 0) {
      deleted[i] = 1;
      w = inf;
    }
    where[i][0] = make_pair(a, g[a].size());
    where[i][1] = make_pair(b, g[b].size());
    g[a].emplace_back(b, w);
    g[b].emplace_back(a, w);
  }
  auto Dijkstra = [&]() {
    set<pair<long long, int>> s;
    vector<long long> d(n, inf);
    d[beg] = 0;
    for (int i = 0; i < n; i++) {
      if (d[i] < inf) {
        s.insert(make_pair(d[i], i));
      }
    }
    while (!s.empty()) {
      int v = s.begin()->second;
      s.erase(s.begin());
      for (const auto& [u, w] : g[v]) {
        if (d[v] + w < d[u]) {
          if (d[u] < inf) {
            s.erase(make_pair(d[u], u));
          }
          d[u] = d[v] + w;
          s.insert(make_pair(d[u], u));
        }
      }
    }
    return d[end];
  };
  if (Dijkstra() < L) {
    cout << "NO" << '\n';
    exit(0);
  }
  for (int v = 0; v < n; v++) {
    for (auto& [u, w] : g[v]) {
      if (w == inf) {
        w = 1;
      }
    }
  }
  if (Dijkstra() > L) {
    cout << "NO" << '\n';
    exit(0);
  }
  int low = 0, high = m - 1, mid;
  while (low < high) {
    mid = (low + high) >> 1;
    for (int j = 0; j <= mid; j++) {
      if (deleted[j]) {
        g[where[j][0].first][where[j][0].second].second = 1;
        g[where[j][1].first][where[j][1].second].second = 1;
      }
    }
    for (int j = mid + 1; j < m; j++) {
      if (deleted[j]) {
        g[where[j][0].first][where[j][0].second].second = inf;
        g[where[j][1].first][where[j][1].second].second = inf;
      }
    }
    if (Dijkstra() <= L) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  for (int j = 0; j <= low; j++) {
    if (deleted[j]) {
      g[where[j][0].first][where[j][0].second].second = 1;
      g[where[j][1].first][where[j][1].second].second = 1;
    }
  }
  for (int j = low + 1; j < m; j++) {
    if (deleted[j]) {
      g[where[j][0].first][where[j][0].second].second = inf;
      g[where[j][1].first][where[j][1].second].second = inf;
    }
  }
  long long r = L - Dijkstra();
  assert(r >= 0);
  if (deleted[low]) {
    g[where[low][0].first][where[low][0].second].second = 1 + r;
    g[where[low][1].first][where[low][1].second].second = 1 + r;
  }
  cout << "YES" << '\n';
  for (int j = 0; j < m; j++) {
    assert(g[where[j][0].first][where[j][0].second].second ==
           g[where[j][1].first][where[j][1].second].second);
    cout << where[j][0].first << ' ' << where[j][1].first << ' '
         << g[where[j][0].first][where[j][0].second].second << '\n';
  }
  return 0;
}
