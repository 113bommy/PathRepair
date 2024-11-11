#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace std {
template <>
struct hash<pair<int, int>> {
  size_t operator()(const pair<int, int> &x) const {
    long long P = 38923, Q = 109797901;
    return (size_t)((x.first * P + x.second) % Q);
  }
};
};  // namespace std
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
void print(T t) {
  cout << t << endl;
}
template <typename T, typename... Args>
void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const int N = 15005;
int n, sent = 0;
unordered_map<int, pair<int, int>> cycle;
vector<int> s(N), vis(N);
vector<vector<int>> g(N);
bool find_cycle(int u, int p = -1) {
  if (vis[u] == sent) {
    s.push_back(u);
    return true;
  }
  s.push_back(u);
  vis[u] = sent;
  for (auto &v : g[u]) {
    if (v != p)
      if (find_cycle(v, u)) return true;
  }
  s.pop_back();
  return false;
}
vector<pair<int, int>> ans(N);
void dfs2(int u, int cp, int k, int p = -1) {
  ans[u] = {0, 0};
  for (auto &v : g[u]) {
    if (v == p || v == cycle[cp].first || v == cycle[cp].second) continue;
    dfs2(v, cp, k, u);
    ans[u].first += ans[v].first;
    ans[u].second += ans[v].second;
  }
  ans[u].second += (u == cp ? n - k + 1 : 1);
  ans[u].first += ans[u].second;
}
int dfs3(int u, int cp, int p = -1) {
  int ans = 0;
  for (auto &v : g[u]) {
    if (v == p || v == cycle[cp].first || v == cycle[cp].second) continue;
    ans += dfs3(v, cp, u);
  }
  return ans + 1;
}
queue<int> q, leaves;
int dfs1(int u) {
  sent++;
  int cnt = 0;
  q.push(u);
  vis[u] = sent;
  while ((int)(q).size()) {
    int uu = q.front();
    q.pop();
    cnt++;
    int nc = 0;
    for (auto &v : g[uu]) {
      if (vis[v] == sent || v == cycle[u].first || v == cycle[u].second)
        continue;
      q.push(v);
      vis[v] = sent;
      nc++;
    }
    if (nc == 0) leaves.push(uu);
  }
  int sol = 0;
  while ((int)(leaves).size()) {
    int csol = 0;
    int uu = leaves.front();
    leaves.pop();
    dfs2(uu, u, cnt, u);
    csol = ans[uu].first;
    sol = max(csol, sol);
  }
  return sol;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = min((int)0, (int)n); i < max((int)0, (int)n); i += 1) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sent++;
  find_cycle(0);
  vector<int> cyc;
  cyc.push_back(s.back());
  s.pop_back();
  while (s.back() != cyc.front()) cyc.push_back(s.back()), s.pop_back();
  cycle[cyc[0]] = {cyc[(int)(cyc).size() - 1], cyc[1]};
  cycle[cyc[(int)(cyc).size() - 1]] = {cyc[(int)(cyc).size() - 2], cyc[0]};
  for (int i = min((int)1, (int)(int)(cyc).size() - 1);
       i < max((int)1, (int)(int)(cyc).size() - 1); i += 1) {
    cycle[cyc[i]] = {cyc[i - 1], cyc[i + 1]};
  }
  vector<int> a((int)(cyc).size(), 0), b((int)(cyc).size(), 0);
  vector<int> da((int)(cyc).size()), db((int)(cyc).size());
  vector<int> stsz((int)(cyc).size());
  for (int i = min((int)0, (int)(int)(cyc).size());
       i < max((int)0, (int)(int)(cyc).size()); i += 1) {
    b[i] = dfs1(cyc[i]);
    db[i] = dfs3(cyc[i], cyc[i]);
    stsz[i] = db[i];
    dfs2(cyc[i], cyc[i], 0);
  }
  for (int j = min((int)1, (int)(int)(cyc).size());
       j < max((int)1, (int)(int)(cyc).size()); j += 1) {
    swap(a, b);
    swap(da, db);
    for (int i = min((int)0, (int)(int)(cyc).size());
         i < max((int)0, (int)(int)(cyc).size()); i += 1) {
      int i1 = (i + j);
      if (i1 >= (int)(cyc).size()) i1 %= (int)(cyc).size();
      int i2 = (i + j + (int)(cyc).size() - 1);
      if (i2 >= (int)(cyc).size()) i2 %= (int)(cyc).size();
      int i3 = (i + 1);
      if (i3 >= (int)(cyc).size()) i3 %= (int)(cyc).size();
      int ss1 = stsz[i];
      int ss2 = stsz[i1];
      int s1 = ans[cyc[i]].first - (da[i3] + ss1);
      int s2 = ans[cyc[i1]].first - (da[i] + ss2);
      if (a[i] + s2 > a[i3] + s1) {
        b[i] = a[i] + s2;
        db[i] = da[i] + ss2;
      } else {
        b[i] = a[i3] + s1;
        db[i] = da[i3] + ss1;
      }
    }
  }
  int sol = 0;
  for (int i = min((int)0, (int)(int)(cyc).size());
       i < max((int)0, (int)(int)(cyc).size()); i += 1)
    sol = max(sol, b[i]);
  print(sol);
  return 0;
}
