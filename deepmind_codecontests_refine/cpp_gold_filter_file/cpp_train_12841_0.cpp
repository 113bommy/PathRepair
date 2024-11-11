#include <bits/stdc++.h>
using namespace std;
int n;
int values[400][400];
int mem[400][400][2];
void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> values[i][j];
      mem[i][j][0] = 0;
      mem[i][j][1] = 0;
    }
  }
}
void add(int x1, int x2, int c, int v) {
  if (x1 > x2) return;
  int lo = max(0, c - n + 1), hi = min(n - 1, c);
  if (x1 < lo || x2 > hi) return;
  int y1 = c - x1, y2 = c - x2;
  v += values[x1][y1] + values[x2][y2];
  if (x1 == x2) v -= values[x1][y1];
  if (v > mem[x1][x2][c & 1]) mem[x1][x2][c & 1] = v;
}
void solve() {
  mem[0][0][0] = values[0][0];
  for (int c = 0; c <= 2 * n - 3; ++c) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mem[i][j][(c + 1) & 1] = -1000 * 400 * 2;
      }
    }
    int lo = max(0, c - n + 1), hi = min(n - 1, c);
    for (int x1 = lo; x1 <= hi; ++x1) {
      for (int x2 = x1; x2 <= hi; ++x2) {
        add(x1, x2, c + 1, mem[x1][x2][c & 1]);
        add(x1 + 1, x2, c + 1, mem[x1][x2][c & 1]);
        add(x1, x2 + 1, c + 1, mem[x1][x2][c & 1]);
        add(x1 + 1, x2 + 1, c + 1, mem[x1][x2][c & 1]);
      }
    }
  }
}
int main() {
  read();
  solve();
  cout << mem[n - 1][n - 1][0] << endl;
  return 0;
}
