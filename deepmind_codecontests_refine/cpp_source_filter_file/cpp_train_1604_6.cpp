#include <bits/stdc++.h>
using namespace std;
char first[5] = {'.', 'U', 'D', 'L', 'R'};
const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};
int b, n, q;
int a[35][35];
int timeExit[5][35][35], timeRepeat[5][35][35];
int cycleLength[5][35][35], tailLength[5][35][35];
pair<int, int> exitpos[5][35][35];
pair<int, pair<int, int> > repeatpos[5][35][35];
int mark[5][35][35];
int startx, starty, startd;
int finalx, finaly, finald;
long long timelimit = 1LL * 1000000000 * 1000000;
void df(int d, int cx, int cy, int time) {
  if (a[cx][cy] != 0) d = a[cx][cy];
  if (mark[d][cx][cy] >= 0) {
    timeRepeat[startd][startx][starty] = time;
    cycleLength[startd][startx][starty] = time - mark[d][cx][cy];
    tailLength[startd][startx][starty] = mark[d][cx][cy];
    repeatpos[startd][startx][starty] = make_pair(d, make_pair(cx, cy));
    timeExit[startd][startx][starty] = -1;
    return;
  }
  mark[d][cx][cy] = time;
  if (cx <= 0 || cy <= 0 || cx > b || cy > b) {
    timeExit[startd][startx][starty] = time;
    int rd;
    if (d % 2 == 1)
      rd = d + 1;
    else
      rd = d - 1;
    exitpos[startd][startx][starty] = make_pair(cx + dx[rd], cy + dy[rd]);
    timeRepeat[startd][startx][starty] = -1;
    return;
  }
  if (time == timelimit) {
    finald = d;
    finalx = cx;
    finaly = cy;
    return;
  }
  df(d, cx + dx[d], cy + dy[d], time + 1);
}
int main() {
  cin >> n >> b;
  b++;
  for (int ni = 1; ni <= n; ni++) {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    x0++;
    y0++;
    x1++;
    y1++;
    int type;
    if (y1 > y0) type = 1;
    if (y1 < y0) type = 2;
    if (x1 < x0) type = 3;
    if (x1 > x0) type = 4;
    int i, j;
    for (i = min(x0, x1); i <= max(x0, x1); i++)
      for (j = min(y0, y1); j <= min(y0, y1); j++) a[i][j] = type;
  }
  for (startd = 1; startd <= 4; startd++)
    for (startx = 1; startx <= b; startx++)
      for (starty = 1; starty <= b; starty++) {
        memset(mark, -1, sizeof(mark));
        df(startd, startx, starty, 0);
      }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int xi, yi;
    int ansx, ansy;
    int d;
    char wi;
    long long ti;
    cin >> xi >> yi >> wi >> ti;
    xi++;
    yi++;
    if (wi == 'U') d = 1;
    if (wi == 'D') d = 2;
    if (wi == 'L') d = 3;
    if (wi == 'R') d = 4;
    if (timeRepeat[d][xi][yi] == -1) {
      if (ti >= timeExit[d][xi][yi]) {
        ansx = exitpos[d][xi][yi].first;
        ansy = exitpos[d][xi][yi].second;
      } else {
        memset(mark, -1, sizeof(mark));
        timelimit = ti;
        df(d, xi, yi, 0);
        ansx = finalx;
        ansy = finaly;
      }
    } else {
      if (ti < timeRepeat[d][xi][yi]) {
        memset(mark, -1, sizeof(mark));
        timelimit = ti;
        df(d, xi, yi, 0);
        ansx = finalx;
        ansy = finaly;
      } else {
        memset(mark, -1, sizeof(mark));
        timelimit = (ti - tailLength[d][xi][yi]) % cycleLength[d][xi][yi] +
                    tailLength[d][xi][yi];
        df(d, xi, yi, 0);
        ansx = finalx;
        ansy = finaly;
      }
    }
    ansx--;
    ansy--;
    cout << ansx << ' ' << ansy << '\n';
  }
  return 0;
}
