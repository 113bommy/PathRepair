#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, maxm = 6e5 + 5;
long long dis[maxn];
int ans[maxm];
int n, m, k, tot, cnt;
bool bo[maxn], vis[maxn];
int now[maxn], pre[maxm], son[maxm], val[maxm];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
void add(int a, int b, int c) {
  pre[++tot] = now[a];
  val[tot] = c;
  now[a] = tot;
  son[tot] = b;
}
struct node {
  int u;
  long long dis;
  node() {}
  node(int _u, long long _dis) { u = _u, dis = _dis; }
  bool operator<(const node &a) const { return dis < a.dis; }
};
struct Heap {
  int tot;
  node tree[maxm];
  void ins(node a) {
    tree[++tot] = a;
    int pos = tot;
    while (pos > 1) {
      if (tree[pos] < tree[pos >> 1])
        swap(tree[pos], tree[pos >> 1]), pos >>= 1;
      else
        break;
    }
  }
  node pop() {
    node res = tree[1];
    tree[1] = tree[tot--];
    int pos = 1;
    while ((pos << 1) <= tot) {
      int nxt = pos << 1;
      if ((nxt | 1) <= tot && tree[nxt | 1] < tree[nxt]) nxt |= 1;
      if (tree[nxt] < tree[pos])
        swap(tree[nxt], tree[pos]), pos = nxt;
      else
        break;
    }
    return res;
  }
} H;
void dijkstra() {
  memset(dis, 63, sizeof(dis));
  dis[1] = 0;
  H.ins(node(1, 0));
  while (H.tot) {
    node fake = H.pop();
    int u = fake.u;
    if (fake.dis > dis[u]) continue;
    for (int p = now[u], v = son[p]; p; p = pre[p], v = son[p])
      if (dis[v] > dis[u] + val[p]) {
        dis[v] = dis[u] + val[p];
        H.ins(node(v, dis[v]));
      }
  }
}
void dfs(int u) {
  if (cnt == k) return;
  for (int p = now[u], v = son[p]; p; p = pre[p], v = son[p])
    if (!bo[v] && dis[v] == dis[u] + val[p] && cnt < k)
      ans[++cnt] = (p + 1) >> 1, bo[v] = 1, dfs(v);
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read(), v = read();
    add(a, b, v);
    add(b, a, v);
  }
  dijkstra();
  bo[1] = 1;
  dfs(1);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
