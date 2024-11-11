#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
template <typename T>
void read(vector<T> &a);
const long long MX = 2e5 + 5;
vector<vector<long long>> g(MX);
bool dfs(long long root, long long len) {
  if (len >= 2) return 0;
  for (long long i : g[root]) {
    bool lvalid = dfs(i, len + 1);
    if (!lvalid) return 0;
  }
  return 1;
}
inline void solve() {
  long long n, m;
  cin >> n >> m;
  set<pair<long long, long long>> st;
  vector<vector<long long>> lg(n + 1);
  vector<pair<long long, long long>> ma;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    st.insert({x, y});
    ma.emplace_back(x, y);
    lg[x].push_back(y);
    lg[y].push_back(x);
  }
  long long root = 1;
  set<pair<long long, long long>> te = st;
  queue<pair<long long, bool>> q;
  q.push({1, 1});
  map<pair<long long, long long>, bool> dirs;
  vector<bool> vis(n + 1, 0);
  vis[1] = 1;
  while (!q.empty()) {
    auto [root, dir] = q.front();
    q.pop();
    for (long long i : lg[root]) {
      if (dir) {
        bool found = 0;
        if (te.find({root, i}) != te.end()) {
          found = 1;
          dirs[{root, i}] = 1;
          te.erase({root, i});
        } else if (te.find({i, root}) != te.end()) {
          found = 1;
          dirs[{i, root}] = 0;
          te.erase({i, root});
        }
        if (found) g[i].push_back(root);
        if (!vis[i]) {
          q.push({i, 0});
          vis[i] = 0;
        }
      } else {
        bool found = 0;
        if (te.find({root, i}) != te.end()) {
          found = 1;
          dirs[{root, i}] = 0;
          te.erase({root, i});
        } else if (te.find({i, root}) != te.end()) {
          found = 1;
          dirs[{i, root}] = 1;
          te.erase({i, root});
        }
        if (found) g[root].push_back(i);
        if (!vis[i]) {
          q.push({i, 0});
          vis[i] = 1;
        }
      }
    }
  }
  bool valid = 1;
  for (long long i = 1; i < n + 1; i++) {
    valid = (valid && dfs(i, 0));
  }
  if (valid) {
    cout << "YES" << NL;
    for (auto [x, y] : ma) cout << dirs[{x, y}];
    cout << NL;
    return;
  }
  vis.assign(n + 1, 0);
  dirs.clear();
  te = st;
  q.push({1, 0});
  vis[1] = 1;
  for (long long i = 0; i < n + 1; i++) g[i].clear();
  while (!q.empty()) {
    auto [root, dir] = q.front();
    q.pop();
    for (long long i : lg[root]) {
      if (dir) {
        bool found = 0;
        if (te.find({root, i}) != te.end()) {
          found = 1;
          dirs[{root, i}] = 1;
          te.erase({root, i});
        } else if (te.find({i, root}) != te.end()) {
          found = 1;
          dirs[{i, root}] = 0;
          te.erase({i, root});
        }
        if (found) g[i].push_back(root);
        if (!vis[i]) {
          q.push({i, 0});
          vis[i] = 0;
        }
      } else {
        bool found = 0;
        if (te.find({root, i}) != te.end()) {
          found = 1;
          dirs[{root, i}] = 0;
          te.erase({root, i});
        } else if (te.find({i, root}) != te.end()) {
          found = 1;
          dirs[{i, root}] = 1;
          te.erase({i, root});
        }
        if (found) g[root].push_back(i);
        if (!vis[i]) {
          q.push({i, 0});
          vis[i] = 1;
        }
      }
    }
  }
  valid = 1;
  for (long long i = 1; i < n + 1; i++) {
    valid = (valid && dfs(i, 0));
  }
  if (valid) {
    cout << "YES" << NL;
    for (auto [x, y] : ma) cout << dirs[{x, y}];
    cout << NL;
    return;
  }
  cout << "NO" << NL;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  fflush(stdin);
  fflush(stdout);
  return 0;
}
template <typename T>
void read(vector<T> &a) {
  for (auto &it : a) cin >> it;
}
