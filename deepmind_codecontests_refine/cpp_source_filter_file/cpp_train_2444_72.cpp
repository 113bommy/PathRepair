#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > vis(50, vector<bool>(50, 0));
bool dfs(char a[][51], int i, int j, int n, int m) {
  stack<pair<int, int> > s;
  s.push(make_pair(i, j));
  char c = a[i][j];
  while (!s.empty()) {
    i = s.top().first;
    j = s.top().second;
    s.pop();
    if (vis[i][j])
      continue;
    else
      vis[i][j] = 1;
    int count = 0;
    if (i > 0) {
      if (a[i - 1][j] == c) {
        if (!vis[i - 1][j]) {
          s.push(make_pair(i - 1, j));
        } else {
          count++;
        }
      }
    }
    if (j > 0) {
      if (a[i][j - 1] == c) {
        if (!vis[i][j - 1]) {
          s.push(make_pair(i, j - 1));
        } else {
          count++;
        }
      }
    }
    if (i < n - 1) {
      if (a[i + 1][j] == c) {
        if (!vis[i + 1][j]) {
          s.push(make_pair(i + 1, j));
        } else
          count++;
      }
    }
    if (j < m - 1) {
      if (a[i][j + 1] == c) {
        if (!vis[i][j + 1]) {
          s.push(make_pair(i, j + 1));
        } else {
          count++;
        }
      }
    }
    if (count >= 2) {
      return 1;
    }
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  char c[n][51];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> c[i][j];
  }
  bool p = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      p = dfs(c, i, j, n, m);
      if (p) break;
    }
    if (p) break;
  }
  if (p)
    cout << "YES";
  else
    cout << "NO";
}
