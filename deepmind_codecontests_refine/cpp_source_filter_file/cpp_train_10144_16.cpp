#include <bits/stdc++.h>
using namespace std;
int plot[303][303];
int tp, tu, td;
int m, n, t;
int r[303][303];
int d[303][303];
int l[303][303];
int u[303][303];
int getDis(int ans, int t) {
  if (ans > t)
    return ans - t;
  else
    return t - ans;
}
int getAns(int ulx, int uly, int drx, int dry) {
  return (r[ulx][dry] - r[ulx][uly] + d[drx][dry] - d[ulx][dry] + l[drx][uly] -
          l[drx][dry] + u[ulx][uly] - u[drx][uly]);
}
int main() {
  cin >> m >> n >> t;
  cin >> tp >> tu >> td;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> plot[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    r[i][1] = 0;
    for (int j = 2; j <= n; j++) {
      if (plot[i][j] < plot[i][j - 1])
        r[i][j] = r[i][j - 1] + td;
      else if (plot[i][j] == plot[i][j - 1])
        r[i][j] = r[i][j - 1] + tp;
      else
        r[i][j] = r[i][j - 1] + tu;
    }
  }
  for (int j = 1; j <= n; j++) {
    d[1][j] = 0;
    for (int i = 2; i <= m; i++) {
      if (plot[i][j] < plot[i - 1][j])
        d[i][j] = d[i - 1][j] + td;
      else if (plot[i][j] == plot[i - 1][j])
        d[i][j] = d[i - 1][j] + tp;
      else
        d[i][j] = d[i - 1][j] + tu;
    }
  }
  for (int i = 1; i <= m; i++) {
    l[i][n] = 0;
    for (int j = n - 1; j >= 1; j--) {
      if (plot[i][j] < plot[i][j + 1])
        l[i][j] = l[i][j + 1] + td;
      else if (plot[i][j] == plot[i][j + 1])
        l[i][j] = l[i][j + 1] + tp;
      else
        l[i][j] = l[i][j + 1] + tu;
    }
  }
  for (int j = 1; j <= n; j++) {
    u[m][j] = 0;
    for (int i = m - 1; i >= 1; i--) {
      if (plot[i][j] < plot[i + 1][j])
        u[i][j] = u[i + 1][j] + td;
      else if (plot[i][j] == plot[i + 1][j])
        u[i][j] = u[i + 1][j] + tp;
      else
        u[i][j] = u[i + 1][j] + tu;
    }
  }
  int ulx, uly, drx, dry;
  int dis;
  ulx = uly = 1;
  drx = m;
  dry = n;
  dis = getDis(getAns(ulx, uly, drx, dry), t);
  if (true) {
    for (int i = 1; i <= m - 2; i++) {
      for (int j = 1; j <= n - 2; j++) {
        for (int k = i + 2; k <= m; k++) {
          int ql = j + 2;
          int qr = n;
          if (getAns(i, j, k, ql) > t) {
            if (getDis(getAns(i, j, k, ql), t) < dis) {
              ulx = i;
              uly = j;
              drx = k;
              dry = ql;
              dis = getDis(getAns(i, j, k, ql), t);
              continue;
            }
          }
          if (getAns(i, j, k, qr) <= t) {
            if (getDis(getAns(i, j, k, qr), t) < dis) {
              ulx = i;
              uly = j;
              drx = k;
              dry = qr;
              dis = getDis(getAns(i, j, k, qr), t);
              continue;
            }
          }
          int mid;
          while (ql < qr) {
            mid = (ql + qr) / 2;
            if (getAns(i, j, k, mid) < t)
              ql = mid + 1;
            else
              qr = mid;
            mid = (ql + qr) / 2;
          }
          if (getDis(getAns(i, j, k, qr), t) < dis) {
            ulx = i;
            uly = j;
            drx = k;
            dry = qr;
            dis = getDis(getAns(i, j, k, qr), t);
          }
          if (qr - 2 >= j && getDis(getAns(i, j, k, qr - 1), t) < dis) {
            ulx = i;
            uly = j;
            drx = k;
            dry = qr - 1;
            dis = getDis(getAns(i, j, k, qr - 1), t);
          }
        }
      }
    }
  }
  cout << ulx << " " << uly << " " << drx << " " << dry << endl;
  return 0;
}
