#include <bits/stdc++.h>
const int Nt = 1048576;
const long long inf = 1e18;
int ri() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
int n, m, tp, st[30];
long long p;
struct Node {
  std::vector<long long> f;
  long long sum;
  long long operator[](int x) const { return f[x]; }
  void Build(int a) {
    sum = a;
    f.push_back(-inf);
    f.push_back(p - a);
  }
  void F(long long &v) {
    v = v + sum - p * (std::upper_bound(f.begin(), f.end(), v) - f.begin() - 1);
  }
} T[Nt << 1];
void Merge(const Node &a, const Node &b, Node &c) {
  int j = 0, sza = a.f.size(), szb = b.f.size();
  if (!sza || !szb) return;
  c.sum = a.sum + b.sum;
  c.f.resize(sza + szb - 1, inf);
  for (int i = 0; i < sza; ++i) {
    long long xl = a[i], xr = i + 1 == sza ? inf : a[i + 1];
    long long yl = xl + a.sum - i * p, yr = xr + a.sum - i * p;
    if (j == szb) --j;
    for (; j && b[j] > yl;) --j;
    for (; j + 1 < szb && b[j + 1] <= yl;) ++j;
    for (; j < szb && b[j] <= yl; ++j)
      c.f[i + j] = std::min(c[i + j], std::max(xl, b[j] - a.sum + i * p));
  }
}
long long Query(int l, int r) {
  tp = 0;
  long long res = 0;
  for (l += Nt - 1, r += Nt + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) T[l ^ 1].F(res);
    if (r & 1) st[++tp] = r ^ 1;
  }
  for (int i = tp; i; --i) T[st[i]].F(res);
  return res;
}
int main() {
  n = ri();
  m = ri();
  p = ri();
  for (int i = 1; i <= n; ++i) T[i + Nt].Build(ri());
  for (int i = Nt - 1; i; --i) Merge(T[i << 1], T[i << 1 | 1], T[i]);
  for (; m--;) {
    int l = ri(), r = ri();
    printf("%lld\n", Query(l, r));
  }
  return 0;
}
