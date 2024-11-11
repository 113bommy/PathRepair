#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
int n, a[300032], b[300032], Size, head[300032 * 8], num, root, dis[300032 * 8],
    re[300032 * 8];
bool vis[300032 * 8];
struct edge {
  int next, to, vlu;
} mem[300032 * 20];
void add(int u, int v, int vlu) {
  mem[++Size].to = v;
  mem[Size].next = head[u];
  head[u] = Size;
  mem[Size].vlu = vlu;
}
struct TREE {
  int son[2];
} tr[300032 * 8];
void build(int& rt, int l, int r) {
  if (l == r) {
    rt = l + n + 1;
    return;
  }
  rt = ++num;
  int mid = l + r >> 1;
  build(tr[rt].son[0], l, mid);
  build(tr[rt].son[1], mid + 1, r);
  add(rt, tr[rt].son[0], 0);
  add(rt, tr[rt].son[1], 0);
}
void update(int rt, int l, int r, int first, int end) {
  if (first <= l && r <= end) {
    add(end, rt, 1);
    return;
  }
  int mid = l + r >> 1;
  if (first <= mid) update(tr[rt].son[0], l, mid, first, end);
  if (end > mid) update(tr[rt].son[1], mid + 1, r, first, end);
}
struct node {
  int x, dis;
  bool operator<(node A) const { return dis > A.dis; }
};
priority_queue<node> q;
void dij() {
  for (int i = 1; i <= num; ++i) dis[i] = 1e9;
  dis[n] = 0;
  q.push(node{n, 0});
  while (!q.empty()) {
    node now = q.top();
    q.pop();
    if (vis[now.x]) continue;
    vis[now.x] = 1;
    for (int i = head[now.x]; i; i = mem[i].next) {
      int v = mem[i].to;
      if (dis[v] > dis[now.x] + mem[i].vlu) {
        dis[v] = dis[now.x] + mem[i].vlu;
        re[v] = now.x;
        q.push(node{v, dis[v]});
      }
    }
  }
}
vector<int> as;
int main() {
  n = read();
  num = n * 2 + 1;
  build(root, 0, n);
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    update(root, 0, n, i - a[i], i);
  }
  for (int i = 1; i <= n; ++i) b[i] = read(), add(i + n + 1, i + b[i], 0);
  dij();
  if (dis[n + 1] == 1e9)
    cout << -1;
  else {
    cout << dis[n + 1] << '\n';
    int tmp = n + 1;
    while (tmp != n) {
      if (tmp >= n + 1 && tmp <= 2 * n + 1) as.push_back(tmp - n - 1);
      tmp = re[tmp];
    }
    for (int i = as.size() - 1; i >= 0; --i) cout << as[i] << " ";
  }
  return 0;
}
