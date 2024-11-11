#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const int N = 1e6 + 1;
int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
long long div_ceil(long long numerator, long long denominator) {
  std::lldiv_t res = std::div(numerator, denominator);
  return res.rem ? (res.quot + 1) : res.quot;
}
void IO() {}
set<int> s1;
set<int> s2;
int visited[50000];
void dfs(int x, bool what, vector<int> graph[]) {
  visited[x] = 1;
  if (what)
    s1.insert(x);
  else
    s2.insert(x);
  for (int p : graph[x]) {
    if (!visited[p]) dfs(p, !what, graph);
  }
}
void decode() {
  int n;
  cin >> n;
  vector<int> graph[n + 1];
  memset(visited, 0, sizeof(visited));
  int src = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    src = x;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dfs(src, true, graph);
  int l1 = s1.size();
  int l2 = s2.size();
  cout << ((long long)l1 * l2 - (n - 1)) << endl;
}
int32_t main() {
  IO();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    decode();
  }
  return 0;
}
