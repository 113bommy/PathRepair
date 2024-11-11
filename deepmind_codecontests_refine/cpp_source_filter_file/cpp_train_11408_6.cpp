#include <bits/stdc++.h>
using namespace std;
inline bool is_digit(int c) { return c >= '0' && c <= '9'; }
template <typename T>
inline void read(T &a) {
  int c = getchar();
  bool sgn = false;
  while (!is_digit(c)) sgn ^= (c == '-'), c = getchar();
  a = c - '0';
  while (is_digit(c = getchar())) a = a * 10 + c - '0';
  if (sgn) a = -a;
}
const int N = 100000 + 5, M = 300000 + 5;
int n;
int an[N], ls[N];
int m;
int lm[M], rm[M], ansm[M], od[M];
inline bool cmp_m_r(int a, int b) { return rm[a] < rm[b]; }
int bit[N];
inline void bch0(int p, int v) {
  for (; p <= n; p += p & -p) bit[p] = min(bit[p], v);
}
inline int bqry0(int p) {
  int ret = 0x3f3f3f3f;
  for (; p; p &= p - 1) ret = min(ret, bit[p]);
  return ret;
}
inline void bch(int p, int v) { return bch0(n - p + 1, v); }
inline int bqry(int p) { return bqry0(n - p + 1); }
const int SEG = N * 4;
int mx[SEG];
inline void spu(int idx) { mx[idx] = max(mx[idx << 1], mx[idx << 1 | 1]); }
void sch(int idx, int l, int r, int p, int v) {
  if (l == r) return mx[idx] = max(mx[idx], v), void();
  int mid = (l + r) >> 1;
  if (p <= mid)
    sch(idx << 1, l, mid, p, v);
  else
    sch(idx << 1 | 1, mid + 1, r, p, v);
  spu(idx);
}
int sqry(int idx, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mx[idx];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return sqry(idx << 1, l, mid, L, R);
  else if (L > mid)
    return sqry(idx << 1 | 1, mid + 1, r, L, R);
  else
    return max(sqry(idx << 1, l, mid, L, R),
               sqry(idx << 1 | 1, mid + 1, r, L, R));
}
inline int find_pre(int i, int a) {
  int l = int(lower_bound(ls + 1, ls + n + 1, ls[an[i]] - a) - ls),
      r = int(upper_bound(ls + 1, ls + n + 1, ls[an[i]] + a) - ls) - 1;
  if (l > r)
    return 0;
  else
    return sqry(1, 1, n, l, r);
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(an[i]);
  read(m);
  for (int i = 1; i <= m; ++i) read(lm[i]), read(rm[i]);
  for (int i = 1; i <= n; ++i) ls[i] = an[i];
  sort(ls + 1, ls + n + 1);
  for (int i = 1; i <= n; ++i)
    an[i] = int(lower_bound(ls + 1, ls + n + 1, an[i]) - ls);
  for (int i = 1; i <= m; ++i) od[i] = i;
  sort(od + 1, od + m + 1, cmp_m_r);
  memset(bit, 0x3f, sizeof(bit));
  for (int i = 1, jit = 1; i <= n && jit <= m; ++i) {
    int ta = 0x3f3f3f3f, k = 0;
    while ((k = find_pre(i, ta - 1))) {
      ta = abs(ls[an[i]] - ls[an[k]]);
      bch(k, ta);
    }
    sch(1, 1, n, an[i], i);
    while (jit <= n && rm[od[jit]] == i) {
      ansm[od[jit]] = bqry(lm[od[jit]]);
      ++jit;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ansm[i]);
  return 0;
}
