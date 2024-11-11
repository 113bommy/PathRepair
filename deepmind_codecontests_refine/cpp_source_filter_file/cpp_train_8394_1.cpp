#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int n, m, l[1000005], r[1000005], tot, num[1000005];
bool lb[1000005], rb[1000005], lazy[1000005];
set<int> s;
vector<int> v;
struct node {
  bool lb, rb;
  int num;
};
void merge(int k) {
  lb[k] = lb[k * 2];
  rb[k] = rb[k * 2 + 1];
  num[k] = num[k * 2] + num[k * 2 + 1];
  if (rb[k * 2] && lb[k * 2 + 1]) num[k]--;
}
void Lazy(int k) {
  lb[k * 2] = rb[k * 2] = lb[k * 2 + 1] = rb[k * 2 + 1] = true;
  num[k * 2] = num[k * 2 + 1] = 1;
  lazy[k * 2] = lazy[k * 2 + 1] = true;
  lazy[k] = false;
}
void build(int k, int l, int r) {
  if (l == r) {
    lb[k] = rb[k] = false;
    num[k] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
}
void update(int k, int l, int r, int x, int y) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    lazy[k] = lb[k] = rb[k] = true;
    num[k] = 1;
    return;
  }
  if (lazy[k]) Lazy(k);
  int mid = (l + r) / 2;
  update(k * 2, l, mid, x, y);
  update(k * 2 + 1, mid + 1, r, x, y);
  merge(k);
}
node query(int k, int l, int r, int x, int y) {
  if (l > y || r < x) return (node){false, false, 0};
  if (l >= x && r <= y) return (node){lb[k], rb[k], num[k]};
  int mid = (l + r) / 2;
  node lans = query(k * 2, l, mid, x, y);
  node rans = query(k * 2 + 1, mid + 1, r, x, y);
  node ret;
  ret.lb = lans.lb;
  ret.rb = rans.rb;
  ret.num = lans.num + rans.num;
  if (lans.rb && rans.lb) ret.num--;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    r[i]--;
    s.insert(l[i]);
    s.insert(r[i]);
    s.insert(r[i] + 1);
  }
  vector<int> v(s.begin(), s.end());
  int sz = (int)v.size();
  build(1, 1, sz);
  for (int i = 0; i < n; i++) {
    int p = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
    int q = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
    update(1, 1, sz, p, q);
    printf("%d\n", query(1, 1, sz, 1, sz).num);
  }
  return 0;
}
