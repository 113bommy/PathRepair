#include <bits/stdc++.h>
const int N = 1e6 + 5;
long long mx[N << 2], ad[N << 2];
void addNode(int k, long long v) {
  ad[k] += v;
  mx[k] += v;
}
void pull(int k) { mx[k] = std::max(mx[k << 1], mx[k << 1 | 1]); }
void push(int k) {
  if (!ad[k]) return;
  addNode(k << 1, ad[k]);
  addNode(k << 1 | 1, ad[k]);
  ad[k] = 0;
}
void build(int k, int lef, int rig) {
  mx[k] = rig;
  if (lef == rig) return;
  int mid = (lef + rig) >> 1;
  build(k << 1, lef, mid);
  build(k << 1 | 1, mid + 1, rig);
}
void update(int k, int lef, int rig, int l, int r, long long v) {
  if (l <= lef && rig <= r) {
    addNode(k, v);
    return;
  }
  int mid = (lef + rig) >> 1;
  push(k);
  if (l <= mid) update(k << 1, lef, mid, l, r, v);
  if (r > mid) update(k << 1 | 1, mid + 1, rig, l, r, v);
  pull(k);
}
long long query(int k, int lef, int rig, int l, int r) {
  if (l <= lef && rig <= r) return mx[k];
  int mid = (lef + rig) >> 1;
  push(k);
  long long ans = 0;
  if (l <= mid) ans = std::max(ans, query(k << 1, lef, mid, l, r));
  if (r > mid) ans = std::max(ans, query(k << 1 | 1, mid + 1, rig, l, r));
  return ans;
}
std::pair<int, int> c[N];
int tail, q;
int main() {
  scanf("%d", &q);
  char s[2];
  int l, r;
  int n = 1e6 + 1;
  build(1, 1, n);
  while (q--) {
    scanf("%s%d", s, &l);
    if (s[0] == '+') {
      scanf("%d", &r);
      update(1, 1, n, 1, l, r);
      c[++tail] = std::pair<int, int>(l, r);
    } else if (s[0] == '-') {
      update(1, 1, n, 1, c[l].first, -c[l].second);
      ++tail;
    } else
      printf("%lld\n", query(1, 1, n, 1, l) - query(1, 1, n, l + 1, l + 1) + 1),
          ++tail;
  }
  return 0;
}
