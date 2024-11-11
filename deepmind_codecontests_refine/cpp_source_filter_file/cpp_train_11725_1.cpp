#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[200005];
long long st[200005], en[200005];
long long t[200005];
long long cnt;
long long in[200005];
void dfs(long long u) {
  cnt++;
  st[u] = cnt;
  long long i, v;
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    dfs(v);
  }
  en[u] = cnt;
}
long long tree[200005 * 4];
long long lazy[200005 * 4];
void propagate(long long node, long long r1, long long r2) {
  tree[node] = (r2 - r1 + 1) - tree[node];
  if (r1 != r2) {
    lazy[node * 2] ^= 1;
    lazy[node * 2 + 1] ^= 1;
  }
  lazy[node] = 0;
}
void build(long long node, long long r1, long long r2) {
  if (r1 == r2) {
    tree[node] = in[r1];
    return;
  }
  long long bam = node * 2;
  long long dan = bam + 1;
  long long mid = (r1 + r2) / 2;
  build(bam, r1, mid);
  build(dan, mid + 1, r2);
  tree[node] = tree[bam] + tree[dan];
}
void update(long long node, long long r1, long long r2, long long i,
            long long j) {
  long long bam = node * 2;
  long long dan = bam + 1;
  if (lazy[node]) propagate(node, r1, r2);
  if (r1 > j || r2 < i) return;
  if (r1 >= i && r2 <= j) {
    tree[node] = (r2 - r1 + 1) - tree[node];
    if (r1 != r2) {
      lazy[bam] ^= 1;
      lazy[dan] ^= 1;
    }
    return;
  }
  long long mid = (r1 + r2) / 2;
  update(bam, r1, mid, i, j);
  update(dan, mid + 1, r2, i, j);
  tree[node] = tree[bam] + tree[dan];
}
long long query(long long node, long long r1, long long r2, long long i,
                long long j) {
  long long bam = node * 2;
  long long dan = bam + 1;
  if (r1 > i || r2 < i) return 0;
  if (lazy[node]) propagate(node, r1, r2);
  if (r1 >= i && r2 <= j) return tree[node];
  long long mid = (r1 + r2) / 2;
  long long p1 = query(bam, r1, mid, i, j);
  long long p2 = query(dan, mid + 1, r2, i, j);
  return (p1 + p2);
}
int main() {
  long long n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
  scanf("%lld", &n);
  for (i = 2; i <= n; i++) {
    scanf("%lld", &x);
    adj[x].push_back(i);
  }
  for (i = 1; i <= n; i++) scanf("%lld", &t[i]);
  dfs(1);
  for (i = 1; i <= n; i++) in[st[i]] = t[i];
  build(1, 1, n);
  scanf("%lld", &q);
  string com;
  while (q--) {
    cin >> com >> x;
    i = st[x];
    j = en[x];
    if (com == "get") {
      ans = query(1, 1, n, i, j);
      printf("%lld\n", ans);
    } else
      update(1, 1, n, i, j);
  }
  return 0;
}
