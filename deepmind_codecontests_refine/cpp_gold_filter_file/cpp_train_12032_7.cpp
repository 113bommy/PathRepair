#include <bits/stdc++.h>
const long long P = 1000000000039LL;
inline long long mul(long long a, long long b) {
  long long ans = 0;
  for (; b; b >>= 1) {
    if (b & 1) {
      ans = (ans + a) % P;
    }
    a = (a << 1) % P;
  }
  return ans;
}
int k = 0, t = 0;
long long fac[10], ifac[10];
void init() {
  fac[0] = 1;
  ifac[0] = 1;
  fac[1] = 1;
  ifac[1] = 1;
  for (int i = 2; i < 10; i++) {
    ifac[i] = (P - mul(P / i, ifac[P % i])) % P;
  }
  for (int i = 2; i < 10; i++) {
    ifac[i] = mul(ifac[i - 1], ifac[i]);
    fac[i] = mul(fac[i - 1], i);
  }
}
int cnt[16];
long long f[10], g[10];
long long c[10];
void calc(int len) {
  std::fill(f, f + len + 1, 0);
  for (int i = 0; i < 16; i++) {
    if (cnt[i] < 0) {
      return;
    }
  }
  f[0] = 1;
  for (int i = 0; i < 16; i++) {
    std::fill(g, g + len + 1, 0);
    for (int j = 0; j <= cnt[i]; j++) {
      for (int u = 0; u <= len - j; u++) {
        g[u + j] = (g[u + j] + mul(ifac[j], f[u])) % P;
      }
    }
    std::copy(g, g + len + 1, f);
  }
}
void preDP() {
  std::fill(cnt, cnt + 16, t);
  c[0] = 0;
  cnt[1]--;
  calc(9);
  for (int i = 1; i < 10; i++) {
    c[i] = c[i - 1] + 15 * mul(f[i - 1], fac[i - 1]);
  }
}
long long solve(long long x) {
  long long l = 0, ans = 0;
  int d[10];
  std::fill(cnt, cnt + 16, t);
  for (; x; d[l++] = x % 16, x /= 16)
    ;
  if (l > 0) {
    ans += c[l - 1];
  }
  for (int i = l - 1; i >= 0; i--) {
    for (int u = ((i == l - 1) ? 1 : 0); u < d[i]; u++) {
      cnt[u]--;
      calc(i);
      ans += mul(f[i], fac[i]);
      cnt[u]++;
    }
    cnt[d[i]]--;
  }
  for (int i = 0; i < 16; i++) {
    if (cnt[i] < 0) {
      return ans;
    }
  }
  return ans + 1;
}
int main() {
  scanf("%d%d", &k, &t);
  if (t >= 8) {
    printf("%x\n", k);
  } else {
    init();
    preDP();
    long long l = 0, r = 0xFFFFFFFFFLL;
    for (long long mid = 0; l + 1 < r;
         solve(mid = (l + r) >> 1) >= k ? r = mid : l = mid)
      ;
    printf("%I64x\n", r);
  }
  return 0;
}
