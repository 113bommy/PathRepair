#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;
long long readInt() {
  bool minus1 = false;
  long long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus1 = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus1)
    return -result;
  else
    return result;
}
const int N = 1111;
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
string dirs = "UDRL";
int directiony[N];
int directionx[N];
long long curx = 5000000001LL, cury = 5000000001LL;
vector<long long> xler;
vector<long long> yler;
void add() {
  xler.push_back(curx);
  xler.push_back(curx - 1);
  xler.push_back(curx + 1);
  yler.push_back(cury);
  yler.push_back(cury - 1);
  yler.push_back(cury + 1);
}
int used[N][N];
int H, W;
void dfs(int x, int y) {
  used[x][y] = 2;
  for (int i = 0; i < 4; i++) {
    int tmpx = x + dx[i];
    int tmpy = y + dy[i];
    if ((0 <= tmpx && tmpx < H) && (0 <= tmpy && tmpy < W) &&
        used[tmpx][tmpy] == 0) {
      dfs(tmpx, tmpy);
    }
  }
}
int main() {
  int n = readInt();
  add();
  for (int i = 0; i < n; i++) {
    char x;
    int y;
    cin >> x >> y;
    for (int j = 0; j < 4; j++) {
      if (dirs[j] == x) {
        directionx[i] = dx[j] * y;
        directiony[i] = dy[j] * y;
        curx += directionx[i];
        cury += directiony[i];
        add();
      }
    }
  }
  sort(xler.begin(), xler.end());
  sort(yler.begin(), yler.end());
  xler.resize(unique(xler.begin(), xler.end()) - xler.begin());
  yler.resize(unique(yler.begin(), yler.end()) - yler.begin());
  H = xler.size();
  W = yler.size();
  curx = 5000000001LL;
  cury = 5000000001LL;
  long long compx = lower_bound(xler.begin(), xler.end(), curx) - xler.begin();
  long long compy = lower_bound(yler.begin(), yler.end(), cury) - yler.begin();
  for (int i = 0; i < n; i++) {
    long long tmpx = curx + directionx[i];
    long long tmpy = cury + directiony[i];
    long long tmpcompx =
        lower_bound((xler).begin(), (xler).end(), tmpx) - xler.begin();
    long long tmpcompy =
        lower_bound((yler).begin(), (yler).end(), tmpy) - yler.begin();
    for (int j = min(tmpcompx, compx); j <= max(tmpcompx, compx); j++) {
      for (int k = min(tmpcompy, compy); k <= max(tmpcompy, compy); k++) {
        used[j][k] = 1;
      }
    }
    curx = tmpx;
    cury = tmpy;
    compx = tmpcompx;
    compy = tmpcompy;
  }
  dfs(0, 0);
  long long res = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (used[i][j] != 2) {
        res += (xler[i + 1] - xler[i]) * (yler[j + 1] - yler[j]);
      }
    }
  }
  cout << res;
  return 0;
}
