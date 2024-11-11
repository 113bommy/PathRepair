#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int x;
  while (c = getchar(), c < '0' || c > '9')
    ;
  x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  return x;
}
int n, m, S, T, cnt, p[10005], nxt[10005], head[10005], dis[10005];
long long ans, sum;
struct node {
  int to;
  long long val;
} L[10005];
void add(int x, int y, long long c) {
  L[cnt] = (node){y, c};
  nxt[cnt] = head[x];
  head[x] = cnt;
  cnt++;
  L[cnt] = (node){x, 0};
  nxt[cnt] = head[x];
  head[x] = cnt;
  cnt++;
}
queue<int> q;
int BFS() {
  memset(dis, 0, sizeof(dis));
  dis[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = nxt[i]) {
      int to = L[i].to;
      if (!dis[to] && L[i].val) {
        q.push(to);
        dis[to] = dis[x] + 1;
      }
    }
  }
  return dis[T];
}
long long DFS(int x, long long now) {
  if (x == T) return now;
  int res = 0;
  for (int i = head[x]; i != -1 && now; i = nxt[i]) {
    int to = L[i].to;
    if (dis[to] == dis[x] + 1 && L[i].val) {
      long long fd = DFS(to, min(now, L[i].val));
      res += fd;
      now -= fd;
      L[i].val -= fd;
      L[i ^ 1].val += fd;
    }
  }
  if (!res) dis[x] = -1;
  return res;
}
int main() {
  n = read();
  m = read();
  S = 0;
  T = n + m + 1;
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++) p[i] = read();
  for (int i = 1; i <= n; i++) add(i, T, p[i]);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), c = read();
    sum += c;
    add(n + i, x, 1e18);
    add(n + i, y, 1e18);
    add(S, n + i, c);
  }
  while (BFS()) ans += DFS(S, 2e9);
  printf("%lld", sum - ans);
  return 0;
}
