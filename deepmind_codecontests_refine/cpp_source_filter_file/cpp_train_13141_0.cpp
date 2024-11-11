#include <bits/stdc++.h>
using namespace std;
void read(int &val) {
  int x = 0;
  int bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 100;
const int mod = 998244353;
int m, t, a[maxn], b[maxn], p[maxn], n;
long long v[maxn], lz[maxn];
void bd(int root, int l, int r) {
  v[root] = 1LL << 60;
  if (l == r) {
    if (l == 0) v[root] = 0;
    return;
  }
  int mid = l + r >> 1;
  bd(root << 1, l, mid);
  bd(root << 1 | 1, mid + 1, r);
}
void pd(int root) {
  if (lz[root] == 0) return;
  v[root << 1] += lz[root];
  v[root << 1 | 1] += lz[root];
  lz[root << 1] += lz[root];
  lz[root << 1 | 1] += lz[root];
  lz[root] = 0;
}
void upd(int root, int l, int r, int L, int R, long long val) {
  if (L <= l && r <= R) {
    lz[root] += val;
    v[root] += val;
    return;
  }
  if (r < L || R < l) return;
  pd(root);
  int mid = l + r >> 1;
  upd(root << 1, l, mid, L, R, val);
  upd(root << 1 | 1, mid + 1, r, L, R, val);
}
long long qu(int root, int l, int r, int pos) {
  if (l == r) return v[root];
  pd(root);
  int mid = l + r >> 1;
  if (pos <= mid)
    return qu(root << 1, l, mid, pos);
  else
    return qu(root << 1 | 1, mid + 1, r, pos);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(p[i]);
  read(m);
  for (int i = 1; i <= m; i++) read(b[i]);
  bd(1, 0, m);
  b[m + 1] = 1LL << 30;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b;
    if (a[i] == b[pos]) {
      upd(1, 0, m, pos, m, min(0, p[i]));
      long long x = qu(1, 0, m, pos - 1), y = qu(1, 0, m, pos);
      if (x < (5e14 + 1)) upd(1, 0, m, pos, pos, min(0LL, x - y));
      upd(1, 0, m, 0, pos - 1, p[i]);
    } else {
      upd(1, 0, m, 0, pos - 1, p[i]);
      upd(1, 0, m, pos, m, min(0, p[i]));
    }
  }
  long long ans = qu(1, 0, m, m);
  if (ans > 5e14)
    puts("NO");
  else {
    puts("YES");
    printf("%lld\n", ans);
  }
  return 0;
}
