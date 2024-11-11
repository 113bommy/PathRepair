#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, -1, 1, 1, -1};
struct node {
  int sum = 0;
  node *left, *right;
  node(int sum = 0) : sum(sum), left(this), right(this) {}
  node(int sum, node *left, node *right) : sum(sum), left(left), right(right) {}
};
const int N = 1e5 + 5, M = 2 * N + 5, K = 18;
int n, m, q;
int arr[N], table[M][K], LG[M], parent[N];
vector<int> adj[N], people[N];
int sz = 0;
int E[M], L[M], F[N];
node *root[N];
node *insert(node *cur, int v, int l = 1, int r = n) {
  if (v > r || v < l) return cur;
  if (l == r) return new node(cur->sum + 1);
  int mid = l + ((r - l) >> 1);
  node *left = insert(cur->left, v, l, mid);
  node *right = insert(cur->right, v, mid + 1, r);
  return new node(cur->sum + 1, left, right);
}
int query(node *a, node *b, node *lca, node *lcap, int k, int l = 1,
          int r = n) {
  if (a->sum + b->sum - lca->sum - lcap->sum < k) return -1;
  if (l == r) return l;
  int mid = l + ((r - l) >> 1);
  int lefCnt = a->left->sum + b->left->sum - lca->left->sum - lcap->left->sum;
  if (k <= lefCnt)
    return query(a->left, b->left, lca->left, lcap->left, k, l, mid);
  return query(a->right, b->right, lca->right, lcap->right, k - lefCnt, mid + 1,
               r);
}
void dfs(int cur, int par, int level) {
  parent[cur] = par;
  E[sz] = cur;
  L[sz] = level;
  F[cur] = sz++;
  root[cur] = root[par];
  for (int person : people[cur]) root[cur] = insert(root[cur], person);
  for (int child : adj[cur]) {
    if (child == par) continue;
    dfs(child, cur, level + 1);
    E[sz] = cur;
    L[sz++] = level;
  }
}
void build() {
  root[0] = new node;
  dfs(1, 0, 0);
  LG[0] = -1;
  for (int i = 0; i < sz; i++) {
    table[i][0] = i;
    LG[i + 1] = LG[i] + ((i & (i + 1)) == 0);
  }
  for (int j = 1; j < K; j++) {
    for (int i = 1; i + (1 << j) - 1 < sz; i++) {
      int f = table[i][j - 1];
      int s = table[i + (1 << (j - 1))][j - 1];
      table[i][j] = L[f] < L[s] ? f : s;
    }
  }
}
int RMQ(int l, int r) {
  if (l > r) swap(l, r);
  int lg = LG[r - l + 1];
  int f = table[l][lg], s = table[r - (1 << lg) + 1][lg];
  return L[f] < L[s] ? f : s;
}
int LCA(int a, int b) {
  int pos = RMQ(F[a], F[b]);
  return E[pos];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int c;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &c);
    people[c].push_back(i);
  }
  build();
  int v, u;
  while (q--) {
    scanf("%d%d%d", &v, &u, &a);
    int lca = LCA(v, u);
    vector<int> info;
    for (int i = 1; i <= a; i++) {
      int x = query(root[v], root[u], root[lca], root[parent[lca]], i);
      if (x == -1) break;
      info.push_back(x);
    }
    printf("%d ", info.size());
    for (int x : info) printf("%d ", x);
    puts("");
  }
}
