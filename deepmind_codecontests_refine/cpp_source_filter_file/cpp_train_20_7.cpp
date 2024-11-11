#include <bits/stdc++.h>
using namespace std;
int num[800005], m;
long long b[200005], sum[200005], cnt[200005], tr[800005];
struct node {
  int x, v;
  bool operator<(const node t) const { return x < t.x; }
} a[200005];
int lsh(long long x) { return lower_bound(b + 1, b + 1 + m, x) - b; }
void build(int l, int r, int p) {
  if (l == r) {
    tr[p] = sum[l];
    num[p] = cnt[l];
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, p << 1);
  build(mid + 1, r, p << 1 | 1);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
  num[p] = num[p << 1] + num[p << 1 | 1];
}
pair<long long, int> query(int l, int r, int x, int y, int p) {
  if (l == x && r == y) return make_pair(tr[p], num[p]);
  int mid = l + r >> 1;
  if (y <= mid)
    return query(l, mid, x, y, p << 1);
  else if (x > mid)
    return query(mid + 1, r, x, y, p << 1 | 1);
  else {
    pair<long long, int> v1 = query(l, mid, x, mid, p << 1),
                         v2 = query(mid + 1, r, mid + 1, y, p << 1 | 1);
    return make_pair(v1.first + v2.first, v1.second + v2.second);
  }
}
void update(int l, int r, int x, int y, int p) {
  if (l == r) {
    tr[p] -= y;
    num[p]--;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    update(l, mid, x, y, p << 1);
  else
    update(mid + 1, r, x, y, p << 1 | 1);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
  num[p] = num[p << 1] + num[p << 1 | 1];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].v);
    b[i] = a[i].v;
  }
  sort(b + 1, b + 1 + n);
  m = unique(b + 1, b + 1 + n) - b - 1;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int x = lsh(a[i].v);
    sum[x] += a[i].x;
    cnt[x]++;
  }
  build(1, m, 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = lsh(a[i].v);
    update(1, m, x, a[i].x, 1);
    pair<long long, int> t = query(1, m, x, m, 1);
    ans += t.first - (long long)a[i].x * t.second;
  }
  printf("%d", ans);
  return 0;
}
