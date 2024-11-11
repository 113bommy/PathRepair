#include <bits/stdc++.h>
using namespace std;
vector<int> adj[400005];
int vec[400005], a[400005], pos = 1;
int entrada[400005], saida[400005], lazy[400005];
bitset<65> tree[800005], cnt;
int left(int u) { return (u << 1); }
int right(int u) { return (u << 1) + 1; }
void dfs(int u, int p) {
  vec[pos] = u;
  entrada[u] = pos++;
  for (int v : adj[u])
    if (v != p) dfs(v, u);
  saida[u] = pos - 1;
}
void push(int u, int L, int R) {
  if (lazy[u] != 0) {
    tree[u].reset();
    tree[u][lazy[u]] = 1;
    if (L != R) {
      lazy[left(u)] = lazy[u];
      lazy[right(u)] = lazy[u];
    }
    lazy[u] = 0;
  }
}
void build(int u, int L, int R) {
  tree[u].reset();
  if (L == R) {
    tree[u][a[vec[L]]] = 1;
  } else {
    int mid = (L + R) / 2;
    build(left(u), L, mid);
    build(right(u), mid + 1, R);
    tree[u] = tree[left(u)] | tree[right(u)];
  }
}
void update(int u, int L, int R, int i, int j, int k) {
  push(u, L, R);
  if (R < i || j < L) return;
  if (L >= i and R <= j) {
    lazy[u] = k;
    push(u, L, R);
    return;
  }
  int mid = (L + R) / 2;
  update(left(u), L, mid, i, j, k);
  update(right(u), mid + 1, R, i, j, k);
  tree[u] = tree[left(u)] | tree[right(u)];
}
void query(int u, int L, int R, int i, int j) {
  push(u, L, R);
  if (R < i || j < L) return;
  if (L >= i and R <= j) {
    cnt |= tree[u];
    return;
  }
  int mid = (L + R) / 2;
  query(left(u), L, mid, i, j);
  query(right(u), mid + 1, R, i, j);
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  pos--;
  build(1, 1, pos);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int v, k;
      scanf("%d %d", &v, &k);
      update(1, 1, pos, entrada[v], saida[v], k);
    } else {
      int v;
      scanf("%d", &v);
      cnt.reset();
      query(1, 1, pos, entrada[v], saida[v]);
      printf("%d\n", int(cnt.count()));
    }
  }
  return 0;
}
