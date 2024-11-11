#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c == ' ' || c == '\n') c = _buff.get();
  return c;
}
int p[1000111], pn, mnp[10000111], phi[10000111], mu[10000111];
bool np[10000111];
int pre[10001111];
long long solve(int d, int n, int lim) {
  if (n == 1) return 0;
  long long ret = 0, all = 0, tret = 0;
  for (int i = 2; i <= n; i++) {
    int cmnp = min(mnp[d], mnp[i]);
    if (1ll * cmnp * mnp[d] <= lim)
      tret += 2;
    else if (cmnp * 2 <= lim && mnp[d] * 2 <= lim)
      tret += 3;
    if (1ll * cmnp * cmnp <= lim)
      ret -= 2;
    else if (cmnp * 2 <= lim)
      ret -= 3;
    if (cmnp * 2 <= lim) all++;
    pre[cmnp]++;
  }
  for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
  for (int i = 1; i <= n; i++) {
    if (np[i]) continue;
    long long cur = pre[i] - pre[i - 1];
    if (cur == 0) continue;
    ret += cur * pre[min(n, lim / i)] * 2;
    if (i * 2 <= lim) ret += cur * (all - pre[min(n, lim / i)]) * 3;
  }
  for (int i = 1; i <= n; i++) pre[i] = 0;
  return ret / 2 + tret;
}
int main() {
  mu[1] = 1;
  mnp[1] = 23333333;
  for (int i = 2; i <= 10000005; i++) {
    if (!np[i]) p[pn++] = i, mnp[i] = i, phi[i] = i - 1, mu[i] = -1;
    for (int j = 0; j < pn && 1ll * i * p[j] <= 10000005; j++) {
      np[i * p[j]] = 1;
      mnp[i * p[j]] = p[j];
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        mu[i * p[j]] = 0;
        break;
      } else
        phi[i * p[j]] = phi[i] * (p[j] - 1), mu[i * p[j]] = -mu[i];
    }
  }
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 2; i <= n; i++) ans += (i - 1) - phi[i];
  for (int i = 1; i <= n; i++) {
    if (!mu[i]) continue;
    ans += mu[i] * solve(i, n / i, n);
  }
  cout << ans << endl;
  return 0;
}
