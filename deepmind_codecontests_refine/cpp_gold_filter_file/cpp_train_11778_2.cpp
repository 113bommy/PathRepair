#include <bits/stdc++.h>
static int k = 1;
static inline int inv(int x) { return ((1 << k) - 1) ^ x; }
static int t[1 << 5][(1 << 18) << 1];
static inline int max(int a, int b) { return a > b ? a : b; }
static inline void init() {
  for (int i = 0; i < (1 << 5); ++i)
    for (int j = 0; j < ((1 << 18) << 1); ++j) t[i][j] = -10000000;
}
static inline void set(int pos, int val[]) {
  for (int sum, mask = 0; mask < (1 << k); ++mask) {
    sum = 0;
    for (int j = 0; j < k; ++j)
      if (mask & (1 << j))
        sum += val[j];
      else
        sum -= val[j];
    t[mask][(1 << 18) + pos] = sum;
  }
  for (int mask = 0; mask < (1 << k); ++mask)
    for (int i = (pos + (1 << 18)) / 2; i; i >>= 1)
      t[mask][i] = max(t[mask][i << 1], t[mask][i << 1 | 1]);
}
static inline int get(int l, int r) {
  static int res[1 << 5], best;
  for (int mask = 0; mask < (1 << k); ++mask) {
    res[mask] = -10000000;
    for (int L = l + (1 << 18), R = r + (1 << 18); L <= R; L >>= 1, R >>= 1) {
      if (L % 2 == 1) res[mask] = max(res[mask], t[mask][L++]);
      if (R % 2 == 0) res[mask] = max(res[mask], t[mask][R--]);
    }
  }
  best = -10000000;
  for (int mask = 0; mask < (1 << k); ++mask)
    best = max(best, res[mask] + res[inv(mask)]);
  return best;
}
int main() {
  int n;
  scanf("%i%i", &n, &k);
  init();
  for (int i = 0; i < n; ++i) {
    static int X[5];
    for (int j = 0; j < k; ++j) scanf("%i", X + j);
    set(i, X);
  }
  int q;
  scanf("%i", &q);
  while (q--) {
    static int t;
    scanf("%i", &t);
    if (t == 1) {
      static int i;
      scanf("%i", &i);
      static int X[5];
      for (int j = 0; j < k; ++j) scanf("%i", X + j);
      set(--i, X);
    } else {
      static int l, r;
      scanf("%i%i", &l, &r);
      printf("%i\n", get(--l, --r));
    }
  }
}
