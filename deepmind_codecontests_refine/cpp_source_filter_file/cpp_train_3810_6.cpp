#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 2277;
class Query {
 public:
  int l, r, type, val;
  Query(int l, int r, int type, int val) {
    this->l = l;
    this->r = r;
    this->type = type;
    this->val = val;
  }
};
int n, k, a[N], rmq[N][20], node[4 * N], lazy[4 * N], q;
vector<int> indices;
vector<Query> queries;
void input() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  indices.push_back(0);
  indices.push_back(1);
  indices.push_back(n * k + 1);
  while (q--) {
    int type, l, r, x;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d %d", &l, &r, &x);
      queries.push_back(Query(l, r, type, x));
    } else {
      scanf("%d %d", &l, &r);
      queries.push_back(Query(l, r, type, 0));
    }
    indices.push_back(l);
    indices.push_back(r + 1);
  }
}
void prep() {
  for (int i = 1; i <= n; i++) rmq[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int get(int u, int v) {
  int LG = log2(v - u + 1);
  return min(rmq[u][LG], rmq[v - (1 << LG) + 1][LG]);
}
void build_tree(int i, int l, int r) {
  if (l > r) return;
  if (l == r) {
    lazy[i] = 0;
    int left = indices[l];
    int right = indices[r + 1] - 1;
    int nxt_left = (left + n - 1) / n;
    int nxt_right = (right + n - 1) / n;
    left = (left % n == 0 ? n : left % n);
    right = (right % n == 0 ? n : right % n);
    if (nxt_right - nxt_left > 1)
      node[i] = get(1, n);
    else if (nxt_right - nxt_left == 1)
      node[i] = min(get(1, right), get(left, n));
    else
      node[i] = get(left, right);
    return;
  }
  lazy[i] = 0;
  int m = (l + r) >> 1;
  build_tree(i << 1, l, m);
  build_tree(i << 1 | 1, m + 1, r);
  node[i] = min(node[i << 1], node[i << 1 | 1]);
}
void dolazy(int i, int l, int r) {
  if (lazy[i]) {
    node[i] = lazy[i];
    if (l != r) {
      lazy[i << 1] = lazy[i];
      lazy[i << 1 | 1] = lazy[i];
    }
    lazy[i] = 0;
  }
}
void update(int i, int l, int r, int a, int b, int val) {
  dolazy(i, l, r);
  if (l > r || a > r || b < l) return;
  if (a <= l && r <= b) {
    node[i] = val;
    if (l != r) {
      lazy[i << 1] = val;
      lazy[i << 1 | 1] = val;
    }
    return;
  }
  int m = (l + r) >> 1;
  update(i << 1, l, m, a, b, val);
  update(i << 1 | 1, m + 1, r, a, b, val);
  node[i] = min(node[i << 1], node[i << 1 | 1]);
}
int query(int i, int l, int r, int a, int b) {
  if (l > r || a > r || b < l) return inf;
  dolazy(i, l, r);
  if (a <= l && r <= b) return node[i];
  int m = (l + r) >> 1;
  return min(query(i << 1, l, m, a, b), query(i << 1 | 1, m + 1, r, a, b));
}
void solve() {
  sort(indices.begin(), indices.end());
  indices.resize(unique(indices.begin(), indices.end()) - indices.begin());
  build_tree(1, 1, (int)indices.size() - 2);
  for (int i = 0; i < queries.size(); i++) {
    int a = lower_bound(indices.begin(), indices.end(), queries[i].l) -
            indices.begin();
    int b = upper_bound(indices.begin(), indices.end(), queries[i].r) -
            indices.begin() - 1;
    if (queries[i].type == 1)
      update(1, 1, (int)indices.size() - 2, a, b, queries[i].val);
    else
      printf("%d\n", query(1, 1, (int)indices.size() - 2, a, b));
  }
}
int main() {
  input();
  prep();
  solve();
  return 0;
}
