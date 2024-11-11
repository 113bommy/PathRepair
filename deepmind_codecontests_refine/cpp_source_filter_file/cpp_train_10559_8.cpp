#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n;
vector<vector<long long>> g, gr;
vector<long long> ts, used;
void dfs(long long v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  ts.push_back(v);
}
void dfs2(long long v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  g.resize(n), gr.resize(n), used.resize(n);
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      long long x;
      cin >> x;
      if (x > 0 && j != i) {
        g[i].push_back(j);
        gr[j].push_back(i);
      }
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  long long cnt = 0;
  reverse(ts.begin(), ts.end());
  used.assign(n, 0);
  for (long long i = 0; i < ts.size(); ++i) {
    if (!used[ts[i]]) {
      cnt++;
      dfs2(ts[i]);
    }
  }
  if (cnt > 1) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
