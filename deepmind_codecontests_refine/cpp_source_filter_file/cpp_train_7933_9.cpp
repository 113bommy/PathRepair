#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int dx[] = {0, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, -1, 1, -1, 1, -1};
string a[10];
int dp[10][10][200];
void Load() {
  for (int i = 0; i < 8; i++) cin >> a[i];
}
bool good(int x, int y, int step) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8 &&
      (x - step < 0 || a[x - step][y] == '.') &&
      (x - step + 1 < 0 || a[x - step + 1][y] == '.'))
    return true;
  return false;
}
bool go(int x, int y, int step) {
  if (step > 100) return true;
  if (x == 0 && y == 7) return true;
  int &res = dp[x][y][step];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < 9; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (good(nx, ny, step + 1)) res |= go(nx, ny, step + 1);
  }
  return res;
}
void Solve() {
  memset(dp, -1, sizeof(dp));
  if (go(7, 0, 0))
    cout << "WIN";
  else
    cout << "LOSE";
}
int main() {
  Load();
  Solve();
  return 0;
}
