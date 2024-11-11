#include <bits/stdc++.h>
using namespace std;
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long n, p, l, r, cnt, tot, ap, ans;
long long dv[15], du[15], num[15], prm[100005];
bool fl[100005];
long long qpow(long long x, long long p, long long cys) {
  long long ret = 1;
  for (; p; p >>= 1, x = x * x % cys)
    if (p & 1) ret = ret * x % cys;
  return ret;
}
namespace Cb {
long long prd[15][200005];
void exgcd(long long x, long long y, long long &a, long long &b) {
  if (y == 0) {
    a = 1, b = 0;
    return;
  }
  exgcd(y, x % y, b, a);
  b -= a * (x / y);
}
long long getinv(long long n, long long cys) {
  long long x, y;
  exgcd(n, cys, x, y);
  return (x % cys + cys) % cys;
}
long long calc(long long n, long long x) {
  if (n <= 1) return 1;
  long long ans = n >= du[x] ? qpow(prd[x][du[x]], n / du[x], du[x]) : 1;
  return (n % du[x] == 0 ? ans : ans * prd[x][n % du[x]] % du[x]) *
         calc(n / du[x], x) % du[x];
}
long long C(long long n, long long m, long long x) {
  long long pw = 0;
  for (long long i = n; i; i /= dv[x]) pw += i / dv[x];
  for (long long i = m; i; i /= dv[x]) pw -= i / dv[x];
  for (long long i = n - m; i; i /= dv[x]) pw -= i / dv[x];
  if (pw >= num[x]) return 0;
  return qpow(dv[x], pw, du[x]) * calc(n, x) % du[x] *
         getinv(calc(m, x), du[x]) % du[x] * getinv(calc(n - m, x), du[x]) %
         du[x];
}
long long exlucas(long long n, long long m) {
  if (n < m) return 0;
  long long now = 1, lst = 0, aa, nw;
  for (int i = 1; i <= cnt; i++) {
    aa = C(n, m, i);
    nw = now * du[i];
    lst = (aa * now % nw * getinv(now % du[i], du[i]) % nw +
           lst * du[i] % nw * getinv(du[i] % now, now) % nw) %
          nw;
    now = nw;
  }
  return lst;
}
}  // namespace Cb
void getprime() {
  fl[1] = true;
  for (int i = 2; i <= 100000; i++) {
    if (!fl[i]) prm[++tot] = i;
    for (int j = 1; j <= tot && i * prm[j] <= 100000; j++) {
      fl[i * prm[j]] = true;
      if (i % prm[j] == 0) break;
    }
  }
}
int main() {
  getprime();
  n = readint();
  ap = p = readint();
  l = readint();
  r = readint();
  for (int i = 1; i <= tot && prm[i] <= sqrt(p); i++) {
    if (p % prm[i] == 0) {
      dv[++cnt] = prm[i], du[cnt] = 1;
      while (p % prm[i] == 0) num[cnt]++, p /= prm[i], du[cnt] *= prm[i];
    }
  }
  if (p > 1) dv[++cnt] = p, num[cnt] = 1, du[cnt] = p;
  for (int i = 1; i <= cnt; i++) {
    Cb::prd[i][0] = 1;
    for (int j = 1; j <= min(n, du[i]); j++) {
      Cb::prd[i][j] = Cb::prd[i][j - 1];
      if (j % dv[i]) Cb::prd[i][j] = Cb::prd[i][j] * j % du[i];
    }
  }
  for (int i = 0; i <= n; i++)
    ans = (ans + Cb::exlucas(n, i) *
                     (Cb::exlucas(n - i, (n - i + l + 1) / 2) + ap -
                      Cb::exlucas(n - i, (n - i + r) / 2 + 1)) %
                     ap) %
          ap;
  cout << ans << endl;
  return 0;
}
