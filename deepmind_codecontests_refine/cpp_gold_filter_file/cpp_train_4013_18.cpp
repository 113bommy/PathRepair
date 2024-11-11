#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<vector<vector<long long>>> a(
      4, vector<vector<long long>>(2 * n + 1, vector<long long>(2 * m + 1, 2)));
  char c;
  for (long long i = 1; i < 2 * n; i += 2) {
    for (long long j = 1; j < 2 * m; j += 2) {
      cin >> c;
      a[0][i][j] = 0;
      a[1][i][j] = 0;
      a[2][i][j] = 0;
      a[3][i][j] = 0;
      if (c == '+') {
        a[0][i + 1][j]--;
        a[0][i - 1][j]--;
        a[0][i][j + 1]--;
        a[0][i][j - 1]--;
        a[1][i + 1][j]--;
        a[1][i - 1][j]--;
        a[1][i][j + 1]--;
        a[1][i][j - 1]--;
        a[2][i][j - 1]--;
        a[2][i + 1][j]--;
        a[2][i - 1][j]--;
        a[2][i][j + 1]--;
        a[3][i][j - 1]--;
        a[3][i + 1][j]--;
        a[3][i - 1][j]--;
        a[3][i][j + 1]--;
      } else if (c == '-') {
        a[0][i][j + 1]--;
        a[0][i][j - 1]--;
        a[1][i + 1][j]--;
        a[1][i - 1][j]--;
        a[2][i][j + 1]--;
        a[2][i][j - 1]--;
        a[3][i + 1][j]--;
        a[3][i - 1][j]--;
      } else if (c == '|') {
        a[0][i + 1][j]--;
        a[0][i - 1][j]--;
        a[1][i][j + 1]--;
        a[1][i][j - 1]--;
        a[2][i + 1][j]--;
        a[2][i - 1][j]--;
        a[3][i][j + 1]--;
        a[3][i][j - 1]--;
      } else if (c == '^') {
        a[0][i - 1][j]--;
        a[1][i][j + 1]--;
        a[2][i + 1][j]--;
        a[3][i][j - 1]--;
      } else if (c == '>') {
        a[0][i][j + 1]--;
        a[1][i + 1][j]--;
        a[2][i][j - 1]--;
        a[3][i - 1][j]--;
      } else if (c == '<') {
        a[0][i][j - 1]--;
        a[1][i - 1][j]--;
        a[2][i][j + 1]--;
        a[3][i + 1][j]--;
      } else if (c == 'v') {
        a[0][i + 1][j]--;
        a[1][i][j - 1]--;
        a[2][i - 1][j]--;
        a[3][i][j + 1]--;
      } else if (c == 'L') {
        a[0][i - 1][j]--;
        a[0][i + 1][j]--;
        a[0][i][j + 1]--;
        a[1][i + 1][j]--;
        a[1][i][j - 1]--;
        a[1][i][j + 1]--;
        a[2][i + 1][j]--;
        a[2][i - 1][j]--;
        a[2][i][j - 1]--;
        a[3][i - 1][j]--;
        a[3][i][j - 1]--;
        a[3][i][j + 1]--;
      } else if (c == 'R') {
        a[0][i - 1][j]--;
        a[0][i + 1][j]--;
        a[0][i][j - 1]--;
        a[1][i - 1][j]--;
        a[1][i][j - 1]--;
        a[1][i][j + 1]--;
        a[2][i + 1][j]--;
        a[2][i - 1][j]--;
        a[2][i][j + 1]--;
        a[3][i + 1][j]--;
        a[3][i][j - 1]--;
        a[3][i][j + 1]--;
      } else if (c == 'D') {
        a[0][i - 1][j]--;
        a[0][i][j - 1]--;
        a[0][i][j + 1]--;
        a[1][i + 1][j]--;
        a[1][i - 1][j]--;
        a[1][i][j + 1]--;
        a[2][i + 1][j]--;
        a[2][i][j - 1]--;
        a[2][i][j + 1]--;
        a[3][i + 1][j]--;
        a[3][i - 1][j]--;
        a[3][i][j - 1]--;
      } else if (c == 'U') {
        a[0][i + 1][j]--;
        a[0][i][j - 1]--;
        a[0][i][j + 1]--;
        a[1][i + 1][j]--;
        a[1][i - 1][j]--;
        a[1][i][j - 1]--;
        a[2][i - 1][j]--;
        a[2][i][j - 1]--;
        a[2][i][j + 1]--;
        a[3][i + 1][j]--;
        a[3][i - 1][j]--;
        a[3][i][j + 1]--;
      } else {
        a[0][i][j] = INF;
        a[1][i][j] = INF;
        a[2][i][j] = INF;
        a[3][i][j] = INF;
      }
    }
  }
  long long xs, ys, l = 0, xf, yf;
  cin >> xs >> ys >> xf >> yf;
  xs--;
  ys--;
  xf--;
  yf--;
  vector<pair<long long, pair<long long, long long>>> wave(1, {l, {xs, ys}});
  vector<vector<vector<long long>>> ans(
      4, vector<vector<long long>>(n, vector<long long>(m, INF)));
  ans[0][xs][ys] = 0;
  while (wave.size() > 0) {
    vector<pair<long long, pair<long long, long long>>> newWave;
    for (auto v : wave) {
      long long x = v.second.first;
      long long y = v.second.second;
      long long dx = 2 * x + 1;
      long long dy = 2 * y + 1;
      long long cl = v.first;
      long long dl;
      if (cl == 3) {
        dl = 0;
      } else {
        dl = cl + 1;
      }
      if (dx + 2 < 2 * n) {
        if (a[cl][dx + 1][dy] <= 0 && ans[cl][x + 1][y] > ans[cl][x][y] + 1) {
          ans[cl][x + 1][y] = ans[cl][x][y] + 1;
          newWave.push_back({cl, {x + 1, y}});
        }
      }
      if (dy + 2 < 2 * m) {
        if (a[cl][dx][dy + 1] <= 0 && ans[cl][x][y + 1] > ans[cl][x][y] + 1) {
          ans[cl][x][y + 1] = ans[cl][x][y] + 1;
          newWave.push_back({cl, {x, y + 1}});
        }
      }
      if (dx - 2 > 0) {
        if (a[cl][dx - 1][dy] <= 0 && ans[cl][x - 1][y] > ans[cl][x][y] + 1) {
          ans[cl][x - 1][y] = ans[cl][x][y] + 1;
          newWave.push_back({cl, {x - 1, y}});
        }
      }
      if (dy - 2 > 0) {
        if (a[cl][dx][dy - 1] <= 0 && ans[cl][x][y - 1] > ans[cl][x][y] + 1) {
          ans[cl][x][y - 1] = ans[cl][x][y] + 1;
          newWave.push_back({cl, {x, y - 1}});
        }
      }
      if (ans[dl][x][y] > ans[cl][x][y] + 1 && a[dl][dx][dy] != INF) {
        ans[dl][x][y] = ans[cl][x][y] + 1;
        newWave.push_back({dl, {x, y}});
      }
    }
    wave = newWave;
  }
  long long rec = INF;
  for (long long i = 0; i < 4; i++) {
    rec = min(rec, ans[i][xf][yf]);
  }
  if (rec == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << rec << endl;
}
