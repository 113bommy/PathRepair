#include <bits/stdc++.h>
using namespace std;
int read() {
  int ans = 0, flag = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') flag = -flag;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ans = ans * 10 + ch - '0';
    ch = getchar();
  }
  return ans * flag;
}
const int N = 5010;
const int INF = 1000000000;
struct node {
  int id, l, r;
  bool operator<(const node a) { return r < a.r; }
} a[N];
int anum;
bool cmp(node a, node b) { return a.l < b.l; }
struct heap {
  int heapcnt = 0;
  node h[N];
  void push(node x) {
    h[++heapcnt] = x;
    int now = heapcnt;
    while (now / 2) {
      if (h[now] < h[now / 2]) {
        swap(h[now], h[now / 2]);
        now /= 2;
      } else
        break;
    }
  }
  void pop() {
    h[1] = (node){0, 0, 0};
    h[1] = h[heapcnt];
    h[heapcnt--] = (node){0, 0, 0};
    int now = 1, son = 2;
    while (son <= heapcnt) {
      if (son + 1 <= heapcnt && h[son + 1] < h[son]) ++son;
      if (h[son] < h[now]) {
        swap(h[son], h[now]);
        now = son;
        son = now * 2;
      } else
        break;
    }
  }
} q;
int n, m;
struct edge {
  int t, n, f;
} e[400010];
int head[4 * N], cur[4 * N], tot = 1;
void addedge(int u, int v, int w) {
  ++tot;
  e[tot].t = v;
  e[tot].n = head[u];
  e[tot].f = w;
  head[u] = tot;
  ++tot;
  e[tot].t = u;
  e[tot].n = head[v];
  e[tot].f = 0;
  head[v] = tot;
}
int ch[4 * N][2];
int id[4 * N];
int rt = 1, cnt = 1;
int s, t;
int d[4 * N];
int f[4 * N];
int opt[N];
int ll[N], rr[N];
int match[N];
void build(int &x, int l, int r) {
  if (!x) x = ++cnt;
  if (l == r) {
    id[x] = l;
    return;
  } else {
    build(ch[x][0], l, ((l + r) >> 1));
    build(ch[x][1], ((l + r) >> 1) + 1, r);
    addedge(x + n * 2, ch[x][0] + n * 2, INF);
    addedge(x + n * 2, ch[x][1] + n * 2, INF);
  }
}
void add(int x, int l, int r, int ll, int rr, int u) {
  if (l >= ll && r <= rr)
    addedge(u, x + n * 2, 1);
  else {
    if (((l + r) >> 1) >= ll) add(ch[x][0], l, ((l + r) >> 1), ll, rr, u);
    if (((l + r) >> 1) < rr) add(ch[x][1], ((l + r) >> 1) + 1, r, ll, rr, u);
  }
}
void buildedge(int x, int l, int r) {
  if (l == r)
    addedge(x + n * 2, t, 1);
  else {
    buildedge(ch[x][0], l, ((l + r) >> 1));
    buildedge(ch[x][1], ((l + r) >> 1) + 1, r);
  }
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i; i = e[i].n) {
    cur[now] = i;
    if (e[i].f > 0 && d[e[i].t] + 1 == d[now]) {
      int tmp = dfs(e[i].t, min(e[i].f, flow - use));
      use += tmp;
      e[i].f -= tmp;
      e[i ^ 1].f += tmp;
      if (flow == use) return use;
    }
  }
  cur[now] = head[now];
  if (!--f[d[now]]) d[s] = 2 * n + cnt + 2;
  ++f[++d[now]];
  return use;
}
int main() {
  n = read();
  m = read();
  build(rt, 1, m);
  for (int i = 1; i <= n; ++i) {
    opt[i] = read();
    if (opt[i] == 0) {
      int k = read();
      addedge(i, i + n, 1);
      for (int j = 1; j <= k; ++j) {
        int pos = read();
        add(1, 1, m, pos, pos, i + n);
      }
    } else if (opt[i] == 1) {
      ll[i] = read();
      rr[i] = read();
      addedge(i, i + n, 1);
      add(1, 1, m, ll[i], rr[i], i + n);
    } else {
      int a = read(), b = read(), c = read();
      addedge(i, i + n, 2);
      add(1, 1, m, a, a, i + n);
      add(1, 1, m, b, b, i + n);
      add(1, 1, m, c, c, i + n);
    }
  }
  s = 2 * n + cnt + 1;
  t = 2 * n + cnt + 2;
  for (int i = 1; i <= n; ++i) addedge(s, i, INF);
  buildedge(1, 1, m);
  f[0] = 2 * n + cnt + 2;
  int ans = 0;
  while (d[s] < 2 * n + cnt + 2) ans += dfs(s, 1 << 30);
  printf("%d\n", ans);
  for (int i = head[t]; i; i = e[i].n) {
    if (e[i].f == 1)
      match[id[e[i].t - 2 * n]] = 0;
    else
      match[id[e[i].t - 2 * n]] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    if (opt[i] == 2) {
      int nowflow = 0;
      for (int j = head[i + n]; j; j = e[j].n) {
        if (e[j].t > 2 * n && e[j].f == 0) {
          match[id[e[j].t - 2 * n]] = i;
          ++nowflow;
        }
      }
      if (nowflow == 2 || nowflow == 0) continue;
      for (int j = head[i + n]; j; j = e[j].n) {
        if (e[j].t > 2 * n && match[id[e[j].t - 2 * n]] == 0) {
          match[id[e[j].t - 2 * n]] = i;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (opt[i] == 0) {
      for (int j = head[i + n]; j; j = e[j].n) {
        if (e[j].t > 2 * n && e[j].f == 0 && match[id[e[j].t - 2 * n]] == 0) {
          match[id[e[j].t - 2 * n]] = i;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (opt[i] == 1) a[++anum] = (node){i, ll[i], rr[i]};
  sort(a + 1, a + anum + 1, cmp);
  int top = 1;
  for (int i = 1; i <= n; ++i) {
    while (top <= anum && a[top].l <= i) q.push(a[top++]);
    while (q.heapcnt && q.h[1].r < i) {
      q.pop();
    }
    if (match[i] == 0 && q.heapcnt) {
      match[i] = q.h[1].id;
      q.pop();
    }
  }
  for (int i = 1; i <= m; ++i)
    if (match[i] != -1) printf("%d %d\n", match[i], i);
  return 0;
}
