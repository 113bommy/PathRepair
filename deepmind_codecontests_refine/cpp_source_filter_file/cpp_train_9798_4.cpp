#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 0x3f3f3f3f;
void read(int &val) {
  int x = 0;
  int bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
struct node {
  node(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
  int x, y;
};
int n, m, u;
char ch[maxn][maxn];
int dis[1005][1005];
deque<node> q;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
bool judge(node p) {
  if (p.x <= 0 || p.x > n || p.y <= 0 || p.y > m || ch[p.x][p.y] == '*')
    return 0;
  return 1;
}
void OZbfs(int x, int y) {
  memset(dis, 0x3f, sizeof(dis));
  dis[x][y] = 0;
  deque<node> q;
  q.push_front(node(x, y));
  while (!q.empty()) {
    node p = q.front();
    q.pop_front();
    for (int i = 0; i <= 3; i++) {
      node tmp = node(p.x + dx[i], p.y + dy[i]);
      if (judge(tmp)) {
        if (dis[tmp.x][tmp.y] > dis[p.x][p.y] + (i == 3)) {
          dis[tmp.x][tmp.y] = dis[p.x][p.y] + (i == 3);
          if (i == 3)
            q.push_back(tmp);
          else
            q.push_front(tmp);
        }
      }
    }
  }
}
int main() {
  read(n);
  read(m);
  int x, y, l, r;
  read(x);
  read(y);
  read(l);
  read(r);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
  }
  OZbfs(x, y);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == '*') continue;
      int d = dis[i][j] + j - y;
      if (dis[i][j] <= l && d <= r) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
