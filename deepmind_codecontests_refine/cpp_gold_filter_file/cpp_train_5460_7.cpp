#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2, mod = 1e9 + 9;
struct ND {
  long long a, b, x;
} s[N << 2];
int n, m;
long long f[3][N];
void pushup(int num) {
  s[num].x = (s[(num << 1)].x + s[(num << 1 | 1)].x) % mod;
}
void build(int num, int l, int r) {
  if (l == r) {
    scanf("%lld", &s[num].x);
    return;
  }
  build((num << 1), l, ((l + r) >> 1)),
      build((num << 1 | 1), ((l + r) >> 1) + 1, r), pushup(num);
}
void pushdown(int num, int l, int r) {
  if (!s[num].a && !s[num].b) return;
  s[(num << 1)].a = (s[(num << 1)].a + s[num].a) % mod,
            s[(num << 1)].b = (s[(num << 1)].b + s[num].b) % mod;
  s[(num << 1 | 1)].a = (s[(num << 1 | 1)].a + s[num].a) % mod,
                s[(num << 1 | 1)].b = (s[(num << 1 | 1)].b + s[num].b) % mod;
  s[(num << 1)].x =
      (s[(num << 1)].x +
       (f[2][((l + r) >> 1)] - f[2][l - 1] + mod) * s[num].a % mod +
       (f[2][((l + r) >> 1) + 1] - f[2][l] + mod) * s[num].b % mod) %
      mod;
  s[(num << 1 | 1)].x =
      (s[(num << 1 | 1)].x +
       (f[2][r] - f[2][((l + r) >> 1)] + mod) * s[num].a % mod +
       (f[2][r + 1] - f[2][((l + r) >> 1) + 1] + mod) * s[num].b % mod) %
      mod;
  s[num].a = s[num].b = 0;
}
void update(int num, int l, int r, int ql, int qr, long long qa, long long qb) {
  if (l == ql && r == qr) {
    s[num].a = (s[num].a + qa) % mod, s[num].b = (s[num].b + qb) % mod;
    s[num].x = (s[num].x + (f[2][r] - f[2][l - 1] + mod) * qa % mod +
                (f[2][r + 1] - f[2][l] + mod) * qb % mod) %
               mod;
    return;
  }
  pushdown(num, l, r);
  if (ql <= ((l + r) >> 1))
    update((num << 1), l, ((l + r) >> 1), ql, min(qr, ((l + r) >> 1)), qa, qb);
  if (((l + r) >> 1) < qr)
    update((num << 1 | 1), ((l + r) >> 1) + 1, r, max(ql, ((l + r) >> 1) + 1),
           qr, qa, qb);
  pushup(num);
}
long long query(int num, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return s[num].x % mod;
  pushdown(num, l, r);
  long long ret = 0;
  if (ql <= ((l + r) >> 1))
    ret =
        query((num << 1), l, ((l + r) >> 1), ql, min(qr, ((l + r) >> 1))) % mod;
  if (((l + r) >> 1) < qr)
    ret = (ret + query((num << 1 | 1), ((l + r) >> 1) + 1, r,
                       max(ql, ((l + r) >> 1) + 1), qr)) %
          mod;
  return ret % mod;
}
int main() {
  scanf("%d%d", &n, &m), f[0][0] = f[1][0] = f[2][0] = 0,
                         f[0][1] = f[1][1] = f[2][1] = 1;
  for (int i = 2; i <= n + 1; i++)
    f[0][i] = (f[0][i - 1] + f[0][i - 2]) % mod,
    f[1][i] = (i & 1) ? f[0][i] : mod - f[0][i],
    f[2][i] = (f[2][i - 1] + f[0][i]) % mod;
  build(1, 1, n);
  for (int op, l, r; m--;) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1)
      update(1, 1, n, l, r, f[1][l], f[1][l - 1]);
    else
      printf("%lld\n", query(1, 1, n, l, r) % mod);
  }
  return 0;
}
