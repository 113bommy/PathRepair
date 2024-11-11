#include <bits/stdc++.h>
using namespace std;
bool a[2000][2000], b[2000][2000], c[2000][2000];
int n, m;
void jian() {
  memcpy(c, b, sizeof(b));
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m - 2; j++) {
      if (!b[i + 1][j] || !b[i][j + 1] || !b[i - 1][j] || !b[i][j - 1])
        c[i][j] = 0;
    }
  }
  memcpy(b, c, sizeof(b));
}
void jia() {
  memcpy(c, b, sizeof(b));
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m - 2; j++) {
      if (b[i + 1][j] || b[i][j + 1] || b[i - 1][j] || b[i][j - 1]) {
        c[i][j] = 1;
      }
    }
  }
  memcpy(b, c, sizeof(b));
}
bool vis[2000][2000];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int cnt, ans[200000];
pair<int, int> q1[6000000], q2[6000000];
int h1, t1, h2, t2;
bool count(int x, int y) {
  h1 = 1;
  t1 = 1;
  q1[t1++] = make_pair(x, y);
  a[x][y] = 0;
  int cnt = 0;
  while (h1 < t1) {
    x = q1[h1].first;
    y = q1[h1].second;
    h1++;
    for (int i = 0; i < 4; i++) {
      int tx = x + d[i][0], ty = y + d[i][1];
      if (tx > n || tx < 0 || ty > m || ty < 0) continue;
      if (a[tx][ty]) {
        a[tx][ty] = 0;
        cnt++;
        q1[t1++] = make_pair(tx, ty);
      }
    }
  }
  if (cnt > 10)
    return 1;
  else
    return 0;
}
int bfs(int x, int y) {
  h2 = 1;
  t2 = 1;
  q2[t2++] = make_pair(x, y);
  b[x][y] = 0;
  int an = 0;
  while (h2 < t2) {
    x = q2[h2].first;
    y = q2[h2].second;
    h2++;
    for (int i = 0; i < 4; i++) {
      int tx = x + d[i][0], ty = y + d[i][1];
      if (a[tx][ty]) {
        an += count(tx, ty);
      }
      if (b[tx][ty]) {
        b[tx][ty] = 0;
        q2[t2++] = make_pair(tx, ty);
      }
    }
  }
  return an;
}
inline int read() {
  int x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || c > '9') {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return flag ? -x : x;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int C = read();
      a[i][j] = b[i][j] = C;
    }
  }
  n += 2;
  m += 2;
  for (int i = 1; i <= 4; i++) jian();
  for (int i = 1; i <= 8; i++) jia();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (b[i][j]) a[i][j] = 0;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (b[i][j]) {
        ans[++cnt] = bfs(i, j);
      }
    }
  }
  sort(ans + 1, ans + cnt + 1);
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
