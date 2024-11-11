#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
const int MAXN = 600010;
const int mod = 1e9 + 7;
inline int Mod(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y, x -= x >= mod ? mod : 0; }
inline int fsp(int x, int k = mod - 2) {
  int s = 1;
  while (k) {
    if (k & 1) s = 1LL * s * x % mod;
    x = 1LL * x * x % mod, k >>= 1;
  }
  return s;
}
int n;
char S[MAXN];
char T[MAXN];
int NS, SA, SB, SQ;
int NT, TA, TB, TQ;
int tot;
int pri[MAXN];
int chk[MAXN];
int phi[MAXN];
int pw[MAXN];
int fac[MAXN];
int ifac[MAXN];
int F0;
inline void init(int N, int n) {
  N = max(N, n) << 1;
  pw[0] = fac[0] = ifac[0] = 1;
  for (int i = 1; i <= N; i++) {
    pw[i] = Mod(pw[i - 1] << 1);
    fac[i] = 1LL * fac[i - 1] * i % mod;
  }
  ifac[N] = fsp(fac[N]);
  for (int i = N; i >= 1; i--) ifac[i - 1] = 1LL * i * ifac[i] % mod;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!chk[i]) pri[++tot] = i, phi[i] = i - 1;
    for (int j = 1; j <= tot; j++) {
      if (i * pri[j] > n) break;
      chk[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
  }
  for (int i = 1; i <= n; i++) Add(phi[i], phi[i - 1]);
  for (int i = 1; i <= n; i++)
    F0 = (F0 + 1LL * pw[i] * (2 * phi[n / i] - 1)) % mod;
}
inline int f(int x, int y) {
  if (!x && !y) return F0;
  if (1LL * x * y >= 0) return 0;
  x = abs(x), y = abs(y);
  return pw[1LL * n * gcd(x, y) / max(x, y) + 1] - 2;
}
inline int C(int n, int m) {
  return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
  scanf("%s", S + 1);
  scanf("%s", T + 1);
  NS = strlen(S + 1);
  NT = strlen(T + 1);
  scanf("%d", &n);
  init(max(NS, NT), n);
  for (int i = 1; i <= NS; i++) {
    if (S[i] == 'A') SA++;
    if (S[i] == 'B') SB++;
    if (S[i] == '?') SQ++;
  }
  for (int i = 1; i <= NT; i++) {
    if (T[i] == 'A') TA++;
    if (T[i] == 'B') TB++;
    if (T[i] == '?') TQ++;
  }
  int cnt = 0, res = 0;
  if (NS == NT) {
    int Same = 0;
    for (int i = 1; i <= NS; i++)
      if (S[i] == '?' || T[i] == '?')
        ++Same, cnt += S[i] == T[i];
      else if (S[i] == T[i])
        ++Same;
    if (Same == NT)
      res = 1LL * (fsp(pw[n + 1] - 2, 2) + mod - F0) * pw[cnt] % mod;
  }
  for (int t = -TQ; t <= SQ; t++)
    res = (res +
           1LL * f(SA - TA + t, SB - TB + SQ - TQ - t) * C(SQ + TQ, SQ - t)) %
          mod;
  cout << res << endl;
  return 0;
}
