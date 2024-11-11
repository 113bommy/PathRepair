#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:108777216")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T>
using pair2 = pair<T, T>;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
int v, e;
vector<vector<int>> graph;
vector<bool> used;
void dfs(int u) {
  if (used[u]) return;
  used[u] = true;
  v++;
  e += graph[u].size();
  for (int to : graph[u]) dfs(to);
}
int main() {
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    graph[--from].push_back(--to);
    graph[to].push_back(from);
  }
  used.resize(n, false);
  for (int i = 0; i < n; i++) {
    v = 0;
    e = 0;
    dfs(i);
    if (v * (v - 1) != e) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
