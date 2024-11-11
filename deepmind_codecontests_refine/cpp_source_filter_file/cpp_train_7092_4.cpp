#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
vector<vector<pair<int, int>>> graph;
vector<int> sz, cnt;
int n, u, v, w;
bool lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
void dfs(int x, int par) {
  sz[x]++;
  for (auto child : graph[x]) {
    if (child.first == par) continue;
    dfs(child.first, x);
    sz[x] += sz[child.first];
    if (lucky(child.second)) {
      cnt[x] += sz[child.first];
    } else {
      cnt[x] += cnt[child.first];
    }
  }
}
void dfs2(int x, int par) {
  for (auto child : graph[x]) {
    if (child.first == par) continue;
    int v = child.first;
    bool islucky = lucky(child.second);
    if (islucky) {
      cnt[v] += (n - sz[v]);
    } else {
      cnt[v] = cnt[x];
    }
    dfs2(v, x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  graph.assign(n, vector<pair<int, int>>());
  sz.assign(n, 0);
  cnt.assign(n, 0);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  dfs(0, -1);
  dfs2(0, -1);
  long long res = 0;
  for (int x : cnt) {
    res += x * (x - 1);
  }
  cout << res << "\n";
}
