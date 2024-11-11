#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
struct tt {
  int v, i;
  bool operator<(const tt &o) const { return v < o.v; }
} lx[100005];
int g = 0, n = 0, two[N] = {0}, w[N] = {0}, r[N] = {0};
int pow_mod(int x, int y) {
  if (y == 0) {
    return 1;
  }
  int now = pow_mod(x, y / 2);
  now = now * 1LL * now % mod;
  if (y & 1) {
    now = now * 1LL * x % mod;
  }
  return now;
}
void init() {
  int i = 0;
  two[0] = 1;
  for (i = 1; i < N; i++) {
    two[i] = (two[i - 1] + two[i - 1]) % mod;
  }
  w[0] = 1;
  for (i = 1; i < N; i++) {
    w[i] = w[i - 1] * 1LL * i % mod;
  }
  r[0] = 1;
  for (i = 1; i < N; i++) {
    r[i] = r[i - 1] * 1LL * pow_mod(i, mod - 2);
  }
}
int com(int xy, int x) {
  int ans = w[xy];
  ans = (ans * 1LL * r[x]) % mod;
  ans = (ans * 1LL * r[xy - x]) % mod;
  return ans;
}
int tt(int p, int q, int id) {
  if (id == g) {
    if (n == q - p + 1) {
      return 1;
    }
    return com(n - (q - p + 1), p - 1);
  }
  if (p <= lx[id].i && lx[id].i <= q) {
    return 0;
  }
  int now = lx[id].v - lx[id - 1].v - 1;
  int ans = 0;
  if (lx[id].i < p) {
    if (p - lx[id].i - 1 > now) {
      return 0;
    }
    if (lx[id].i + now + (q - p + 1) > n) {
      return 0;
    }
    ans = tt(lx[id].i, lx[id].i + now + (q - p + 1), id + 1);
    ans = ans * 1LL * com(now, p - lx[id].i - 1) % mod;
  } else {
    if (lx[id].i - q - 1 > now) {
      return 0;
    }
    if (lx[id].i - now - (q - p + 1) < 1) {
      return 0;
    }
    ans = tt(lx[id].i - now - (q - p + 1), lx[id].i, id + 1);
    ans = ans * 1LL * com(now, lx[id].i - q - 1) % mod;
  }
  return ans;
}
int main() {
  int i = 0, ans = 0, now = 0;
  init();
  while (scanf("%d", &n) == 1) {
    g = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &lx[g].v);
      if (lx[g].v) {
        lx[g].i = i;
        g++;
      }
    }
    if (g == 0) {
      printf("%d\n", two[n - 1]);
      continue;
    }
    sort(lx, lx + g);
    ans = 0;
    if (lx[0].i - lx[0].v + 1 >= 1) {
      now = tt(lx[0].i - lx[0].v + 1, lx[0].i, 1);
      if (lx[0].v - 2 >= 0) {
        now = now * 1LL * two[lx[0].v - 2] % mod;
      }
      ans += now;
      ans %= mod;
    }
    if (lx[0].v > 1 && lx[0].i + lx[0].v - 1 <= n) {
      now = tt(lx[0].i, lx[0].i + lx[0].v - 1, 1);
      if (lx[0].v - 2 >= 0) {
        now = now * 1LL * two[lx[0].v - 2] % mod;
      }
      ans += now;
      ans %= mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
