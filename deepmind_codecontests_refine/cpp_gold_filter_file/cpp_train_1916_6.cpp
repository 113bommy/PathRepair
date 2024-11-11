#include <bits/stdc++.h>
using namespace std;
const long long MX = 100000;
const long long MOD = 1000000007;
long long fast_exp(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}
int X[] = {0, -1, 0, 1};
int Y[] = {-1, 0, 1, 0};
char arr[1111][1111];
int r, c;
bool isvalid(int x, int y) {
  if (x >= 0 && x < r && y >= 0 && y < c)
    return true;
  else
    return false;
}
int dis[1111][1111];
queue<pair<int, int> > q;
void bfs() {
  pair<int, int> end;
  for (int i = 0, _i = (r); i < _i; ++i) {
    for (int j = 0, _j = (c); j < _j; ++j) {
      dis[i][j] = 555555555;
      if (arr[i][j] == 'E') end.first = i, end.second = j;
    }
  }
  q.push(end);
  dis[end.first][end.second] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int x = cur.first, y = cur.second;
    q.pop();
    for (int i = 0, _i = (4); i < _i; ++i) {
      if (isvalid(x + X[i], y + Y[i]) && arr[x + X[i]][y + Y[i]] != 'T') {
        if (dis[x][y] + 1 < dis[x + X[i]][y + Y[i]]) {
          dis[x + X[i]][y + Y[i]] = 1 + dis[x][y];
          q.push(make_pair(x + X[i], y + Y[i]));
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  cin >> r >> c;
  pair<int, int> start;
  for (int i = 0, _i = (r); i < _i; ++i) {
    for (int j = 0, _j = (c); j < _j; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') start.first = i, start.second = j;
    }
  }
  bfs();
  int ans = 0;
  int cmp = dis[start.first][start.second];
  for (int i = 0, _i = (r); i < _i; ++i) {
    for (int j = 0, _j = (c); j < _j; ++j) {
      if (arr[i][j] != 'S' && arr[i][j] != 'T' && arr[i][j] != 'E') {
        if (dis[i][j] <= cmp) ans += (arr[i][j] - '0');
      }
    }
  }
  cout << ans;
  return 0;
}
