#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
string graph[51];
vector<vector<bool>> visited(51, vector<bool>(51, false));
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
long long n, m;
bool find_cycle = false;
void DFS(long long x, long long y, long long fromx, long long fromy,
         char colour) {
  if (x < 0 || x >= n || y < 0 || y >= m || colour != graph[x][y]) return;
  if (visited[x][y]) {
    find_cycle = true;
    return;
  }
  visited[x][y] = true;
  for (long long i = 0; i < 4; ++i) {
    long long nextx = x + dx[i];
    long long nexty = y + dy[i];
    if (nextx == fromx and nexty == fromy) continue;
    DFS(nexty, nexty, x, y, colour);
  }
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; ++i) cin >> graph[i];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (!visited[i][j]) DFS(i, j, -1, -1, graph[i][j]);
    }
  }
  cout << (find_cycle ? "Yes" : "No");
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) solve();
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  cerr << "My CLOCKS_PER_SEC= " << CLOCKS_PER_SEC << "\n";
  return 0;
}
