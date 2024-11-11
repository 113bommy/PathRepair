#include <bits/stdc++.h>
using namespace std;
const int N = 300005, mo = 1e9 + 7, M = N * 8;
int n, a[N], tot, p[N], cnt[N], ans, Fac[N], Inv[N], m, ss, h[N], e[M], nxt[M],
    two[N];
bool bz[N];
char c;
int read() {
  int x = 0, sig = 1;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * sig;
}
int C(int n, int m) {
  if (n < m) return 0;
  return (long long)Fac[n] * Inv[m] % mo * Inv[n - m] % mo;
}
void Add(int x, int y) {
  e[++ss] = y;
  nxt[ss] = h[x];
  h[x] = ss;
}
int main() {
  Fac[0] = Inv[0] = Fac[1] = Inv[1] = 1;
  for (int i = 2; i < N; i++) {
    Inv[i] = (long long)Inv[mo % i] * (mo - mo / i) % mo;
    Fac[i] = (long long)Fac[i - 1] * i % mo;
    if (!bz[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      bz[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 2; i < N; i++) Inv[i] = (long long)Inv[i - 1] * Inv[i] % mo;
  n = read();
  two[0] = 1;
  for (int i = 1; i <= n; i++) two[i] = 2 * two[i - 1] % mo;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    for (int j = 0; p[j] * p[j] <= a[i]; j++)
      if (a[i] % p[j] == 0) {
        int k = 0;
        for (; a[i] % p[j] == 0; a[i] /= p[j]) k++;
        Add(p[j], k);
      }
    if (a[i] > 1) Add(a[i], 1);
  }
  for (int i = 0; i < tot; i++) {
    m = 0;
    for (long long j = 1; j < N; j *= p[i]) m++;
    for (int j = 1; j <= m; j++) cnt[j] = 0;
    cnt[0] = n;
    for (int j = h[p[i]]; j; j = nxt[j])
      cnt[e[j]]++, ans = (ans + (long long)two[n - 1] * e[j]) % mo;
    for (int j = m - 1; j; j--) {
      cnt[j] += cnt[j + 1];
      for (int k = 0, t = 0; k <= cnt[j]; k++) {
        t = (t + C(n - cnt[j], k)) % mo;
        ans = (ans - (long long)k * C(cnt[j], k) % mo * t) % mo;
      }
      for (int k = cnt[j], t = 0; k; k--) {
        t = (t + C(cnt[j], k)) % mo;
        ans = (ans + (long long)k * C(n - cnt[j], k) % mo * t) % mo;
      }
    }
  }
  if (ans < 0) ans += mo;
  printf("%d\n", ans);
  return 0;
}
