#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 401000;
int n;
long long c, v[N], s[N];
long long nd[4 * N];
void upd(int p) { nd[p] = max(nd[p + p], nd[p + p + 1]); }
long long query(int p, int l, int r, int tl, int tr) {
  if (tl == l && tr == r)
    return nd[p];
  else {
    int md = (l + r) >> 1;
    if (tr <= md)
      return query(p + p, l, md, tl, tr);
    else if (tl > md)
      return query(p + p + 1, md + 1, r, tl, tr);
    else
      return max(query(p + p, l, md, tl, md),
                 query(p + p + 1, md + 1, r, md + 1, tr));
  }
}
void modify(int p, int l, int r, int x, long long v) {
  if (l == r)
    nd[p] = v;
  else {
    int md = (l + r) >> 1;
    if (x <= md)
      modify(p + p, l, md, x, v);
    else
      modify(p + p + 1, md + 1, r, x, v);
    upd(p);
  }
}
int main() {
  scanf("%d%lld", &n, &c);
  for (int i = 1; i < 2 * n; i++) scanf("%lld", v + i), v[i] += v[i - 1];
  int r = 0;
  for (int i = 1; i < n + 1; i++) {
    while (r < i && v[2 * i - 1] - v[2 * r] > c) ++r;
    if (r > 0) s[i] = s[r - 1] + c;
    if (r <= i - 1) s[i] = max(s[i], v[2 * i - 1] + query(1, 0, n, r, i - 1));
    modify(1, 0, n, i, s[i] - v[2 * i]);
  }
  printf("%lld\n", s[n]);
}
