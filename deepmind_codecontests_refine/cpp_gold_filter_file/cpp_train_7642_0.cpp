#include <bits/stdc++.h>
using namespace std;
int const maxn = (int)2e3 + 111;
int const inf = (1 << 30) - 1;
int n, m;
char a[maxn][maxn];
int used[maxn][maxn];
char dir[] = {'>', 'v', '<', '^'};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char dir2[] = {'<', '^', '>', 'v'};
void dfs(int vx, int vy) {
  used[vx][vy] = 1;
  for (int i = 0; i < 4; i++) {
    if (a[vx][vy] == dir[i]) {
      int toi = vx + di[i];
      int toj = vy + dj[i];
      if (a[toi][toj] == '#') continue;
      if (!used[toi][toj]) {
        dfs(toi, toj);
      } else if (used[toi][toj] == 1) {
        cout << -1 << endl;
        exit(0);
      }
    }
  }
  used[vx][vy] = 2;
}
int d[maxn][maxn];
int calc(int vx, int vy) {
  int &res = d[vx][vy];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < 4; i++) {
    int toi = vx + di[i];
    int toj = vy + dj[i];
    if (a[toi][toj] == dir2[i]) {
      res = max(res, calc(toi, toj) + 1);
    }
  }
  return res;
}
void update(int sum, int &maxx1, int &maxx2) {
  if (sum >= maxx1) {
    maxx2 = maxx1;
    maxx1 = sum;
  } else if (sum > maxx2) {
    maxx2 = sum;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++) a[i][j] = '#';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][j] && a[i][j] != '#') {
        dfs(i, j);
      }
    }
  }
  memset(d, -1, sizeof(d));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '#') {
        d[i][j] = calc(i, j);
      }
    }
  }
  int ans = 0;
  int maxi1 = 0, maxi2 = 0;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (a[i][j] == '#') {
        int maxx1 = 0, maxx2 = 0;
        for (int k = 0; k < 4; k++) {
          int toi = i + di[k];
          int toj = j + dj[k];
          if (a[toi][toj] == dir2[k]) {
            int sum = d[toi][toj] + 1;
            ans = max(ans, sum + sum - 1);
            update(sum, maxx1, maxx2);
          }
        }
        if (maxx1 == maxx2) {
          ans = max(ans, maxx1 + maxx2);
        }
        update(maxx1, maxi1, maxi2);
      }
    }
  }
  ans = max(ans, maxi1 + maxi2);
  cout << ans << endl;
  return 0;
}
