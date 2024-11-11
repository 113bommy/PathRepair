#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void chkmin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <class T1, class T2>
inline void chkmax(T1 &x, T2 y) {
  if (y > x) x = y;
}
const int BUF_SIZE = 1 << 20;
char buf[BUF_SIZE], *P1 = buf, *P2 = buf, obuf[BUF_SIZE], *PO = obuf;
inline char getc() {
  if (P1 == P2) P2 = (P1 = buf) + fread(buf, 1, BUF_SIZE, stdin);
  return P1 == P2 ? EOF : *P1++;
}
inline void read(int &x) {
  register char ch = getc();
  x = 0;
  while (!isdigit(ch)) ch = getc();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getc();
}
inline void flushO() {
  fwrite(obuf, PO - obuf, 1, stdout);
  PO = obuf;
}
inline void putc(char ch) {
  if (PO == obuf + (BUF_SIZE)) flushO();
  *PO++ = ch;
}
inline void prints(char s[]) {
  for (char *ss = s; *ss != '\0'; ss++) putc(*ss);
}
inline void write(long long x) {
  if (x > 9) write(x / 10);
  putc(x % 10 ^ 48);
}
const int N = 1000005, MOD = 998244353;
inline int mo(int x) { return x >= MOD ? x - MOD : x; }
inline void pluseq(int &x, int y) { x = mo(x + y); }
inline int ksm(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % MOD)
    if (b & 1) res = 1ll * res * a % MOD;
  return res;
}
int fac[N], inv[N], _s0[N], _s1[N];
int *s0 = _s0 + 1, *s1 = _s1 + 1;
int n, cnt0, cnt1, cnt2, ans;
char s[N];
inline void math_init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= (n); i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[n] = ksm(fac[n], MOD - 2);
  for (int i = n; i >= (1); i--) inv[i - 1] = 1ll * inv[i] * i % MOD;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  math_init(n);
  for (int i = 0; i <= (n - 1); i++)
    cnt0 += s[i] == '(', cnt1 += s[i] == ')', cnt2 += s[i] == '?';
  for (int i = 0; i <= (cnt2); i++) s0[i] = s0[i - 1] + C(cnt2, i);
  for (int i = 0; i <= (cnt2 - 1); i++) s1[i] = s1[i - 1] + C(cnt2 - 1, i);
  int k1 = cnt1, k2 = cnt2;
  for (int i = 0; i <= (n - 1); i++)
    if (s[i] == '?')
      k2--, pluseq(ans, s1[max(min(k2 + k1 - 1, cnt2 - 1), -1)]);
    else if (s[i] == '(')
      pluseq(ans, s0[max(min(k2 + k1 - 1, cnt2), -1)]), k1--;
    else
      k1--;
  printf("%d", ans);
}
