#include <bits/stdc++.h>
using namespace std;
int n;
int a[2036][2036];
int b[2036][2036];
int c[2036][2036];
int vis[2036][2036];
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int u[2036 * 2036], v[2036 * 2036];
int m;
void go(int first, int second) {
  if (vis[first][second]) return;
  vis[first][second] = true;
  if (!c[first][second]) return;
  u[m] = first;
  v[m++] = second;
  for (int k = (0); k < (int)(4); k++) go(first + dx[k], second + dy[k]);
}
double PI = acos(-1.0);
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)(n + 3); i++)
    for (int j = (1); j <= (int)(n + 3); j++) {
      if (i <= n && j <= n) scanf("%d", &a[i][j]);
      b[i + 3][j + 3] = b[i + 3 - 1][j + 3] + b[i + 3][j + 3 - 1] -
                        b[i + 3 - 1][j + 3 - 1] + a[i][j];
    }
  for (int i = (1); i <= (int)(n); i++)
    for (int j = (1); j <= (int)(n); j++) {
      int sx = i, sy = j, ex = i + 5, ey = j + 5;
      int cnt = b[ex][ey] - b[sx][ey] - b[ex][sy] + b[sx][sy];
      if (cnt >= 13) c[i][j] = 1;
    }
  int nc = 0, ns = 0;
  for (int i = (1); i <= (int)(n); i++)
    for (int j = (1); j <= (int)(n); j++)
      if (!vis[i][j]) {
        m = 0;
        go(i, j);
        if (m < 150) continue;
        int sx = 20000, sy = 20000, ex = 0, ey = 0;
        for (int k = (0); k < (int)(m); k++) {
          sx = min(sx, u[k]);
          sy = min(sy, v[k]);
          ex = max(ex, u[k]);
          ey = max(ey, v[k]);
        }
        double meax = 0, meay = 0;
        for (int k = (0); k < (int)(m); k++) {
          meax += u[k];
          meay += v[k];
        }
        meax /= m;
        meay /= m;
        vector<double> arr;
        int num = 20;
        for (int r = (0); r < (int)(num); r++) {
          double dx = cos(r * (2 * PI) / num);
          double dy = sin(r * (2 * PI) / num);
          double mn = 1e20, mx = -1e20;
          for (int k = (0); k < (int)(m); k++) {
            double first = u[k] - meax;
            double second = v[k] - meay;
            double d = (first * dx) + (second * dy);
            mn = min(d, mn);
            mx = max(d, mx);
          }
          arr.push_back(mx - mn);
        }
        double avg = accumulate((arr).begin(), (arr).end(), (double)0);
        avg /= arr.size();
        sort((arr).begin(), (arr).end());
        double rng = (arr[arr.size() - 1] - arr[0]);
        if (rng / avg > 0.15)
          ns++;
        else
          nc++;
      }
  printf("%d %d\n", nc, ns);
  return 0;
}
