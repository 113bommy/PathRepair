#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
  int l, r, sum;
  pair<int, int> g;
} tr[N << 2];
int n, a[N], b[N];
void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
  if (tr[u << 1].g.second == tr[u << 1 | 1].g.second) {
    if (tr[u << 1].g.first < tr[u << 1 | 1].g.first)
      tr[u].g = tr[u << 1].g;
    else
      tr[u].g = tr[u << 1 | 1].g;
    return;
  }
  if (tr[u << 1].g.second < tr[u << 1 | 1].g.second)
    tr[u].g = tr[u << 1].g;
  else
    tr[u].g = tr[u << 1 | 1].g;
}
void build(int u, int l, int r) {
  tr[u].l = l, tr[u].r = r;
  if (l == r) {
    tr[u].sum = 1;
    tr[u].g = {l, a[l]};
    return;
  }
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
pair<int, int> query(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) {
    return tr[u].g;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  pair<int, int> a = {-1, N + 5}, b = {-1, N + 5};
  if (l <= mid) a = query(u << 1, l, r);
  if (r > mid) b = query(u << 1 | 1, l, r);
  if (a.second <= b.second) return a;
  return b;
}
int get_sum(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) {
    return tr[u].sum;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  int res = 0;
  if (l <= mid) res += get_sum(u << 1, l, r);
  if (r > mid) res += get_sum(u << 1 | 1, l, r);
  return res;
}
void modify(int u, int x) {
  if (tr[u].l == tr[u].r && tr[u].l == x) {
    tr[u].sum = 0;
    tr[u].g = {x, N + 5};
    return;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  if (x <= mid)
    modify(u << 1, x);
  else
    modify(u << 1 | 1, x);
  pushup(u);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  build(1, 1, n);
  long long now = 1, res = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> x = query(1, now, n);
    if (x.second == b[i]) {
      res += get_sum(1, now, x.first);
      now = x.first + 1;
      if (now > n) now = 1;
      modify(1, x.first);
    } else {
      x = query(1, 1, now);
      if (x.second == b[i]) {
        res += get_sum(1, now, n);
        res += get_sum(1, 1, x.first);
        now = x.first + 1;
        if (now > n) now = 1;
        modify(1, x.first);
      }
    }
  }
  cout << res << endl;
  return 0;
}
