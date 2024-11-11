#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long sg[400005], la[400005];
long long k[100005];
int n;
void pushup(int o) { sg[o] = sg[o << 1] + sg[o << 1 | 1]; }
void build(int o, int l, int r) {
  la[o] = LLONG_MAX;
  if (l == r) {
    sg[o] = a[l] - k[l];
    return;
  }
  int mid = (r - l) / 2 + l;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  pushup(o);
}
void update(int o, int l, int r, long long v) {
  sg[o] = v * (r - l + 1);
  la[o] = v;
}
void pushdown(int o, int l, int r) {
  if (la[o] != LLONG_MAX) {
    int mid = (r - l) / 2 + l;
    update(o << 1, l, mid, la[o]);
    update(o << 1 | 1, mid + 1, r, la[o]);
    la[o] = LLONG_MAX;
  }
}
void change(int o, int l, int r, int L, int R, long long v) {
  if (L <= l && r <= R) {
    update(o, l, r, v);
    return;
  }
  pushdown(o, l, r);
  int mid = (r - l) / 2 + l;
  if (L <= mid) change(o << 1, l, mid, L, R, v);
  if (R > mid) change(o << 1 | 1, mid + 1, r, L, R, v);
  pushup(o);
}
long long query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return sg[o];
  pushdown(o, l, r);
  int mid = (r - l) / 2 + l;
  long long ans = 0;
  if (L <= mid) ans += query(o << 1, l, mid, L, R);
  if (R > mid) ans += query(o << 1 | 1, mid + 1, r, L, R);
  return ans;
}
int binary(int l, int r, long long v) {
  if (l == r) return l;
  int mid = (r - l) / 2 + l;
  if (v <= query(1, 1, n, mid, mid)) return binary(l, mid, v);
  return binary(mid + 1, r, v);
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  k[1] = 0;
  for (int i = 2; i <= n; i++) {
    scanf("%lld", &k[i]);
    k[i] += k[i - 1];
  }
  build(1, 1, n);
  for (int i = 2; i <= n; i++) k[i] += k[i - 1];
  int q;
  scanf("%d", &q);
  while (q--) {
    char s[5];
    int l, r;
    scanf("%s%d%d", s, &l, &r);
    if (s[0] == 's')
      printf("%lld\n", query(1, 1, n, l, r) + k[r] - k[l - 1]);
    else {
      long long t = query(1, 1, n, l, l) + r;
      int o = binary(l, n, t);
      if (t <= query(1, 1, n, o, o)) o = max(l, o - 1);
      change(1, 1, n, l, o, t);
    }
  }
}
int main() {
  solve();
  return 0;
}
