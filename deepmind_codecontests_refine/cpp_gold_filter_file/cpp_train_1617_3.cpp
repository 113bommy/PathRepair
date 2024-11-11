#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1005;
int n, m, q;
int a[N];
bool isprime[N];
int prime[N], tot;
bitset<M> p, l;
void init(int m) {
  memset(isprime, true, sizeof(isprime));
  isprime[1] = false;
  for (int i = 2; i <= m; i++) {
    if (isprime[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] <= m; j++) {
      isprime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 0; i < m; i++) l[i] = 1;
  for (int i = 1; i < m; i++)
    if (isprime[i]) p[i] = 1;
  return;
}
struct Edge {
  int to, next;
} edge[N << 1];
int head[N], cnt;
void add_edge(int u, int v) {
  cnt++;
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
  return;
}
int w[N];
int dfn[N], Index;
int siz[N];
void dfs(int u, int father) {
  dfn[u] = ++Index;
  w[Index] = a[u];
  siz[u] = 1;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == father) continue;
    dfs(v, u);
    siz[u] += siz[v];
  }
  return;
}
struct Node {
  int l, r;
  int lazy;
  bitset<M> sum;
} tree[N << 2];
void push_up(int i) {
  tree[i].sum = tree[i * 2].sum | tree[i * 2 + 1].sum;
  return;
}
void build(int i, int l, int r) {
  tree[i].l = l, tree[i].r = r;
  if (l == r) {
    tree[i].sum[w[l] % m] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  push_up(i);
  return;
}
void add(int i, int k) {
  k %= m;
  tree[i].sum = ((tree[i].sum << k) | (tree[i].sum >> (m - k))) & l;
  tree[i].lazy = (tree[i].lazy + k) % m;
  return;
}
void push_down(int i) {
  if (!tree[i].lazy) return;
  add(i * 2, tree[i].lazy);
  add(i * 2 + 1, tree[i].lazy);
  tree[i].lazy = 0;
  return;
}
void modify(int i, int l, int r, int k) {
  if (l <= tree[i].l && tree[i].r <= r) {
    add(i, k);
    return;
  }
  push_down(i);
  if (l <= tree[i * 2].r) modify(i * 2, l, r, k);
  if (r >= tree[i * 2 + 1].l) modify(i * 2 + 1, l, r, k);
  push_up(i);
  return;
}
bitset<M> query(int i, int l, int r) {
  if (l <= tree[i].l && tree[i].r <= r) return tree[i].sum;
  push_down(i);
  if (r <= tree[i * 2].r)
    return query(i * 2, l, r);
  else if (l >= tree[i * 2 + 1].l)
    return query(i * 2 + 1, l, r);
  else
    return query(i * 2, l, r) | query(i * 2 + 1, l, r);
}
int main() {
  scanf("%d%d", &n, &m);
  init(m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  dfs(1, 0);
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int op, v, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &v, &x);
      modify(1, dfn[v], dfn[v] + siz[v] - 1, x);
    } else if (op == 2) {
      scanf("%d", &v);
      printf("%u\n", (query(1, dfn[v], dfn[v] + siz[v] - 1) & p).count());
    }
  }
  return 0;
}
