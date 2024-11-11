#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
char s[maxn][maxn];
int num[maxn * maxn], sum[maxn][maxn], id[maxn][maxn];
int vis[maxn * maxn];
int cnt, cur, all, k, n;
int dir[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
void dfs(int x, int y) {
  cnt++;
  id[x][y] = cur;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && s[xx][yy] == '.' &&
        !id[xx][yy]) {
      dfs(xx, yy);
    }
  }
}
void push(int x, int y) {
  if (!vis[id[x][y]]) {
    all += num[id[x][y]];
  }
  vis[id[x][y]]++;
}
void pop(int x, int y) {
  vis[id[x][y]]--;
  if (!vis[id[x][y]]) {
    all -= num[id[x][y]];
  }
}
int getSum(int x, int y) {
  return sum[x][y] - sum[x - k][y] - sum[x][y - k] + sum[x - k][y - k];
}
int main() {
  cur = 1;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (s[i][j] == '.') {
        sum[i][j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] != '.' || id[i][j]) {
        continue;
      }
      cnt = 0;
      dfs(i, j);
      num[cur++] = cnt;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n - k + 1; i++) {
    all = 0;
    memset(vis, 0, sizeof(vis));
    for (int j = i - 1; j <= i + k; j++) {
      for (int h = 1; h <= k; h++) {
        if (s[j][h] == '.') push(j, h);
      }
    }
    for (int j = i; j < i + k; j++) {
      if (s[j][k + 1] == '.') push(j, k + 1);
    }
    ans = max(ans, all + k * k - getSum(i + k - 1, k));
    for (int j = 1; j <= n - k; j++) {
      for (int h = i; h < i + k; h++) {
        pop(h, j - 1);
        push(h, j + k + 1);
      }
      pop(i - 1, j);
      pop(i + k, j);
      push(i - 1, j + k);
      push(i + k, j + k);
      ans = max(ans, all + k * k - getSum(i + k - 1, k + j));
    }
  }
  printf("%d\n", ans);
}
