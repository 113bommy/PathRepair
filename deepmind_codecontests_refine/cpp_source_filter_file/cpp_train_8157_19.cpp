#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7, maxm = 1e3 + 100;
vector<pair<long long, pair<long long, char> > > store[maxm];
bool visited[maxm];
pair<long long, char> p[maxm];
long long cn = 1;
vector<pair<long long, char> > ans;
void dfs(long long u, long long edge, char direc) {
  for (auto w : store[u]) {
    if (!visited[w.second.first]) {
      visited[w.second.first] = 1;
      dfs(w.first, w.second.first, w.second.second);
    }
  }
  if (edge == -1) return;
  p[edge] = {cn, direc};
  ans.push_back({edge, direc});
  cn++;
}
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    long long u, v;
    cin >> u >> v;
    store[u].push_back({v, {i, '-'}});
    store[v].push_back({u, {i, '+'}});
  }
  long long cnt = 0;
  for (long long i = 0; i <= 6; ++i)
    if (store[i].size() & 1) cnt++;
  if (cnt > 2) {
    cout << "No Solution\n";
    exit(0);
  }
  long long l = -1;
  for (long long i = 0; i <= 6; ++i) {
    if (store[i].size() > 0) {
      l = i;
      if (store[i].size() % 2 != 0) break;
    }
  }
  dfs(l, -1, -1);
  for (long long i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cout << "No solution\n";
      exit(0);
    }
  }
  for (long long i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
}
static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
