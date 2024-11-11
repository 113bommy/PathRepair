#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 8;
const long long sz = 1e5 + 5;
void f_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
string str[8];
map<pair<long long, long long>, long long> statue;
long long dx[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
long long dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
long long vis[8][8][20];
bool valid(long long x, long long y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}
bool dfs(long long x, long long y, long long shift) {
  if (shift >= 20 || vis[x][y][shift]) return false;
  vis[x][y][shift] = 1;
  if (x - shift >= 0 && str[x - shift][y] == 'S') return false;
  if (x == 0 && y == 7) return true;
  for (long long i = 0; i < 9; i++) {
    long long xx = x + dx[i], yy = y + dy[i];
    if (valid(xx, yy)) {
      if (xx - shift >= 0 && str[xx - shift][yy] == 'S') continue;
      if (dfs(xx, yy, shift + 1)) return true;
    }
  }
  return false;
}
int32_t main() {
  f_io();
  long long t = 1;
  while (t--) {
    for (long long i = 0; i < 8; i++) cin >> str[i];
    if (dfs(7, 0, 0))
      cout << "WIN"
           << "\n";
    else
      cout << "LOSE"
           << "\n";
  }
}
