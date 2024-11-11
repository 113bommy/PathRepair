#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const int maxn = 4e7;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long n, m, k, d;
long long ar[N];
long long ans;
long long c[N];
void build(int l, int r, int x) {
  if (l == r) {
    c[x] = read() % k;
    return;
  }
  int md = l + r >> 1;
  build(l, md, x << 1);
  build(md + 1, r, x << 1 | 1);
  c[x] = c[x << 1] * c[x << 1 | 1] % k;
}
long long query(int l, int r, int x, int ql, int qr) {
  if (ql <= l && r <= qr) return c[x];
  int md = l + r >> 1;
  long long res = 1;
  if (ql <= md) res *= (query(l, md, x << 1, ql, qr)) % k;
  res %= k;
  if (qr > md) res *= query(md + 1, r, x << 1 | 1, ql, qr) % k;
  res %= k;
  return res;
}
void solvve() {
  n = read();
  k = read();
  build(1, n, 1);
  int pl = 1, pr = 1;
  for (pr = 1; pr <= n; ++pr) {
    while (pl < pr && query(1, n, 1, pl + 1, pr) == 0) pl++;
    if (query(1, n, 1, pl, pr) == 0) ans += pl;
  }
  cout << ans << endl;
}
int main() {
  { solvve(); }
  return 0;
}
