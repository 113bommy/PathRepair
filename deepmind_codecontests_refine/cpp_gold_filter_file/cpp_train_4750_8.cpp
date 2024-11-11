#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, prime[10000010], phi[10000010], p[10000010], v[10000010], cnt;
long long ans;
bool flag[10000010], f[10000010];
signed main() {
  n = read();
  if (n == 4 || n == 5) {
    cout << 1;
    return 0;
  }
  flag[1] = 1;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!flag[i]) prime[++cnt] = i, phi[i] = i - 1, p[i] = i, v[i] = -1;
    for (int j = 1; j <= cnt && prime[j] * i <= n; j++) {
      flag[prime[j] * i] = 1;
      p[prime[j] * i] = prime[j];
      if (i % prime[j] == 0) {
        phi[prime[j] * i] = phi[i] * prime[j];
        break;
      }
      phi[prime[j] * i] = phi[i] * (prime[j] - 1);
    }
  }
  long long tot = 0;
  for (int i = 2; i <= n; i++) tot += phi[i], v[p[i]]++;
  ans += 1ll * n * (n - 1) / 2 - tot;
  int u = 1;
  for (int i = 1; i <= cnt; i++)
    if (prime[i] > n / 2) u++;
  tot -= 1ll * u * (n - 1);
  tot += 1ll * u * (u - 1) / 2;
  ans += tot * 3;
  for (int i = 1; i <= cnt; i++)
    if (prime[i] <= n / 2) {
      for (int j = 1; j < i; j++)
        if (prime[i] * prime[j] <= n)
          ans--;
        else
          break;
      for (int j = 1; j <= cnt; j++)
        if (prime[j] <= n / prime[i])
          ans -= v[prime[j]];
        else
          break;
      for (int j = prime[i] * 2; j <= n; j += prime[i])
        if (p[j] <= n / prime[i]) ans++;
    } else
      break;
  u = 0;
  for (int i = 2; i <= n; i++)
    if (flag[i]) {
      ans -= i - 2;
      ans += i - 1 - phi[i];
      ans += u;
      int v = i;
      while (v > 1) ans -= !f[p[v]], f[p[v]] = 1, v /= p[v];
      v = i;
      while (v > 1) f[p[v]] = 0, v /= p[v];
    } else
      u++;
  cout << ans;
  return 0;
}
