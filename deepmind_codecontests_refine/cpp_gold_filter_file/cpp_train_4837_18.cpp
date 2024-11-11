#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const long long MAXN = 1000010;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
const long long inv2 = (mod + 1) / 2;
const long long inv3 = (mod + 1) / 3;
long long T, N, M;
inline long long gcd(long long a, long long b) {
  return (!b ? a : gcd(b, a % b));
}
inline long long P(long long a, long long b) {
  return (a * b - a - b + gcd(a, b)) / 2;
}
long long phi[MAXN + 1], D[MAXN + 1], f[MAXN + 1];
long long cnt;
long long sum0[MAXN + 1], sum1[MAXN + 1], sum2[MAXN + 1];
bool vis[MAXN + 1];
long long pri[MAXN + 1], g[MAXN + 1], pt[MAXN + 1];
inline void init() {
  phi[1] = 1;
  f[1] = 1;
  for (long long i = 2; i <= MAXN; i++) {
    if (!vis[i]) pri[++cnt] = i, phi[i] = i - 1, f[i] = i + phi[i], D[i] = i;
    if (D[i] == i && vis[i]) {
      f[i] = (f[i / pt[i]] * pt[i] + phi[i]) % mod;
    }
    for (long long j = 1; j <= cnt && pri[j] * i <= MAXN; j++) {
      vis[i * pri[j]] = 1;
      pt[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        D[i * pri[j]] = D[i] * pri[j];
        f[i * pri[j]] = f[i / D[i]] * f[D[i] * pri[j]] % mod;
        break;
      }
      D[i * pri[j]] = pri[j];
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      f[i * pri[j]] = f[i] * f[pri[j]] % mod;
    }
  }
  return;
}
inline void init2() {
  for (long long s = 1; s <= MAXN; s++) {
    g[s] = (s * (s + 1) % mod * (2 * s + 1) % mod * inv3 % mod -
            3 * s % mod * s % mod + mod + 2 * f[s] % mod) %
           mod;
    sum2[s] = (sum2[s - 1] + (s - 1) * (s - 1) % mod * g[s] % mod) % mod;
    sum1[s] = (sum1[s - 1] + (s - 1) * g[s] % mod) % mod;
    sum0[s] = (sum0[s - 1] + g[s]) % mod;
  }
}
int main() {
  init();
  init2();
  T = read();
  while (T--) {
    N = read(), M = read();
    printf("%lld\n", (N * M % mod * sum0[min(N, M)] % mod -
                      (N + M) * sum1[min(N, M)] % mod + mod + sum2[min(N, M)]) %
                         mod);
  }
  return 0;
}
