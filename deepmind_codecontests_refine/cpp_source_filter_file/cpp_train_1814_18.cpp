#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& aaaa, C bbbb) {
  aaaa = min(aaaa, bbbb);
}
template <class C>
void maxi(C& aaaa, C bbbb) {
  aaaa = max(aaaa, bbbb);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
const int MX = 21;
string board[MX];
int msk[MX][MX];
const int M = 1 << 8;
int dst[MX][MX][M];
const int INF = 1e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> price(8, -INF);
  int bomb = 7;
  int tre = 0;
  pair<pair<int, int>, int> start;
  for (int i = 0; i < (n); ++i) {
    cin >> board[i];
    for (int j = 0; j < (m); ++j) {
      if (board[i][j] == 'S') {
        board[i][j] = '.';
        start = pair<pair<int, int>, int>(pair<int, int>(i, j), 0);
      } else if (board[i][j] == 'B') {
        msk[i][j] = 1 << bomb;
        --bomb;
        board[i][j] = '#';
      } else if (board[i][j] >= '1' && board[i][j] <= '7') {
        int ind = board[i][j] - '1';
        maxi(tre, ind + 1);
        msk[i][j] = 1 << ind;
        board[i][j] = '#';
      }
    }
  }
  for (int i = (n - 2); i >= (0); --i) {
    for (int j = 0; j < (m); ++j) msk[i][j] |= msk[i + 1][j];
  }
  for (int i = 0; i < (tre); ++i) cin >> price[i];
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      for (int k = 0; k < (M); ++k) dst[i][j][k] = INF;
  dst[start.first.first][start.first.second][start.second] = 0;
  queue<pair<pair<int, int>, int> > Q;
  Q.push(start);
  while (!Q.empty()) {
    pair<pair<int, int>, int> f = Q.front();
    Q.pop();
    int x = f.first.first;
    int y = f.first.second;
    int ms = f.second;
    int d = dst[x][y][ms];
    for (int t = 0; t < (4); ++t) {
      int xx = x + dx[t];
      int yy = y + dy[t];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || board[xx][yy] != '.')
        continue;
      int mms = ms;
      if (t == 1)
        mms = ms ^ msk[x][y];
      else if (t == 3)
        mms = ms ^ msk[xx][yy];
      if (dst[xx][yy][mms] == INF) {
        dst[xx][yy][mms] = d + 1;
        Q.push(pair<pair<int, int>, int>(pair<int, int>(xx, yy), mms));
      }
    }
  }
  long long res = 0;
  for (int k = 0; k < (M); ++k) {
    long long val = -dst[start.first.first][start.first.second][k];
    for (int i = 0; i < (8); ++i)
      if (k & (1 << i)) val += price[i];
    maxi(res, val);
  }
  cout << res << endl;
  return 0;
}
