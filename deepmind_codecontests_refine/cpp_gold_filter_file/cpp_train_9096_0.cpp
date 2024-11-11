#include <bits/stdc++.h>
using namespace std;
char str;
int n, m, g;
int num[20480];
struct edge {
  int to;
  int nxt;
  int val;
} nd[8 * 20480];
int head[20480], cnt;
int cur[20480], dep[20480];
queue<int> q;
int ans;
template <class X>
inline void read(X &x) {
  x = 0;
  X f = 1;
  while (!isdigit(str)) {
    if (str == '-') {
      f = -1;
    }
    str = getchar();
  }
  while (isdigit(str)) {
    x *= 10;
    x += str - '0';
    str = getchar();
  }
  x *= f;
  return;
}
void init() {
  memset(head, -1, sizeof(head));
  cnt = 0;
  return;
}
void add(int x, int y, int z) {
  nd[cnt].to = y;
  nd[cnt].nxt = head[x];
  nd[cnt].val = z;
  head[x] = cnt++;
  return;
}
bool bfs(int s, int t) {
  memset(dep, 0x3f, sizeof(dep));
  memcpy(cur, head, sizeof(cur));
  while (q.size()) {
    q.pop();
  }
  q.push(s);
  dep[s] = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = nd[i].nxt) {
      int tt = nd[i].to;
      if (dep[tt] == 0x3f3f3f3f && nd[i].val) {
        dep[tt] = dep[x] + 1;
        q.push(tt);
      }
    }
  }
  return dep[t] != 0x3f3f3f3f;
}
int dfs(int x, int t, int lim) {
  if (x == t || !lim) {
    return lim;
  }
  int ff = 0, f;
  for (int i = cur[x]; i != -1; i = nd[i].nxt) {
    cur[x] = i;
    int tt = nd[i].to;
    if (dep[tt] == dep[x] + 1 && (f = dfs(tt, t, min(lim, nd[i].val)))) {
      ff += f;
      lim -= f;
      nd[i].val -= f;
      nd[i ^ 1].val += f;
      if (!lim) {
        break;
      }
    }
  }
  return ff;
}
void dinic(int s, int t) {
  while (bfs(s, t)) {
    ans -= dfs(s, t, 0x3f3f3f3f);
  }
  return;
}
int main() {
  init();
  read(n), read(m), read(g);
  for (int i = 1; i <= n; i++) {
    read(num[i]);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    read(x);
    if (num[i]) {
      add(i, n + m + 1, x);
      add(n + m + 1, i, 0);
    } else {
      add(0, i, x);
      add(i, 0, 0);
    }
  }
  for (int i = 1; i <= m; i++) {
    int opt, x, k;
    read(opt), read(x), read(k);
    ans += x;
    for (int j = 1; j <= k; j++) {
      int y;
      read(y);
      if (opt == 0) {
        add(n + i, y, 0x3f3f3f3f);
        add(y, n + i, 0);
      } else {
        add(y, n + i, 0x3f3f3f3f);
        add(n + i, y, 0);
      }
    }
    int z;
    read(z);
    if (opt == 0) {
      add(0, n + i, z * g + x);
      add(n + i, 0, 0);
    } else {
      add(n + i, n + m + 1, z * g + x);
      add(n + m + 1, n + i, 0);
    }
  }
  dinic(0, n + m + 1);
  printf("%d\n", ans);
  return 0;
}
