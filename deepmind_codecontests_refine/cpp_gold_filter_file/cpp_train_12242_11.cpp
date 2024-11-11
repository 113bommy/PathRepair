#include <bits/stdc++.h>
using namespace std;
int l1, l2, Aa, Ba, Ca, Ab, Bb, Cb, flag, CC;
long long ans, inv[600005], fac[600005], ifac[600005], G;
int fl[6000005];
long long pr[6000005], cnt;
char a[6000005], b[6000005];
long long n, m, phi[6000005];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
long long C(int x, int y) {
  return fac[y] * ifac[y - x] % 1000000007 * ifac[x] % 1000000007;
}
long long pw(long long x, long long y) {
  long long ans = 1;
  for (; y; x = x * x % 1000000007, y >>= 1)
    if (y & 1) ans = ans * x % 1000000007;
  return ans;
}
map<int, int> Map;
long long S(long long n) {
  if (n <= m) return phi[n];
  if (Map[n]) return Map[n];
  long long tmp = 0;
  for (long long i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    tmp = (tmp + S(n / i) * ((j - i + 1) % 1000000007)) % 1000000007;
  }
  return Map[n] =
             (n % 1000000007 * (n % 1000000007 + 1) / 2 - tmp) % 1000000007;
}
long long GetF(long long n) {
  long long ans = S(n) * 2 - 1;
  return ans % 1000000007;
}
long long GetG(long long n) {
  long long ans = 0, now, lst = 1;
  for (long long i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    now = pw(2, j + 1) - 1;
    ans = ans + (now - lst) * GetF(n / i) % 1000000007;
    lst = now;
  }
  return ans % 1000000007;
}
int main() {
  scanf("%s%s", a + 1, b + 1);
  l1 = strlen(a + 1);
  l2 = strlen(b + 1);
  scanf("%lld", &n);
  inv[1] = 1;
  for (int i = 2; i <= 600000; i++)
    inv[i] = (-1000000007 / i) * inv[1000000007 % i] % 1000000007;
  fac[0] = 1;
  ifac[0] = 1;
  for (int i = 1; i <= 600000; i++)
    fac[i] = fac[i - 1] * i % 1000000007,
    ifac[i] = ifac[i - 1] * inv[i] % 1000000007;
  flag = l1 == l2;
  for (int i = 1; i <= l1; i++) {
    if (a[i] == 'A') Aa++;
    if (a[i] == 'B') Ba++;
    if (a[i] == '?') Ca++;
    flag &= a[i] == b[i] || a[i] == '?' || b[i] == '?';
    if (a[i] == '?' && b[i] == '?') CC++;
  }
  for (int i = 1; i <= l2; i++) {
    if (b[i] == 'A') Ab++;
    if (b[i] == 'B') Bb++;
    if (b[i] == '?') Cb++;
  }
  m = pow(n, 2. / 3);
  phi[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (!fl[i]) {
      phi[i] = i - 1;
      pr[++cnt] = i;
    }
    for (int j = 1, tmp; j <= cnt && (tmp = pr[j] * i) <= m; j++) {
      fl[tmp] = 1;
      if (i % pr[j]) {
        phi[tmp] = phi[i] * (pr[j] - 1);
      } else {
        phi[tmp] = phi[i] * pr[j];
        break;
      }
    }
    phi[i] = (phi[i] + phi[i - 1]) % 1000000007;
  }
  G = GetG(n);
  for (int i = -Cb; i <= Ca; i++) {
    int A = Aa - Ab + i, B = Bb + Cb - Ba - Ca + i;
    long long t = C(Cb + i, Ca + Cb);
    if ((long long)A * B < 0) continue;
    if (A <= 0 && B <= 0) A = -A, B = -B;
    if (A == 0 && B == 0) {
      if (flag) {
        long long tmp = pw(2, n + 1), tmp1 = pw(2, CC);
        ans = (ans + (long long)(tmp - 2) * (tmp - 2) % 1000000007 * tmp1 %
                         1000000007) %
              1000000007;
        t = (t - tmp1 + 1000000007) % 1000000007;
      }
      ans = (ans + t * G) % 1000000007;
      continue;
    }
    if (A > B) swap(A, B);
    if (A == 0) continue;
    ans = (ans +
           (long long)t * (pw(2, n / (B / gcd(A, B)) + 1) - 2) % 1000000007) %
          1000000007;
  }
  printf("%lld\n", (ans + 1000000007) % 1000000007);
}
