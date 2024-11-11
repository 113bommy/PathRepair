#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > q;
char a[2003][2003];
int n, m, used;
bool ok(int i, int j) {
  if (a[i][j] != '.') return false;
  if ((i < 0) || (i > n) || (j < 0) || (j > m)) return false;
  int ans = 0;
  if (a[i - 1][j] == '.') ++ans;
  if (a[i + 1][j] == '.') ++ans;
  if (a[i][j - 1] == '.') ++ans;
  if (a[i][j + 1] == '.') ++ans;
  return (ans == 1);
}
void change(int i, int j) {
  if (a[i - 1][j] == '.') {
    a[i - 1][j] = '^';
    a[i][j] = 'v';
    if (ok(i - 2, j)) q.push(make_pair(i - 2, j));
    if (ok(i - 1, j - 1)) q.push(make_pair(i - 1, j - 1));
    if (ok(i - 1, j + 1)) q.push(make_pair(i - 1, j + 1));
  } else if (a[i + 1][j] == '.') {
    a[i][j] = '^';
    a[i + 1][j] = 'v';
    if (ok(i + 2, j)) q.push(make_pair(i + 2, j));
    if (ok(i + 1, j - 1)) q.push(make_pair(i + 1, j - 1));
    if (ok(i + 1, j + 1)) q.push(make_pair(i + 1, j + 1));
  } else if (a[i][j - 1] == '.') {
    a[i][j - 1] = '<';
    a[i][j] = '>';
    if (ok(i, j - 2)) q.push(make_pair(i, j - 2));
    if (ok(i - 1, j - 1)) q.push(make_pair(i - 1, j - 1));
    if (ok(i + 1, j - 1)) q.push(make_pair(i + 1, j - 1));
  } else if (a[i][j + 1] == '.') {
    a[i][j] = '<';
    a[i][j + 1] = '>';
    if (ok(i, j + 2)) q.push(make_pair(i, j + 2));
    if (ok(i - 1, j + 1)) q.push(make_pair(i - 1, j + 1));
    if (ok(i + 1, j + 1)) q.push(make_pair(i + 1, j + 1));
  } else {
    used -= 2;
  }
  used += 2;
}
int main() {
  used = 0;
  pair<int, int> temp;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i] + 1;
  for (int i = 0; i < n; ++i) {
    a[i][0] = '*';
    a[i][m + 1] = '*';
  }
  for (int i = 0; i < m; ++i) {
    a[0][i] = '*';
    a[n + 1][i] = '*';
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == '*') ++used;
      if (ok(i, j)) q.push(make_pair(i, j));
    }
  }
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    if (a[temp.first][temp.second] != '.') continue;
    change(temp.first, temp.second);
  }
  if (used != n * m) {
    cout << "Not unique";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
