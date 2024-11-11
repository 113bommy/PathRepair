#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e3;
const long long MAXN = 1e5 + 100;
long long n, k, Dis[2][MAXN];
char a[2][MAXN];
vector<pair<long long, long long> > adj[2][MAXN];
bool val(long long x, long long y) {
  return a[x][y] == '-' && x < 2 && x >= 0 && y < n && y >= 0;
}
void bfs(long long x, long long y) {
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < n; j++) Dis[i][j] = INF;
  Dis[x][y] = 0;
  queue<pair<long long, long long> > q;
  q.push({x, y});
  while (!q.empty()) {
    pair<long long, long long> pi;
    pi = q.front();
    q.pop();
    long long u = pi.first, v = pi.second;
    for (auto t : adj[u][v]) {
      if (Dis[t.first][t.second] == INF) {
        if (Dis[u][v] + 1 <= t.second)
          Dis[t.first][t.second] = Dis[u][v] + 1, q.push({t.first, t.second});
      }
    }
  }
}
void check_adj() {
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < n; j++) {
      cout << "-------\n";
      cout << i + 1 << " " << j + 1 << endl;
      for (auto x : adj[i][j])
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
  }
}
void check() {
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < n; j++) cout << Dis[i][j] << " ";
    cout << endl;
  }
}
int main() {
  cin >> n >> k;
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < n; j++) cin >> a[i][j];
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < n; j++) {
      if (val(i, j - 1)) adj[i][j].push_back({i, j - 1});
      if (val(i, j + 1)) adj[i][j].push_back({i, j + 1});
      if (val(i + 1, j + k)) adj[i][j].push_back({i + 1, j + k});
      if (val(i - 1, j + k)) adj[i][j].push_back({i - 1, j + k});
    }
  }
  bfs(0, 0);
  bool isAns = false;
  for (long long i = 0; i < 2; i++) {
    for (long long j = n - 1; j >= n - k; j--) {
      if (Dis[i][j] != INF) isAns = true;
    }
  }
  if (isAns)
    cout << "YES";
  else
    cout << "NO";
}
