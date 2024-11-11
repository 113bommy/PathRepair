#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long sum = 0, fh = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 3) + (sum << 1) + (ch ^ 48);
    ch = getchar();
  }
  return sum * fh;
}
long long a[400010];
long long P[400];
long long tot = 0;
bool e[400];
long long inv[400];
long long qpow(long long x, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * x % 1000000007;
    x = x * x % 1000000007;
    b >>= 1;
  }
  return ans;
}
void sieve(long long n) {
  e[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    if (!e[i]) {
      P[++tot] = i;
    }
    for (long long j = 1; j <= tot; ++j) {
      if (P[j] * i > n) break;
      e[P[j] * i] = 1;
      if (i % P[j] == 0) break;
    }
  }
  for (long long i = 1; i <= tot; ++i) {
    inv[i] = (P[i] - 1) * qpow(P[i], 1000000007 - 2) % 1000000007;
  }
}
long long BIT(long long x) {
  long long ans = 0;
  for (long long i = 1; i <= tot; ++i) {
    if (!(x % P[i])) {
      ans += (1ll << (i - 1));
    }
  }
  return ans;
}
char ch[10];
long long tag[400010 * 4];
long long Or[400010 * 4];
long long mul[400010 * 4];
long long tagmul[400010 * 4];
void upd(long long p) {
  mul[p] = mul[p << 1] * mul[p << 1 | 1] % 1000000007;
  Or[p] = Or[p << 1] | Or[p << 1 | 1];
}
void pd(long long p, long long l, long long r) {
  long long mid = l + r >> 1;
  tag[p << 1] |= tag[p];
  tag[p << 1 | 1] |= tag[p];
  Or[p << 1] |= tag[p];
  Or[p << 1 | 1] |= tag[p];
  tagmul[p << 1] = tagmul[p << 1] * tagmul[p] % 1000000007;
  tagmul[p << 1 | 1] = tagmul[p << 1 | 1] * tagmul[p] % 1000000007;
  mul[p << 1] = mul[p << 1] * qpow(tagmul[p], mid - l + 1) % 1000000007;
  mul[p << 1 | 1] = mul[p << 1 | 1] * qpow(tagmul[p], r - mid) % 1000000007;
  tag[p] = 0;
  tagmul[p] = 1;
  return;
}
void ins(long long p, long long l, long long r, long long x, long long v,
         long long M) {
  tagmul[p] = 1;
  if (l == r) {
    Or[p] = v;
    mul[p] = M;
    return;
  }
  long long mid = l + r >> 1;
  if (x <= mid)
    ins(p << 1, l, mid, x, v, M);
  else
    ins(p << 1 | 1, mid + 1, r, x, v, M);
  upd(p);
}
void modify(long long p, long long l, long long r, long long L, long long R,
            long long v, long long M) {
  if (L <= l && R >= r) {
    mul[p] = mul[p] * qpow(M, r - l + 1) % 1000000007;
    tagmul[p] = tagmul[p] * M % 1000000007;
    Or[p] |= v;
    tag[p] |= v;
    return;
  }
  if (tag[p] || tagmul[p] != 1) pd(p, l, r);
  long long mid = l + r >> 1;
  if (L <= mid) modify(p << 1, l, mid, L, R, v, M);
  if (R > mid) modify(p << 1 | 1, mid + 1, r, L, R, v, M);
  upd(p);
}
long long query(long long p, long long l, long long r, long long L, long long R,
                long long &M) {
  if (L <= l && R >= r) {
    M = mul[p];
    return Or[p];
  }
  if (tag[p] || tagmul[p] != 1) pd(p, l, r);
  long long mid = l + r >> 1;
  long long m1 = 1, m2 = 1;
  long long ans = 0;
  if (L <= mid) ans |= query(p << 1, l, mid, L, R, m1);
  if (R > mid) ans |= query(p << 1 | 1, mid + 1, r, L, R, m2);
  upd(p);
  M = m1 * m2 % 1000000007;
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n = read(), Q = read();
  sieve(300);
  for (long long i = 1; i <= n; ++i) {
    a[i] = read();
    ins(1, 1, n, i, BIT(a[i]), a[i]);
  }
  while (Q--) {
    scanf("%s", ch);
    if (ch[0] == 'M') {
      long long l = read(), r = read(), x = read();
      modify(1, 1, n, l, r, BIT(x), x);
    }
    if (ch[0] == 'T') {
      long long l = read(), r = read();
      long long MUL = 1;
      long long x = query(1, 1, n, l, r, MUL);
      for (long long i = 1; i <= tot; ++i) {
        if ((1ll << (i - 1)) & x) {
          MUL = MUL * inv[i] % 1000000007;
        }
      }
      printf("%lld\n", MUL);
    }
  }
  return 0;
}
