#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, h[maxn][maxn];
string str[maxn];
set<int> x[maxn], y[maxn];
void bfs(int a, int b) {
  queue<pair<int, int>> q;
  h[a][b] = 0;
  q.push({a, b});
  while (!q.empty()) {
    pair<int, int> v = q.front();
    q.pop();
    while (x[v.first].size()) {
      if (h[v.first][*x[v.first].begin()] == -1) {
        h[v.first][*x[v.first].begin()] = h[v.first][v.second] + 1;
        q.push({v.first, *x[v.first].begin()});
      }
      x[v.first].erase(x[v.first].begin());
    }
    if (v.second >= 0) {
      while (y[v.second].size()) {
        if (h[*y[v.second].begin()][v.second] == -1) {
          h[*y[v.second].begin()][v.second] = h[v.first][v.second] + 1;
          q.push({*y[v.second].begin(), v.second});
        }
        y[v.second].erase(y[v.second].begin());
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      h[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  x[0].insert(-1);
  x[n - 1].insert(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == '#') {
        x[i].insert(j);
        y[j].insert(i);
      }
    }
  }
  bfs(0, -1);
  cout << h[n - 1][m] - 1;
}
