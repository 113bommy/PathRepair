#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[2015][2015];
queue<pair<int, int> > q;
bool f(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return 0;
  }
  int out = 0;
  if (x == 0 || a[x - 1][y] != '.') {
    out++;
  }
  if (x == n - 1 || a[x + 1][y] != '.') {
    out++;
  }
  if (y == 0 || a[x][y - 1] != '.') {
    out++;
  }
  if (y == m - 1 || a[x][y + 1] != '.') {
    out++;
  }
  if (out == 3 && a[x][y] == '.') {
    return 1;
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f(i, j) == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    if (f(i, j) == 1) {
      if (i != 0 && a[i - 1][j] == '.') {
        a[i][j] = 'v';
        a[i - 1][j] = '^';
        if (f(i - 2, j) == 1) {
          q.push(make_pair(i - 2, j));
        }
        if (f(i - 1, j - 1) == 1) {
          q.push(make_pair(i - 1, j - 1));
        }
        if (f(i - 1, j + 1) == 1) {
          q.push(make_pair(i - 1, j + 1));
        }
      }
      if (f(i, j) == 1 && (i != n - 1 && a[i + 1][j] == '.')) {
        a[i][j] = '^';
        a[i + 1][j] = 'v';
        if (f(i + 2, j) == 1) {
          q.push(make_pair(i + 2, j));
        }
        if (f(i + 1, j - 1) == 1) {
          q.push(make_pair(i + 1, j - 1));
        }
        if (f(i + 1, j + 1) == 1) {
          q.push(make_pair(i + 1, j + 1));
        }
      }
      if (f(i, j) == 1 && (j != 0 && a[i][j - 1] == '.')) {
        a[i][j] = '>';
        a[i][j - 1] = '<';
        if (f(i, j - 2) == 1) {
          q.push(make_pair(i, j - 2));
        }
        if (f(i + 1, j - 1) == 1) {
          q.push(make_pair(i + 1, j - 1));
        }
        if (f(i - 1, j - 1) == 1) {
          q.push(make_pair(i - 1, j - 1));
        }
      }
      if (f(i, j) == 1 && (j != m - 1 && a[i][j + 1] == '.')) {
        a[i][j] = '<';
        a[i][j + 1] = '>';
        if (f(i, j + 2) == 1) {
          q.push(make_pair(i, j + 2));
        }
        if (f(i + 1, j + 1) == 1) {
          q.push(make_pair(i + 1, j + 1));
        }
        if (f(i - 1, j + 1) == 1) {
          q.push(make_pair(i - 1, j + 1));
        }
      }
    }
    q.pop();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        cout << "Not unique";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
