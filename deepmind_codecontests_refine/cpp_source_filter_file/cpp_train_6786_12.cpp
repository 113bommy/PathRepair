#include <bits/stdc++.h>
using namespace std;
namespace zyt {
const int N = 5e5 + 10;
int n, w[N], tmp[N << 1], cnt;
vector<int> v[N << 1];
pair<int, int> arr[N];
namespace Segment_Tree {
struct node {
  pair<long long, int> mx;
  long long tag;
} tree[N << 2];
void update(const int rot) {
  tree[rot].mx = max(tree[rot << 1].mx, tree[rot << 1 | 1].mx);
}
void add(const int rot, const long long x) {
  tree[rot].mx.first += x;
  tree[rot].tag += x;
}
void pushdown(const int rot) {
  if (tree[rot].tag) {
    add(rot << 1, tree[rot].tag);
    add(rot << 1 | 1, tree[rot].tag);
    tree[rot].tag = 0;
  }
}
void build(const int rot, const int lt, const int rt) {
  tree[rot].tag = 0;
  if (lt == rt) {
    tree[rot].mx.first = -tmp[lt];
    tree[rot].mx.second = tmp[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  build(rot << 1, lt, mid);
  build(rot << 1 | 1, mid + 1, rt);
  update(rot);
}
void add(const int rot, const int lt, const int rt, const int ls, const int rs,
         const long long x) {
  if (ls <= lt && rt <= rs) return void(add(rot, x));
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (ls <= mid) add(rot << 1, lt, mid, ls, rs, x);
  if (rs > mid) add(rot << 1 | 1, mid + 1, rt, ls, rs, x);
  update(rot);
}
pair<long long, int> query(const int rot, const int lt, const int rt,
                           const int ls, const int rs) {
  if (ls <= lt && rt <= rs) return tree[rot].mx;
  int mid = (lt + rt) >> 1;
  pushdown(rot);
  if (rs <= mid)
    return query(rot << 1, lt, mid, ls, rs);
  else if (ls > mid)
    return query(rot << 1 | 1, mid + 1, rt, ls, rs);
  else
    return max(query(rot << 1, lt, mid, ls, rs),
               query(rot << 1 | 1, mid + 1, rt, ls, rs));
}
}  // namespace Segment_Tree
int work() {
  using namespace Segment_Tree;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &arr[i].first, &arr[i].second, &w[i]);
    if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
    tmp[++cnt] = arr[i].first, tmp[++cnt] = arr[i].second;
  }
  sort(tmp + 1, tmp + cnt + 1);
  cnt = unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
  for (int i = 1; i <= n; i++) {
    arr[i].first = lower_bound(tmp + 1, tmp + cnt + 1, arr[i].first) - tmp;
    arr[i].second = lower_bound(tmp + 1, tmp + cnt + 1, arr[i].second) - tmp;
    v[arr[i].first].push_back(i);
  }
  build(1, 1, cnt);
  long long ans = 0;
  int l = 2e9, r = 2e9;
  for (int i = cnt; i > 0; i--) {
    for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++)
      add(1, 1, cnt, arr[*it].second, cnt, w[*it]);
    pair<long long, int> now = query(1, 1, cnt, i, cnt);
    now.first += tmp[i];
    if (now.first > ans) ans = now.first, l = tmp[i], r = now.second;
  }
  printf("%lld\n%d %d %d %d", ans, l, l, r, r);
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }
