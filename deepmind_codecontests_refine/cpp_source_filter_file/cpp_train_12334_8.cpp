#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 100;
string s[maxn];
int n, m;
queue<pair<int, int> > q;
int d[maxn][maxn] = {};
pair<int, int> mt[maxn][maxn];
int sz = 0, sz2 = 0;
bool mark[maxn][maxn];
void f(int i1, int j1, int i2, int j2) {
  mark[i1][j1] = mark[i2][j2] = true;
  mt[i1][j1] = pair<int, int>(i2, j2), mt[i2][j2] = pair<int, int>(i1, j1);
  if (i2 && !mark[i2 - 1][j2]) {
    d[i2 - 1][j2]--;
    if (d[i2 - 1][j2] == 1) q.push(pair<int, int>(i2 - 1, j2));
  }
  if (j2 && !mark[i2][j2 - 1]) {
    d[i2][j2 - 1]--;
    if (d[i2][j2 - 1] == 1) q.push(pair<int, int>(i2, j2 - 1));
  }
  if (i2 < n - 1 && !mark[i2 + 1][j2]) {
    d[i2 + 1][j2]--;
    if (d[i2 + 1][j2] == 1) q.push(pair<int, int>(i2 + 1, j2));
  }
  if (j2 < m - 1 && !mark[i2][j2 + 1]) {
    d[i2][j2 + 1]++;
    if (d[i2][j2 + 1] == 1) q.push(pair<int, int>(i2, j2 + 1));
  }
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i) d[i][j]++;
      if (j) d[i][j]++;
      if (i < n - 1) d[i][j]++;
      if (j < m - 1) d[i][j]++;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        if (i) d[i - 1][j]--;
        if (j) d[i][j - 1]--;
        if (i < n - 1) d[i + 1][j]--;
        if (j < m - 1) d[i][j + 1]--;
        mark[i][j] = true;
        continue;
      }
      sz++;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') continue;
      if (d[i][j] == 0) {
        cout << "Not unique\n";
        return 0;
      }
      if (d[i][j] == 1) q.push(pair<int, int>(i, j));
    }
  while (q.size()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    if (mark[x][y]) continue;
    if (d[x][y] == 0) {
      cout << "Not unique\n";
      return 0;
    }
    sz2 += 2;
    if (x && mark[x - 1][y] == false) {
      f(x, y, x - 1, y);
      continue;
    }
    if (y && !mark[x][y - 1]) {
      f(x, y, x, y - 1);
      continue;
    }
    if (x < n - 1 && !mark[x + 1][y]) {
      f(x, y, x + 1, y);
      continue;
    }
    if (y < m - 1 && !mark[x][y + 1]) {
      f(x, y, x, y + 1);
      continue;
    }
  }
  if (sz != sz2) {
    cout << "Not unique\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] != '*') {
        if (mt[i][j].first == i) {
          if (mt[i][j].second < j) continue;
          s[i][j] = '<';
          s[i][j + 1] = '>';
        } else {
          if (mt[i][j].first < i) continue;
          s[i][j] = '^';
          s[i + 1][j] = 'v';
        }
      }
  for (int i = 0; i < n; i++) cout << s[i] << '\n';
  return 0;
}
