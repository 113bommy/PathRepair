#include <bits/stdc++.h>
using namespace std;
long long n;
int la, lb, cnt, prm[600009], phi[6000009], f[600009], fac[600009], inv[600009];
char a[600009], b[600009];
int ksm(int x, long long y) {
  int z = 1;
  for (; y; y >>= 1, x = (long long)x * x % 1000000007)
    if (y & 1) z = (long long)z * x % 1000000007;
  return z;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void pwk() {
  int i, j, k;
  fac[0] = inv[0] = inv[1] = 1;
  for (i = 1; i < 600009; i++) fac[i] = (long long)fac[i - 1] * i % 1000000007;
  for (i = 2; i < 600009; i++)
    inv[i] = 1000000007 -
             (long long)inv[1000000007 % i] * (1000000007 / i) % 1000000007;
  for (i = 2; i < 600009; i++)
    inv[i] = (long long)inv[i] * inv[i - 1] % 1000000007;
  for (i = 2; i < 6000009; i++) {
    if (!phi[i]) {
      phi[i] = i - 1;
      prm[++cnt] = i;
    }
    for (j = 1; j <= cnt && (k = i * prm[j]) < 6000009; j++)
      if (i % prm[j])
        phi[k] = phi[i] * (prm[j] - 1);
      else {
        phi[k] = phi[i] * prm[j];
        break;
      }
  }
  phi[1] = 1;
  for (i = 2; i < 600009; i++) phi[i] = (phi[i] + phi[i - 1]) % 1000000007;
}
int work(long long m) {
  if (m < 6000009) return phi[m];
  long long i, j;
  int &ans = f[n / m];
  if (ans != -1) return ans;
  ans = m % 1000000007 * ((m - 1) % 1000000007) * (1000000007 + 1 >> 1) %
        1000000007;
  for (i = 2; i <= m; i = j + 1) {
    j = m / (m / i);
    ans = (ans - (j - i + 1) % 1000000007 * work(m / i) % 1000000007 +
           1000000007) %
          1000000007;
  }
  return ans;
}
int solve(long long m) {
  long long i, j;
  int last = 0, now, ans = 0;
  for (i = 1; i <= m; last = now, i = j + 1) {
    j = m / (m / i);
    now = ksm(2, j);
    ans = (ans + (long long)(now - last + 1000000007) * (work(m / i) * 2 - 1)) %
          1000000007;
  }
  return ans;
}
int main() {
  scanf("%s%s%lld", a + 1, b + 1, &n);
  la = strlen(a + 1);
  lb = strlen(b + 1);
  pwk();
  int i, x, y, z, da = 0, db = 0, s1 = 0, s2 = 0, ans = 0;
  for (i = 1; i <= la; i++)
    if (a[i] == 'A')
      da++;
    else if (a[i] == 'B')
      db++;
    else
      s1++;
  for (i = 1; i <= lb; i++)
    if (b[i] == 'A')
      da--;
    else if (b[i] == 'B')
      db--;
    else
      s2++;
  for (i = 0; i <= s1 + s2; i++) {
    x = da + i - s2;
    y = db + s1 - i;
    if (!x || !y) continue;
    if ((x > 0) ^ (y > 0)) {
      x = abs(x);
      y = abs(y);
      z = gcd(x, y);
      ans = (ans + ((long long)fac[s1 + s2] * inv[i] % 1000000007 *
                    inv[(s1 + s2) - (i)] % 1000000007) *
                       (ksm(2, n / max(x / z, y / z) + 1) - 2 + 1000000007)) %
            1000000007;
    }
  }
  if (la == lb) {
    for (i = y = 1, x = 0; i <= la; i++) {
      if (a[i] == '?' && b[i] == '?') x++;
      if (a[i] - 'A' + b[i] - 'A' == 1) y = 0;
    }
    z = (s2 >= da ? ((long long)fac[s1 + s2] * inv[s2 - da] % 1000000007 *
                     inv[(s1 + s2) - (s2 - da)] % 1000000007)
                  : 0);
    if (y) {
      ans = (ans + (long long)ksm(2, x) * (ksm(2, n + 1) - 2 + 1000000007) %
                       1000000007 * (ksm(2, n + 1) - 2 + 1000000007)) %
            1000000007;
      z = (z - ksm(2, x) + 1000000007) % 1000000007;
    }
    ans = (ans + (long long)z * solve(n)) % 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
