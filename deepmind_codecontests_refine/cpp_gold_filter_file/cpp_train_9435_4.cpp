#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 100010;
int t[N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
pair<int, int> getCell(int x) { return {x / m, x % m}; }
int getX(pair<int, int> p) { return p.first * m + p.second; }
bool can(pair<int, int> currCell) {
  pair<int, int> targetCell = getCell(t[getX(currCell)]);
  for (int i = 0; i < (4); ++i) {
    int xx = currCell.first + dx[i];
    int yy = currCell.second + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
      pair<int, int> cell = getCell(t[getX({xx, yy})]);
      if (abs(cell.first - targetCell.first) +
              abs(cell.second - targetCell.second) <=
          1) {
        return false;
      }
    }
  }
  return true;
}
int check() {
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      if (!can({i, j})) return getX({i, j});
    }
  }
  return -1;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (n * m); ++i) t[i] = i;
  random_shuffle(t, t + m * n);
  while (clock() < 1900) {
    int pos = check();
    if (pos == -1) {
      cout << "YES\n";
      for (int i = 0; i < (n); ++i) {
        for (int j = 0; j < (m); ++j) {
          cout << t[i * m + j] + 1 << ' ';
        }
        cout << '\n';
      }
      return 0;
    }
    int x = rand() % (n * m);
    swap(t[pos], t[x]);
  }
  cout << "NO\n";
}
