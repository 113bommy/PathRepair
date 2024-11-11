#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 2e5 + 5;
const int INF = 1e9;
int n;
struct edge {
  int x, y;
  bool swp;
} e[N];
set<int> s[10][10];
int siz[10][10];
char s1[20], s2[20];
int key[10];
int k;
struct Prufer {
  int n, a[20];
  int e[20][2];
  int ext[20];
  void gettree() {
    for (int i = 1; i <= n; i++) ext[i] = 0;
    for (int i = 1; i <= n - 2; i++) ext[a[i]]++;
    for (int i = 1; i <= n - 2; i++) {
      int w = 0;
      for (int x = 1; x <= n; x++)
        if (ext[x] == 0) {
          w = x;
          break;
        }
      e[i][0] = a[i];
      e[i][1] = w;
      ext[a[i]]--;
      ext[w] = -1;
    }
    for (int i = 1; i <= n; i++)
      if (ext[i] != -1)
        for (int j = i + 1; j <= n; j++)
          if (ext[j] != -1) {
            e[n - 1][0] = i;
            e[n - 1][1] = j;
          }
    for (int i = 1; i <= n - 1; i++)
      if (e[i][0] > e[i][1]) swap(e[i][0], e[i][1]);
  }
} A;
struct Network_Flow {
  int n, st, ed;
  int tot;
  int h[105];
  struct edge {
    int x, f, nxt;
  } e[1005];
  void init(int n_, int st_, int ed_) {
    n = n_;
    st = st_;
    ed = ed_;
    for (int i = 1; i <= n; i++) h[i] = 0;
    tot = 1;
  }
  void addedge(int x, int y, int f) {
    e[++tot].x = y;
    e[tot].f = f;
    e[tot].nxt = h[x];
    h[x] = tot;
  }
  void inse(int x, int y, int f) {
    addedge(x, y, f);
    addedge(y, x, 0);
  }
  int que[105];
  int dis[105];
  bool bfs() {
    int he = 0, ta = 1;
    for (int i = 1; i <= n; i++) dis[i] = -1;
    que[1] = st;
    dis[st] = 0;
    for (; he < ta;) {
      int x = que[++he];
      for (int p = h[x]; p; p = e[p].nxt)
        if (e[p].f && dis[e[p].x] == -1) {
          dis[e[p].x] = dis[x] + 1;
          que[++ta] = e[p].x;
        }
    }
    return dis[ed] != -1;
  }
  int vis[105], tim;
  int aug(int x, int f) {
    if (x == ed) return f;
    int ret = 0;
    for (int p = h[x]; p; p = e[p].nxt)
      if (dis[e[p].x] == dis[x] + 1 && e[p].f) {
        int o = aug(e[p].x, min(f, e[p].f));
        e[p].f -= o, e[p ^ 1].f += o;
        ret += o, f -= o;
        if (!f) return ret;
      }
    return ret;
  }
  int flow() {
    tim = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    int ret = 0;
    while (bfs()) ret = ret + aug(st, INF);
    return ret;
  }
} network;
int id[10][10];
int now[10];
void push(int tx, int ty, int x, int y) {
  int id = *s[tx][ty].begin();
  s[tx][ty].erase(s[tx][ty].begin());
  e[id].x = x;
  e[id].y = y;
}
void getans() {
  for (int i = 1; i <= k; i++) now[i] = key[i] + 1;
  for (int i = 1; i <= k - 1; i++)
    push(A.e[i][0], A.e[i][1], key[A.e[i][0]], key[A.e[i][1]]);
  for (int i = 1; i <= k; i++)
    for (int j = i; j <= k; j++) {
      int w = id[i][j];
      for (int p = network.h[w]; p; p = network.e[p].nxt) {
        if (network.e[p].x == i)
          for (int d = 1; d <= network.e[p ^ 1].f; d++)
            push(i, j, now[i]++, key[j]);
        if (network.e[p].x == j && i != j)
          for (int d = 1; d <= network.e[p ^ 1].f; d++)
            push(i, j, key[i], now[j]++);
      }
    }
}
bool Dfs_Prufer(int x) {
  if (x >= k - 1) {
    A.gettree();
    bool pd = 1;
    for (int i = 1; i <= k - 1; i++) pd &= (siz[A.e[i][0]][A.e[i][1]] > 0);
    if (!pd) return 0;
    for (int i = 1; i <= k - 1; i++) siz[A.e[i][0]][A.e[i][1]]--;
    network.init(50, 49, 50);
    for (int i = 1; i <= k; i++)
      network.inse(i, network.ed, min(key[i + 1] - 1, n) - key[i]);
    int pre = k;
    for (int i = 1; i <= k; i++)
      for (int j = i; j <= k; j++) {
        id[i][j] = ++pre;
        network.inse(network.st, id[i][j], siz[i][j]);
        network.inse(id[i][j], i, INF);
        if (i != j) network.inse(id[i][j], j, INF);
      }
    for (int i = 1; i <= k - 1; i++) siz[A.e[i][0]][A.e[i][1]]++;
    int ret = network.flow();
    if (ret == n - k) {
      getans();
      return 1;
    }
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    A.a[x] = i;
    if (Dfs_Prufer(x + 1)) return 1;
  }
  return 0;
}
int main() {
  n = get();
  key[1] = 1;
  for (int i = 2; i <= 7; i++) key[i] = key[i - 1] * 10;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    e[i].x = strlen(s1 + 1);
    e[i].y = strlen(s2 + 1);
    e[i].swp = 0;
    if (e[i].x > e[i].y) {
      swap(e[i].x, e[i].y);
      e[i].swp = 1;
    }
    siz[e[i].x][e[i].y]++;
    s[e[i].x][e[i].y].insert(i);
  }
  for (int i = 1; i <= 7; i++)
    if (key[i] <= n) k = i;
  A.n = k;
  if (!Dfs_Prufer(1)) return printf("-1\n"), 0;
  for (int i = 1; i <= n - 1; i++) {
    if (e[i].swp) swap(e[i].x, e[i].y);
    printf("%d %d\n", e[i].x, e[i].y);
  }
  return 0;
}
