#include <bits/stdc++.h>
using namespace std;
long long K;
bool vis[2000][2000];
int ans, ansX, ansY, cnt;
pair<int, pair<int, int> > v[4000000];
int n, m, p[4000000], s[4000000], a[2000][2000];
int M[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int UF(int x) {
  if (x == p[x]) return x;
  return p[x] = UF(p[x]);
}
void merge(int x, int y) {
  x = UF(x);
  y = UF(y);
  if (x != y) {
    if (s[x] > s[y])
      s[x] += s[y], p[y] = x;
    else
      s[y] += s[x], p[x] = y;
  }
  return;
}
void dfs(int x, int y, int val) {
  if (vis[x][y] || !cnt || !x || !y || x > n || y > m || a[x][y] < val) return;
  cnt--;
  a[x][y] = val;
  vis[x][y] = 1;
  for (int k = 0; k < 4; k++) dfs(x + M[k][0], y + M[k][1], val);
}
int main() {
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      v[(i - 1) * m + j - 1].first = a[i][j];
      v[(i - 1) * m + j - 1].second.first = i;
      v[(i - 1) * m + j - 1].second.second = j;
    }
  }
  sort(v, v + n * m);
  reverse(v, v + n * m);
  for (int i = 1; i <= n * m; i++) p[i] = i, s[i] = 1;
  for (int i = 0; i < n * m; i++) {
    int j = i;
    while (v[i].first == v[j].first && j < n * m) {
      for (int k = 0; k < 4; k++) {
        int xx = v[j].second.first;
        int yy = v[j].second.second;
        int x = xx + M[k][0];
        int y = yy + M[k][1];
        if (a[x][y] >= v[j].first && x && y && x <= n && y <= m)
          merge((x - 1) * m + y, (xx - 1) * m + yy);
      }
      j++;
    }
    if (v[i].first && K % v[i].first == 0) {
      for (int k = i; k < j; k++) {
        if (s[UF((v[k].second.first - 1) * m + v[k].second.second)] >=
            K / v[i].first) {
          ans = v[k].first;
          cnt = K / v[i].first;
          ansX = v[k].second.first;
          ansY = v[k].second.second;
          break;
        }
      }
      if (ans) break;
    }
    i = j;
  }
  if (!cnt)
    cout << "NO\n";
  else {
    cout << "YES\n";
    dfs(ansX, ansY, ans);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (vis[i][j])
          printf("%d ", a[i][j]);
        else
          printf("0 ");
      }
      printf("\n");
    }
  }
  return 0;
}
