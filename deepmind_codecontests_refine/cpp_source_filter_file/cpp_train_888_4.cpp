#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct mat {
  long long m[3][3];
} unite, zero;
mat operator*(mat a, mat b) {
  mat ans;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      long long x = 0;
      for (int k = 1; k <= 2; k++) x += (a.m[i][k] * b.m[k][j]) % mod;
      ans.m[i][j] = x % mod;
    }
  }
  return ans;
}
mat operator+(mat a, mat b) {
  mat ans;
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) ans.m[i][j] = (a.m[i][j] + b.m[i][j]) % mod;
  return ans;
}
mat mod_pow(mat a, long long n) {
  mat ans = unite;
  while (n) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n >>= 1;
  }
  return ans;
}
const int maxn = 1e5 + 10;
mat sum[maxn * 4], a, lazy[maxn * 4];
long long v[maxn];
void init() {
  a.m[1][1] = a.m[1][2] = a.m[2][1] = 1, a.m[2][2] = 0;
  for (int i = 0; i < 3; i++) unite.m[i][i] = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) zero.m[i][j] = 0;
}
void push_up(int id) { sum[id] = sum[id << 1] + sum[id << 1 | 1]; }
void build(int id, int l, int r) {
  lazy[id] = unite;
  if (l == r) {
    sum[id] = mod_pow(a, v[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  push_up(id);
}
bool same(mat a, mat b) {
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      if (a.m[i][j] != b.m[i][j]) return false;
    }
  }
  return true;
}
void push_down(int id) {
  if (same(lazy[id], unite)) return;
  sum[id << 1] = sum[id << 1] * lazy[id];
  sum[id << 1 | 1] = sum[id << 1 | 1] * lazy[id];
  lazy[id << 1] = lazy[id << 1] + lazy[id];
  lazy[id << 1 | 1] = lazy[id << 1 | 1] + lazy[id];
  lazy[id] = unite;
}
void update(int id, int l, int r, int x, int y, mat val) {
  if (x <= l && y >= r) {
    lazy[id] = lazy[id] + val;
    sum[id] = sum[id] * val;
    return;
  }
  push_down(id);
  int mid = (l + r) >> 1;
  if (x <= mid) update(id << 1, l, mid, x, y, val);
  if (y > mid) update(id << 1 | 1, mid + 1, r, x, y, val);
  push_up(id);
}
mat query(int id, int l, int r, int x, int y) {
  if (x <= l && y >= r) return sum[id];
  mat ans = zero;
  int mid = (l + r) >> 1;
  push_down(id);
  if (x <= mid) ans = ans + query(id << 1, l, mid, x, y);
  if (y > mid) ans = ans + query(id << 1 | 1, mid + 1, r, x, y);
  return ans;
}
int main() {
  init();
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
  build(1, 1, n);
  while (m--) {
    int opt;
    long long l, r, x;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%lld%lld%lld", &l, &r, &x);
      mat val = mod_pow(a, x);
      update(1, 1, n, l, r, val);
    } else {
      scanf("%lld%lld", &l, &r);
      mat ans = query(1, 1, n, l, r);
      printf("%lld\n", ans.m[1][2]);
    }
  }
  return 0;
}
