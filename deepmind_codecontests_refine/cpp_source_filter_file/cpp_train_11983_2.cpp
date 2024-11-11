#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 0, f = 1;
  char c = ' ';
  while (c < '0' || c > '9') c = getchar(), f = c == '-' ? -1 : f;
  while (c >= '0' && c <= '9') w = w * 10 + c - 48, c = getchar();
  return w * f;
}
struct node {
  int x;
  vector<int> s;
  node() { x = 0; }
} t[1 << 6];
vector<node> f[14];
bool vis[1 << 13];
int ans[100005 / 3 + 15][3], cnt;
void init() {
  for (int i = 1; i <= 13; i++) {
    f[i].resize(1 << i);
    for (int j = 0; j < (1 << i); j++) vis[j] = 0, f[i][j].x = -1;
    queue<node> q;
    q.push(node()), vis[0] = 1;
    while (!q.empty()) {
      node x = q.front();
      q.pop();
      f[i][x.x] = x;
      for (int j = 0; j < i - 2; j++)
        for (int k = 1; j + k * 2 < i; k++) {
          node y = x;
          for (int l = 0; l <= 2; l++)
            y.x ^= 1 << (j + k * l), y.s.push_back(j + k * l);
          if (!vis[y.x]) {
            q.push(y);
            vis[y.x] = 1;
          }
        }
    }
  }
  for (int i = 0; i < (1 << 6); i++) vis[i] = 0;
  queue<node> q;
  q.push(node()), vis[0] = 1;
  while (!q.empty()) {
    node x = q.front();
    q.pop();
    t[x.x] = x;
    for (int j = 0; j < 6; j++)
      for (int k = 1; j + k * 2 < 11; k++) {
        node y = x;
        for (int l = 0; l <= 2; l++)
          y.x ^= (j + k * l < 6) ? (1 << (j + k * l)) : 0,
              y.s.push_back(j + k * l);
        if (!vis[y.x]) {
          q.push(y);
          vis[y.x] = 1;
        }
      }
  }
}
int n, a[100005];
void work(int x) {
  int now = 0, s = 0;
  for (int i = x; i < x + 6; i++) now |= a[i] << (i - x);
  for (auto i : t[now].s) {
    ans[cnt][s++] = x + i;
    a[x + i] ^= 1;
    if (s == 3) cnt++, s = 0;
  }
}
signed main() {
  init();
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1;; i++)
    if (n - i + 1 >= 14)
      work(i);
    else {
      int now = 0, s = 0;
      for (int j = i; j <= n; j++) now |= a[j] << (j - i);
      if (f[n - i + 1][now].x == -1) return puts("NO"), 0;
      for (auto j : f[n - i + 1][now].s) {
        ans[cnt][s++] = i + j;
        if (s == 3) cnt++, s = 0;
      }
      break;
    }
  printf("YES\n%d\n", cnt);
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j <= 2; j++) printf("%d%c", ans[i][j], j == 2 ? '\n' : ' ');
  return 0;
}
