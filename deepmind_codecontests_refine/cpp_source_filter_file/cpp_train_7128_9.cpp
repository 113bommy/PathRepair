#include <bits/stdc++.h>
using namespace std;
int n, m;
int n_max = 2e3 + 5;
vector<vector<char> > grid(n_max, vector<char>(n_max));
void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}
bool finished() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') return false;
    }
  }
  return true;
}
bool all_obs() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') return false;
    }
  }
  return true;
}
int edge_count(int i, int j) {
  int count = 0;
  if (i < 0 || j < 0 || i >= n || j >= m) return count;
  if (grid[i][j] != '.') return count;
  if (i > 0 && grid[i - 1][j] == '.') count++;
  if (i < n - 1 && grid[i + 1][j] == '.') count++;
  if (j > 0 && grid[i][j - 1] == '.') count++;
  if (j < m - 1 && grid[i][j + 1] == '.') count++;
  return count;
}
void solve() {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') count++;
    }
  }
  if (count % 2 == 1) {
    cout << "Not unique" << endl;
    return;
  }
  queue<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        int count = edge_count(i, j);
        if (count == 1) {
          q.emplace(i, j);
        }
      }
    }
  }
  if (q.empty()) {
    cout << "Not unique" << endl;
    return;
  }
  while (!q.empty()) {
    auto next = q.front();
    q.pop();
    int i = next.first;
    int j = next.second;
    if (grid[next.first][next.second] != '.') continue;
    if (i > 0 && grid[i - 1][j] == '.') {
      grid[i - 1][j] = '^';
      grid[i][j] = 'v';
      if (edge_count(i - 2, j) == 1) q.emplace(i - 2, j);
      if (edge_count(i + 1, j) == 1) q.emplace(i + 1, j);
      if (edge_count(i - 1, j - 1) == 1) q.emplace(i - 1, j - 1);
      if (edge_count(i - 1, j + 1) == 1) q.emplace(i - 1, j + 1);
      if (edge_count(i, j - 1) == 1) q.emplace(i, j - 1);
      if (edge_count(i, j + 1) == 1) q.emplace(i, j + 1);
    }
    if (i < n - 1 && grid[i + 1][j] == '.') {
      grid[i + 1][j] = 'v';
      grid[i][j] = '^';
      if (edge_count(i - 1, j) == 1) q.emplace(i - 1, j);
      if (edge_count(i + 2, j) == 1) q.emplace(i + 2, j);
      if (edge_count(i, j - 1) == 1) q.emplace(i, j - 1);
      if (edge_count(i, j + 1) == 1) q.emplace(i, j + 1);
      if (edge_count(i + 1, j - 1) == 1) q.emplace(i + 1, j - 1);
      if (edge_count(i + 1, j + 1) == 1) q.emplace(i + 1, j + 1);
    }
    if (j > 0 && grid[i][j - 1] == '.') {
      grid[i][j - 1] = '<';
      grid[i][j] = '>';
      if (edge_count(i, j - 2) == 1) q.emplace(i, j - 2);
      if (edge_count(i, j + 1) == 1) q.emplace(i, j + 1);
      if (edge_count(i - 1, j - 1) == 1) q.emplace(i - 1, j - 1);
      if (edge_count(i - 1, j) == 1) q.emplace(i - 1, j);
      if (edge_count(i + 1, j - 1) == 1) q.emplace(i + 1, j - 1);
      if (edge_count(i + 1, j) == 1) q.emplace(i + 1, j);
    }
    if (i < m - 1 && grid[i][j + 1] == '.') {
      grid[i][j + 1] = '>';
      grid[i][j] = '<';
      if (edge_count(i, j - 1) == 1) q.emplace(i, j - 1);
      if (edge_count(i, j + 2) == 1) q.emplace(i, j + 2);
      if (edge_count(i - 1, j) == 1) q.emplace(i - 1, j);
      if (edge_count(i - 1, j + 1) == 1) q.emplace(i - 1, j + 1);
      if (edge_count(i + 1, j) == 1) q.emplace(i + 1, j);
      if (edge_count(i + 1, j + 1) == 1) q.emplace(i + 1, j + 1);
    }
  }
  if (finished()) {
    print();
    return;
  } else {
    cout << "Not unique" << endl;
    return;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c;
    }
  }
  if (all_obs()) {
    print();
    return 0;
  }
  solve();
  return 0;
}
