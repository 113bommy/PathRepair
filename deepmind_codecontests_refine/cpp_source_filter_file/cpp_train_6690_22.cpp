#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream &operator<<(ostream &str, pair<T, T> &a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream &operator>>(istream &str, pair<T, T> &a) {
  str >> a.first >> a.second;
  return str;
}
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(6);
  solve();
  return 0;
}
const long long MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e18 + 10, BASE = 37;
long long root, len;
vector<long long> prefix, res;
void dfs1(long long v, long long finish, vector<long long> &used,
          vector<vector<long long>> &g) {
  prefix.push_back(v);
  if (v == finish) {
    res = prefix;
  }
  if ((long long)((prefix).size()) > len) {
    len = (long long)((prefix).size());
    root = prefix.back();
  }
  used[v] = 1;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs1(u, finish, used, g);
    }
  }
  prefix.pop_back();
}
void dfs2(long long v, long long d, vector<long long> &used,
          vector<vector<long long>> &g, map<long long, vector<long long>> &mp) {
  used[v] = 1;
  mp[d].push_back(v);
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs2(u, d + 1, used, g, mp);
    }
  }
}
void query() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> g(n + 1);
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<long long> used(n + 1);
  root = 0, len = 0;
  res.clear();
  dfs1(1, INF, used, g);
  long long start = root;
  root = 0, len = 0;
  used.assign(n + 1, 0);
  dfs1(start, INF, used, g);
  long long finish = root;
  used.assign(n + 1, 0);
  dfs1(start, finish, used, g);
  if ((long long)((res).size()) >= (n + 1) / 2) {
    cout << "PATH" << '\n';
    cout << (long long)((res).size()) << '\n';
    cout << res << '\n';
    return;
  }
  map<long long, vector<long long>> mp;
  used.assign(n + 1, 0);
  dfs2(start, 0, used, g, mp);
  vector<pair<long long, long long>> ans;
  for (auto it : mp) {
    for (long long i = 1; i < (long long)((it.second).size()); ++i) {
      ans.push_back({it.second[i - 1], it.second[i]});
    }
  }
  cout << "PAIRING" << '\n';
  cout << (long long)((ans).size()) << '\n';
  for (auto it : ans) {
    cout << it << '\n';
  }
}
void solve() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    query();
  }
}
