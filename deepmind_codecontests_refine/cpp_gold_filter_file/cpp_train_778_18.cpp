#include <bits/stdc++.h>
using namespace std;
vector<int> e[1000005];
vector<int> num[1000005], v1[1000005];
map<int, int> mp[1000005];
queue<int> q;
int read() {
  char ch = getchar();
  int f = 0, x = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    f = (f << 1) + (f << 3) + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct node {
  int from;
  int to;
  int next;
} edge[1000005];
int head[1000005], tot, n, m, val[1000005], cnt;
int dfn[1000005], tim, low[1000005], rev[1000005];
stack<int> s;
int du[1000005], belong[1000005];
int vis[1000005];
void link(int u, int v) {
  edge[tot].from = u;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void add(int u, int c, int i) {
  if (mp[u][c] != 0) {
    if (mp[u][c] == -1) {
      puts("No");
      exit(0);
    }
    link(i + m, mp[u][c]);
    link(mp[u][c] + m, i);
    mp[u][c] = -1;
  } else
    mp[u][c] = i;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++tim;
  s.push(x);
  vis[x] = 1;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    if (!dfn[edge[i].to])
      tarjan(edge[i].to), low[x] = min(low[x], low[edge[i].to]);
    else if (vis[edge[i].to])
      low[x] = min(low[x], low[edge[i].to]);
  }
  if (low[x] == dfn[x]) {
    int now;
    do {
      now = s.top();
      vis[s.top()] = 0;
      belong[s.top()] = x;
      if (s.top() <= 2 * m) num[x].push_back(s.top());
      s.pop();
    } while (now != x);
  }
}
int id[1000005], tm;
void topsort() {
  for (int i = 1; i <= cnt; i++) {
    if (belong[i] == i && du[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    id[++tm] = x;
    for (int i = 0; i < v1[x].size(); i++) {
      du[v1[x][i]]--;
      if (!du[v1[x][i]]) q.push(v1[x][i]);
    }
  }
}
bool choose(int x) {
  if (vis[x] == -1) return 0;
  if (vis[x] == 1) return 1;
  vis[x] = 1;
  for (int i = 0; i < num[x].size(); i++) {
    if (vis[belong[rev[num[x][i]]]] == 1) return 0;
    vis[belong[rev[num[x][i]]]] = -1;
  }
  for (int i = 0; i < v1[x].size(); i++) {
    if (!choose(v1[x][i])) return 0;
  }
  return 1;
}
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; i++) {
    if (val[i] > x) {
      if (!choose(belong[i + m])) return 0;
    }
  }
  for (int i = tm; i; i--) {
    int x = id[i];
    if (x > 2 * m) {
      if (num[x].size() == 0) continue;
      x = num[x].back();
    }
    if (vis[belong[x]] == 0) choose(belong[x]);
  }
  return 1;
}
int main() {
  memset(head, -1, sizeof(head));
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), c = read(), t = read();
    e[u].push_back(i);
    e[v].push_back(i);
    val[i] = t;
    add(u, c, i);
    add(v, c, i);
  }
  cnt = 2 * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      int temp = ++cnt;
      if (j) {
        link(e[i][j], temp - 1);
        link(temp, temp - 1);
      }
      link(temp, e[i][j] + m);
    }
    for (int j = e[i].size() - 1; j >= 0; j--) {
      int temp = ++cnt;
      if (j != e[i].size() - 1) {
        link(e[i][j], temp - 1);
        link(temp, temp - 1);
      }
      link(temp, e[i][j] + m);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= m; i++) {
    rev[i] = i + m;
    rev[i + m] = i;
    if (belong[i] == belong[i + m]) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = head[i]; j != -1; j = edge[j].next) {
      if (belong[i] != belong[edge[j].to]) {
        v1[belong[i]].push_back(belong[edge[j].to]);
        du[belong[edge[j].to]]++;
      }
    }
  }
  topsort();
  int l = 0, r = 1000000000, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  puts("Yes");
  check(ans);
  int cou = 0;
  for (int i = 1; i <= m; i++) {
    if (vis[belong[i]] == 1) cou++;
  }
  printf("%d %d\n", ans, cou);
  for (int i = 1; i <= m; i++) {
    if (vis[belong[i]] == 1) printf("%d ", i);
  }
}
