#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, K;
char mp[N][N];
int vis[N][N];
int val[N * N];
int t[N * N];
int sum[N][N];
int xi[] = {0, 1, 0, -1};
int yi[] = {1, 0, -1, 0};
int temp;
struct node {
  int x, y;
  node() {}
  node(int x, int y) : x(x), y(y) {}
};
void bfs(int cnt, int x, int y) {
  queue<node> q;
  vis[x][y] = cnt;
  q.push(node(x, y));
  while (q.size()) {
    node e = q.front();
    q.pop();
    val[cnt]++;
    for (int i = 0; i < 4; i++) {
      int xx = e.x + xi[i], yy = e.y + yi[i];
      if (xx > 0 && xx <= n && yy > 0 && yy <= n && !vis[xx][yy] &&
          mp[xx][yy] == '.') {
        vis[xx][yy] = cnt;
        q.push(node(xx, yy));
      }
    }
  }
}
void del(int i, int j) {
  if (!vis[i][j]) return;
  if ((--t[vis[i][j]]) == 0) temp -= val[vis[i][j]];
}
void add(int i, int j) {
  if (!vis[i][j]) return;
  if ((++t[vis[i][j]]) == 1) temp += val[vis[i][j]];
}
int cal(int x, int y) {
  return sum[x][y] - sum[x - K][y] - sum[x][y - K] + sum[x - K][y - K];
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mp[i][j] == '.') sum[i][j] = 1;
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!vis[i][j] && mp[i][j] == '.') {
        bfs(++cnt, i, j);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i + K <= n + 1; i++) {
    temp = 0;
    memset(t, 0, sizeof(t));
    for (int j = i - 1; j <= i + K; j++)
      for (int k = 1; k <= K + 1; k++) add(j, k);
    del(i - 1, K + 1);
    del(i + K, K + 1);
    ans = max(ans, temp + K * K - cal(i + K - 1, K));
    for (int k = K + 2; k <= n + 1; k++) {
      for (int j = i; j < i + K; j++) {
        add(j, k);
        del(j, k - K - 1);
      }
      add(i - 1, k - 1);
      add(i + K, k - 1);
      del(i - 1, k - K);
      del(i + K, k - K);
      ans = max(ans, temp + K * K - cal(i + K - 1, k - 1));
    }
  }
  cout << ans << endl;
  return 0;
}
