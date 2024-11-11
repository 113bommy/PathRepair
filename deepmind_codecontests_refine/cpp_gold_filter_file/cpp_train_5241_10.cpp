#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
int mat1[2100][2100];
int mat[2100][2100];
int vis[2100][2100];
bool issqr(int x) {
  int r = sqrt(x);
  r--;
  if (r * r == x) return true;
  r++;
  if (r * r == x) return true;
  r++;
  if (r * r == x) return true;
  return false;
}
void solve() {
  int n = in();
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) mat1[i][j] = in();
  memset(mat, 0, sizeof mat);
  int ii, jj, kk;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      kk = 0;
      for (ii = i - 2; ii < i + 3; ii++)
        for (jj = j - 2; jj < j + 3; jj++)
          if (ii >= 0 && jj >= 0 && ii < n && jj < n) kk += mat1[ii][jj];
      if (kk >= 13)
        mat[i][j] = 1;
      else
        mat[i][j] = 0;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) vis[i][j] = 0;
  int cant;
  int squares = 0;
  int circles = 0;
  pair<int, int> act;
  pair<int, int> mini, minj, maxi, maxj;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (mat[i][j] == 1 && !vis[i][j]) {
        cant = 0;
        vector<pair<int, int> > pts;
        queue<pair<int, int> > cola;
        cola.push(pair<int, int>(i, j));
        vis[i][j] = 1;
        maxi = pair<int, int>(i, j);
        mini = pair<int, int>(i, j);
        maxj = pair<int, int>(j, i);
        minj = pair<int, int>(j, i);
        while (!cola.empty()) {
          act = cola.front();
          pts.push_back(act);
          cola.pop();
          cant++;
          maxi = max(maxi, act);
          mini = min(mini, act);
          maxj = max(maxj, pair<int, int>(act.second, act.first));
          minj = min(minj, pair<int, int>(act.second, act.first));
          if (mat[act.first + 1][act.second] != 0 &&
              !vis[act.first + 1][act.second]) {
            vis[act.first + 1][act.second] = 1;
            cola.push(pair<int, int>(act.first + 1, act.second));
          }
          if (mat[act.first - 1][act.second] != 0 &&
              !vis[act.first - 1][act.second]) {
            vis[act.first - 1][act.second] = 1;
            cola.push(pair<int, int>(act.first - 1, act.second));
          }
          if (mat[act.first][act.second + 1] != 0 &&
              !vis[act.first][act.second + 1]) {
            vis[act.first][act.second + 1] = 1;
            cola.push(pair<int, int>(act.first, act.second + 1));
          }
          if (mat[act.first][act.second - 1] != 0 &&
              !vis[act.first][act.second - 1]) {
            vis[act.first][act.second - 1] = 1;
            cola.push(pair<int, int>(act.first, act.second - 1));
          }
        }
        if (cant < 50) continue;
        double cx = (maxi.first + mini.first) / 2.;
        double cy = (maxj.first + minj.first) / 2.;
        double dmax = 0;
        for (k = 0; k < pts.size(); k++)
          dmax = max(dmax, ((pts[k].first - cx) * (pts[k].first - cx)) +
                               ((pts[k].second - cy) * (pts[k].second - cy)));
        if (cant / dmax < 2.5)
          squares++;
        else
          circles++;
      }
  cout << circles << " " << squares << endl;
}
int main() {
  solve();
  return 0;
}
