#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;
const long long mod = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch<'0' | ch> '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void Out(int aa) {
  if (aa > 9) Out(aa / 10);
  putchar(aa % 10 + '0');
}
char mapp[255][255];
bool vis[255][255];
long long ans[255][255];
int dic[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct node {
  int x, y;
  long long c;
};
long long p, q, n, m;
void bfs(int x, int y, long long c) {
  queue<node> que;
  que.push({x, y, c / 2});
  memset(vis, 0, sizeof(vis));
  vis[x][y] = 1;
  while (!que.empty()) {
    node q1 = que.front();
    que.pop();
    if (q1.c < 1) continue;
    for (int i = 0; i < 4; i++) {
      int xx = q1.x + dic[i][0];
      int yy = q1.y + dic[i][1];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mapp[xx][yy] != '*' &&
          !vis[xx][yy]) {
        vis[xx][yy] = 1;
        ans[xx][yy] += q1.c;
        que.push({xx, yy, q1.c / 2});
      }
    }
  }
}
int main() {
  n = read(), m = read(), q = read(), p = read();
  for (int i = 1; i <= n; i++) scanf("%s", mapp[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mapp[i][j] != '.' && mapp[i][j] != '*') {
        ans[i][j] += q * (mapp[i][j] - 'A' + 1);
        bfs(i, j, q * (mapp[i][j] - 'A' + 1));
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ans[i][j] > p) res++;
    }
  }
  printf("%d\n", res);
  return 0;
}
