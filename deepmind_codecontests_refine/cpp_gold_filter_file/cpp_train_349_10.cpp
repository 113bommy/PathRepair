#include <bits/stdc++.h>
using namespace std;
vector<long long> g[1234];
bool has_reached[1234][1234];
pair<long long, long long> parent[1234][1234];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long from, to;
    cin >> from >> to;
    g[from].push_back(to);
    g[to].push_back(from);
    continue;
  }
  memset(has_reached, false, sizeof has_reached);
  has_reached[1][n] = true;
  parent[1][n] = {0, 0};
  queue<pair<long long, long long> > q;
  q.push(make_pair(1, n));
  while (!q.empty()) {
    long long u = q.front().first;
    long long v = q.front().second;
    q.pop();
    if (u == v) continue;
    for (auto x : g[u]) {
      for (auto y : g[v]) {
        if (has_reached[x][y] == false) {
          has_reached[x][y] = true;
          q.push(make_pair(x, y));
          parent[x][y] = {u, v};
        }
      }
    }
  }
  if (has_reached[n][1] == false) {
    cout << -1 << endl;
    cout.flush();
    return 0;
  }
  vector<long long> v1;
  v1.clear();
  vector<long long> v2;
  v2.clear();
  long long a = n;
  long long b = 1;
  while (a + b) {
    v2.push_back(b);
    v1.push_back(a);
    int foo = parent[a][b].first;
    b = parent[a][b].second;
    a = foo;
  }
  cout << v2.size() - 1 << endl;
  for (auto x : v2) {
    cout << x << " ";
  }
  cout << endl;
  cout.flush();
  for (auto y : v1) {
    cout << y << " ";
  }
  cout.flush();
  return 0;
}
