#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int n, a[500005];
int dat[1048576];
int gcd(int u, int v) { return v == 0 ? u : gcd(v, u % v); }
void build_t() {
  for (int i = 0; i < (int)(n); i++) dat[i + 524288] = a[i];
  for (int i = 524287; i >= 0; i--) dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);
}
void modify_t(int id, int v, int cv = 1, int cl = 0, int cr = 524287) {
  if (cl == cr) {
    dat[cv] = v;
    return;
  }
  int mid = (cl + cr) >> 1;
  if (id <= mid)
    modify_t(id, v, cv << 1, cl, mid);
  else
    modify_t(id, v, cv << 1 | 1, mid + 1, cr);
  dat[cv] = gcd(dat[cv << 1], dat[cv << 1 | 1]);
}
bool query_t(int l, int r, int x, bool& fd, int cv = 1, int cl = 0,
             int cr = 524287) {
  if (dat[cv] % x == 0)
    return true;
  else if (l == cl && r == cr && fd)
    return false;
  else if (cl == cr) {
    fd = true;
    return true;
  }
  int mid = (cl + cr) >> 1;
  if (r <= mid) return query_t(l, r, x, fd, cv << 1, cl, mid);
  if (l > mid) return query_t(l, r, x, fd, cv << 1 | 1, mid + 1, cr);
  bool ret = query_t(l, mid, x, fd, cv << 1, l, mid);
  ret &= query_t(mid + 1, r, x, fd, cv << 1 | 1, mid + 1, r);
  return ret;
}
bool query_t(int l, int r, int x) {
  bool fd = false;
  return query_t(l, r, x, fd);
}
int main() {
  int q, l, r, x;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  build_t();
  scanf("%d", &q);
  for (int i = 0; i < (int)(q); i++) {
    scanf("%d", &l);
    if (l == 1) {
      scanf("%d%d%d", &l, &r, &x);
      printf(query_t(l - 1, r - 1, x) ? "YES\n" : "NO\n");
    } else {
      scanf("%d%d", &l, &x);
      modify_t(l - 1, x);
    }
  }
  return 0;
}
