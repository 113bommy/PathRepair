#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5 + 5);
int par[N], sz[N], a[N], l[N], r[N], n, tree[4 * N], size, wait[4 * N];
vector<pair<int, int> > ans;
int get(int v) {
  if (par[v] != v) par[v] = get(par[v]);
  return par[v];
}
void uni(int v1, int v2) {
  v1 = get(v1);
  v2 = get(v2);
  if (sz[v1] < sz[v2]) {
    par[v1] = v2;
    sz[v2] += sz[v1];
    l[v2] = min(l[v1], l[v2]);
    r[v2] = max(r[v1], r[v2]);
  } else {
    par[v2] = v1;
    sz[v1] += sz[v2];
    l[v1] = min(l[v1], l[v2]);
    r[v1] = max(r[v1], r[v2]);
  }
}
void build() {
  size = 1;
  while (size < n) size <<= 1;
  for (int i = 0; i < n; i++) tree[size + i] = a[i];
  for (int i = size - 1; i > 0; i--)
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}
void push(int v) {
  if (!wait[v]) return;
  if (v < size) {
    wait[v * 2] += wait[v];
    wait[v * 2 + 1] += wait[v];
  }
  tree[v] += wait[v];
  wait[v] = 0;
}
void update(int l, int r, int L, int R, int v, int val) {
  push(v);
  if (r <= L || R <= l) return;
  if (l <= L && R <= r) {
    wait[v] += val;
    return;
  }
  int mid = (L + R) / 2;
  update(l, r, L, mid, v * 2, val);
  update(l, r, mid, R, v * 2 + 1, val);
  tree[v] = max(tree[v * 2] + wait[v * 2], tree[v * 2 + 1] + wait[v * 2 + 1]);
}
int go_to_max(int v, int l, int r) {
  push(v);
  int mid = (l + r) / 2;
  if (l + 1 == r) return l;
  if (tree[v] == tree[v * 2]) return go_to_max(v * 2, l, mid);
  return go_to_max(v * 2 + 1, mid, r);
}
int max(int l, int r, int L, int R, int v) {
  push(v);
  if (r <= L || R <= l) return 0;
  if (l <= L && R <= r) return tree[v];
  int mid = (L + R) / 2;
  int ret_val = max(max(l, r, L, mid, v * 2), max(l, r, mid, R, v * 2 + 1));
  tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  return ret_val;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sz[i + 1] = 1;
    par[i + 1] = i + 1;
    l[i + 1] = r[i + 1] = i + 1;
  }
  for (int i = 1; i < n; i++)
    if (a[i] == a[i - 1]) uni(i + 1, i);
  build();
  while (tree[1] + wait[1]) {
    int pos = go_to_max(1, 1, size + 1);
    int mx = tree[1] + wait[1] - 1;
    int st = get(pos);
    update(l[st], r[st] + 1, 1, size + 1, 1, -1);
    ans.push_back(make_pair(l[st], r[st]));
    if (max(l[st] - 1, l[st], 1, size + 1, 1) == mx) uni(st, l[st] - 1);
    if (max(r[st] + 1, r[st] + 2, 1, size + 1, 1) == mx) uni(st, r[st] + 1);
  }
  printf("%d\n", (int)(ans).size());
  for (int i = 0; i < (int)(ans).size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
