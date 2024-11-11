#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) {
    if (ch == '-') f = -1;
  }
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - 48;
  }
  return x * f;
}
const int N = 6e5;
const int P = 1e9 + 7;
long long fact[N + 3], finv[N + 3];
int pri[N + 3];
bool isp[N + 3];
int phi[N + 3];
long long sphi[N + 3];
char a[N + 3], b[N + 3];
int cnt[2][3];
long long ans1_[(N << 1) + 3];
long long *ans1 = ans1_ + N + 1;
int n, m, len, np;
long long ans;
long long quickpow(long long x, long long y) {
  long long cur = x, ret = 1ll;
  for (int i = 0; y; i++) {
    if (y & (1ll << i)) {
      y -= (1ll << i);
      ret = ret * cur % P;
    }
    cur = cur * cur % P;
  }
  return ret;
}
long long comb(long long x, long long y) {
  return x < 0 || y < 0 || x < y ? 0ll
                                 : fact[x] * finv[y] % P * finv[x - y] % P;
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
void EulerSieve() {
  isp[1] = 1;
  phi[1] = 1;
  for (int i = 1; i <= N; i++) {
    if (!isp[i]) {
      pri[++np] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= np && i * pri[j] <= N; j++) {
      isp[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * phi[pri[j]];
    }
  }
  for (int i = 1; i <= N; i++) sphi[i] = (sphi[i - 1] + phi[i]) % P;
}
long long calc(int x, int y) {
  if (x == 0 && y == 0) {
    long long ret = 0ll;
    for (int i = 1; i <= len; i++) {
      ret = (ret + quickpow(2ll, i) % P * (2ll * sphi[len / i] - 1ll)) % P;
    }
    return ret;
  } else if (1ll * x * y <= 0ll) {
    return 0ll;
  } else {
    if (x < 0 && y < 0) {
      x = -x, y = -y;
    }
    int g = gcd(x, y);
    int lim = len / max(x / g, y / g);
    return (quickpow(2ll, lim + 1) - 2 + P) % P;
  }
}
int main() {
  EulerSieve();
  fact[0] = 1ll;
  for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % P;
  finv[N] = quickpow(fact[N], P - 2);
  for (int i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1) % P;
  scanf("%s%s%d", a + 1, b + 1, &len);
  n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != '?')
      cnt[0][a[i] - 'A']++;
    else
      cnt[0][2]++;
  }
  for (int i = 1; i <= m; i++) {
    if (b[i] != '?')
      cnt[1][b[i] - 'A']++;
    else
      cnt[1][2]++;
  }
  for (int i = -cnt[1][2]; i <= cnt[0][2]; i++) {
    ans1[i] = comb(cnt[0][2] + cnt[1][2], cnt[1][2] + i);
  }
  if (n == m) {
    int sta = 0;
    long long tmp = 1ll;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] == '?' && b[i] == 'A') {
        sta++;
      } else if (a[i] == 'A' && b[i] == '?') {
        sta--;
      } else if (a[i] == '?' && b[i] == '?') {
        tmp = (tmp << 1) % P;
      } else if (a[i] != b[i] && a[i] != '?' && b[i] != '?') {
        ok = false;
      }
    }
    if (ok) {
      ans1[sta] = (ans1[sta] - tmp + P) % P;
      ans = (ans + tmp * quickpow(quickpow(2ll, len + 1) - 2, 2ll)) % P;
    }
  }
  for (int i = -cnt[1][2]; i <= cnt[0][2]; i++) {
    long long tmp = calc(cnt[0][0] - cnt[0][1] + i,
                         cnt[1][1] - cnt[1][0] - cnt[0][2] + cnt[1][2] + i);
    ans = (ans + tmp * ans1[i]) % P;
  }
  printf("%I64d\n", ans);
  return 0;
}
