#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct ioi {
  int x, y, tt, s;
};
ioi st, en;
int n, m, a[maxn][maxn];
bool kt[maxn][maxn][4];
string s[maxn];
const string mau = "+-|^><vLRUD*";
const int c[12][4] = {{15, 15, 15, 15}, {10, 5, 10, 5},  {5, 10, 5, 10},
                      {4, 2, 1, 8},     {2, 1, 8, 4},    {8, 4, 2, 1},
                      {1, 8, 4, 2},     {7, 11, 13, 14}, {13, 14, 7, 11},
                      {11, 13, 14, 7},  {14, 7, 11, 13}, {0, 0, 0, 0}};
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int doi[4] = {1, 0, 3, 2};
queue<ioi> que;
void nhap() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < 12; ++k)
        if (mau[k] == s[i][j]) {
          a[i][j] = k;
          break;
        }
    }
  cin >> st.x >> st.y;
  cin >> en.x >> en.y;
}
int bit(int x, int d) { return (x >> d) & 1; }
void BFS() {
  kt[st.x][st.y][0] = true;
  que.push(st);
  while (!que.empty()) {
    int x = que.front().x;
    int y = que.front().y;
    int tt = que.front().tt;
    int s = que.front().s;
    que.pop();
    if (x == en.x && y == en.y) {
      cout << s;
      exit(0);
    }
    if (!kt[x][y][(tt + 1) % 4]) {
      ioi tmp;
      tmp.x = x;
      tmp.y = y;
      tmp.s = s + 1;
      tmp.tt = (tt + 1) % 4;
      que.push(tmp);
      kt[x][y][(tt + 1) % 4] = true;
    }
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
      if (kt[xx][yy][tt]) continue;
      if (bit(c[a[x][y]][tt], 3 - i) == 1 &&
          bit(c[a[xx][yy]][tt], doi[i]) == 1) {
        ioi tmp;
        tmp.x = xx;
        tmp.y = yy;
        tmp.tt = tt;
        tmp.s = s + 1;
        que.push(tmp);
        kt[xx][yy][tt] = true;
      }
    }
  }
}
int main() {
  nhap();
  BFS();
  cout << -1;
  return 0;
}
