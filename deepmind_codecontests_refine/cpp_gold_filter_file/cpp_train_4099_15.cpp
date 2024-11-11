#include <bits/stdc++.h>
using namespace std;
int solve();
int main() {
  cout.precision(30);
  ios_base::sync_with_stdio(0);
  return solve();
}
const int N = 3100, INF = 15e8;
int step[N];
string d[N];
int f[N][N];
int qx[N * N], qy[N * N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int solve() {
  int n;
  cin >> n;
  int x = 0, y = 0;
  vector<int> xs, ys;
  xs.push_back(0);
  ys.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> step[i];
    if (d[i] == "L") {
      y -= step[i];
    } else if (d[i] == "R") {
      y += step[i];
    } else if (d[i] == "D") {
      x += step[i];
    } else if (d[i] == "U") {
      x -= step[i];
    }
    xs.push_back(x);
    ys.push_back(y);
  }
  xs.push_back(-INF);
  ys.push_back(-INF);
  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  sort(ys.begin(), ys.end());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  vector<int> xx, yy, xl, yl;
  for (int i = 1; i < xs.size(); i++) {
    if (xs[i] - xs[i - 1] > 1) {
      xx.push_back(xs[i] - 1);
      xl.push_back(xs[i] - xs[i - 1] - 1);
    }
    xx.push_back(xs[i]);
    xl.push_back(1);
  }
  xx.push_back(xx[xx.size() - 1] + 1);
  xl.push_back(1);
  for (int i = 1; i < ys.size(); i++) {
    if (ys[i] - ys[i - 1] > 1) {
      yy.push_back(ys[i] - 1);
      yl.push_back(ys[i] - ys[i - 1] - 1);
    }
    yy.push_back(ys[i]);
    yl.push_back(1);
  }
  yy.push_back(yy[yy.size() - 1] + 1);
  yl.push_back(1);
  x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int px = x, py = y;
    if (d[i] == "L") {
      y -= step[i];
    } else if (d[i] == "R") {
      y += step[i];
    } else if (d[i] == "D") {
      x += step[i];
    } else if (d[i] == "U") {
      x -= step[i];
    }
    int left = lower_bound(yy.begin(), yy.end(), min(py, y)) - yy.begin();
    int right = lower_bound(yy.begin(), yy.end(), max(py, y)) - yy.begin();
    int up = lower_bound(xx.begin(), xx.end(), min(px, x)) - xx.begin();
    int down = lower_bound(xx.begin(), xx.end(), max(px, x)) - xx.begin();
    for (int a = up; a <= down; a++) {
      for (int b = left; b <= right; b++) {
        f[a][b] = 1;
      }
    }
  }
  int l = 0, r = 0;
  f[0][0] = 2;
  qx[r] = 0;
  qy[r] = 0;
  r++;
  while (l < r) {
    int vx = qx[l];
    int vy = qy[l];
    l++;
    for (int t = 0; t < 4; t++) {
      int tox = vx + dx[t];
      int toy = vy + dy[t];
      if (0 <= tox && tox < xx.size() && 0 <= toy && toy < yy.size() &&
          f[tox][toy] == 0) {
        f[tox][toy] = 2;
        qx[r] = tox;
        qy[r] = toy;
        r++;
      }
    }
  }
  long long result = 0;
  for (int i = 0; i < xx.size(); i++) {
    for (int j = 0; j < yy.size(); j++) {
      if (f[i][j] != 2) {
        result += xl[i] * 1ll * yl[j];
      }
    }
  }
  cout << result << endl;
  return 0;
}
