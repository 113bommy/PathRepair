#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
std::vector<int> v[5005];
std::vector<pair<int, int>> cnt;
bool vis[5005];
bool vis1[5005];
int c;
void dfs(int u) {
  vis[u] = true;
  for (auto x : v[u]) {
    if (!vis[x]) dfs(x);
  }
}
void dfs2(int u) {
  vis1[u] = true;
  c++;
  for (auto x : v[u]) {
    if (!vis1[x] && !vis[x]) dfs2(x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, x, y;
  long long res = 0;
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    v[x].emplace_back(y);
  }
  dfs(s);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      memset(vis1, 0, sizeof(bool) * (n + 1));
      c = 0;
      dfs2(i);
      cnt.emplace_back(make_pair(c, i));
    }
  }
  sort(cnt.begin(), cnt.end(), greater<pair<int, int>>());
  for (size_t i = 0; i < cnt.size(); ++i) {
    if (!vis[cnt[i].second]) {
      dfs(cnt[i].second);
      res++;
    }
  }
  cout << res;
  return 0;
}
