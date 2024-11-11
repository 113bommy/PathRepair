#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int INF = 0x7fffffff;
const long long inf = (((long long)1) << 61) + 5;
const int N = 100005;
struct node {
  int l, r;
  pair<int, int> p;
} tree[N * 4];
void build(int x, int l, int r) {
  tree[x].l = l, tree[x].r = r;
  tree[x].p = make_pair(0, -1);
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}
void update(int x, int pos, pair<int, int> p) {
  if (tree[x].l == pos && tree[x].r == pos) {
    tree[x].p = max(tree[x].p, p);
    return;
  }
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (pos <= mid)
    update(x << 1, pos, p);
  else
    update(x << 1 | 1, pos, p);
  tree[x].p = max(tree[x << 1].p, tree[x << 1 | 1].p);
}
pair<int, int> query(int x, int l, int r) {
  if (l > r) return make_pair(0, -1);
  if (tree[x].l == l && tree[x].r == r) return tree[x].p;
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (r <= mid)
    return query(x << 1, l, r);
  else if (l > mid)
    return query(x << 1 | 1, l, r);
  else
    return max(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
}
int pre[N];
int dp[N];
long long a[N], b[N];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - (b + 1);
  build(1, 1, m);
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    pre[i] = -1;
    int l = lower_bound(b + 1, b + m + 1, a[i] - d) - b;
    int r = upper_bound(b + 1, b + m + 1, a[i] + d) - b;
    if (l > 0 && b[l] > a[i] - d) l--;
    if (r <= m && b[r] < a[i] + d) r++;
    pair<int, int> p = max(query(1, 1, l), query(1, r, m));
    if (p.first + 1 > dp[i]) {
      dp[i] = p.first + 1;
      pre[i] = p.second;
    }
    int id = lower_bound(b + 1, b + m + 1, a[i]) - b;
    update(1, id, make_pair(dp[i], i));
  }
  int ans = 0, pos = 1;
  for (int i = 1; i <= n; i++) {
    if (dp[i] > ans) {
      ans = dp[i];
      pos = i;
    }
  }
  vector<int> g;
  while (pos != -1) {
    g.push_back(pos);
    pos = pre[pos];
  }
  printf("%d\n", ans);
  for (int i = g.size() - 1; i >= 0; i--) printf("%d ", g[i]);
  puts("");
  return 0;
}
