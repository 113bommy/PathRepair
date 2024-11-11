#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 300005, p = 1000000007, S = 300000;
int n, a1, a2, b1, b2, c1, c2, len;
char s[maxn], t[maxn];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = (long long)a * a % p)
    if (b & 1) ret = (long long)ret * a % p;
  return ret;
}
int fac[maxn << 1], inv[maxn << 1];
int pw[maxn];
int phi[maxn], mn[maxn], pc, prm[50000];
int g[maxn];
void prepare() {
  fac[0] = 1;
  for (int i = int(1); i <= (int)(S << 1); i++)
    fac[i] = (long long)fac[i - 1] * i % p;
  inv[S << 1] = qpow(fac[S << 1], p - 2);
  for (int i = int((S << 1) - 1); i >= (int)(0); i--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % p;
  phi[1] = 1;
  for (int i = int(2); i <= (int)(S); i++) {
    if (!mn[i]) prm[mn[i] = ++pc] = i, phi[i] = i - 1;
    for (int j = int(1); j <= (int)(mn[i]); j++) {
      int k = i * prm[j];
      if (k > S) break;
      mn[k] = j;
      if (j == mn[i])
        phi[k] = phi[i] * prm[j];
      else
        phi[k] = phi[i] * (prm[j] - 1);
    }
  }
  g[1] = phi[1];
  for (int i = int(2); i <= (int)(S); i++) g[i] = (g[i - 1] + phi[i] * 2) % p;
  pw[0] = 1;
  for (int i = int(1); i <= (int)(S + 1); i++) pw[i] = (pw[i - 1] << 1) % p;
}
int ans;
void upd(int &x, int y) { x = x + y >= p ? x + y - p : x + y; }
int C(int n, int m) { return (long long)fac[n] * inv[m] % p * inv[n - m] % p; }
int main() {
  scanf("%s", s);
  len = strlen(s);
  for (int i = int(0); i <= (int)(len - 1); i++) {
    if (s[i] == 'A') a1++;
    if (s[i] == 'B') b1++;
    if (s[i] == '?') c1++;
  }
  scanf("%s", t);
  len = strlen(t);
  for (int i = int(0); i <= (int)(len - 1); i++) {
    if (t[i] == 'A') a2++;
    if (t[i] == 'B') b2++;
    if (t[i] == '?') c2++;
  }
  n = rd();
  prepare();
  for (int i = int(-c2); i <= (int)(c1); i++) {
    int ca = a1 - a2 + i, cb = b1 - b2 + (c1 - c2 - i), xs = C(c1 + c2, i + c2);
    if (ca == 0 && cb == 0) {
      if (strlen(s) == strlen(t)) {
        int fas = 1;
        for (int i = int(0); i <= (int)(len - 1); i++) {
          if (s[i] == '?' && t[i] == '?')
            upd(fas, fas);
          else if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
            fas = 0;
            break;
          }
        }
        xs = (xs + p - fas) % p,
        upd(ans, (long long)(pw[n + 1] - 2) * (pw[n + 1] - 2) % p * fas % p);
      }
      for (int i = int(1); i <= (int)(n); i++)
        upd(ans, (long long)g[i] * xs % p * pw[i] % p);
    } else if ((long long)ca * cb < 0) {
      int la = abs(ca), lb = abs(cb), g = gcd(la, lb);
      la /= g, lb /= g;
      upd(ans, (long long)xs * (pw[n / max(la, lb) + 1] - 2) % p);
    }
  }
  rt(ans), putchar('\n');
}
