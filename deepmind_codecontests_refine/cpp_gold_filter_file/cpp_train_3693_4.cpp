#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
inline void rds(char *s, int &x) {
  for (c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++);
       c < 33 || c > 126;
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    ;
  for (x = 0; c >= 33 && c <= 126;
       s[++x] = c, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                                   IS == IT ? EOF : *IS++)
                                 : *IS++))
    ;
  s[x + 1] = '\0';
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
inline void prints(string s) {
  int x = s.length();
  while (t < x) pc(s[t++]);
  pc('\n'), t = 0;
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::prints;
using io::rd;
using io::rds;
const int P = 1e4 + 7;
struct modint {
  int x;
  inline modint(int x = 0) : x(x) {}
  inline modint &operator=(int o) { return x = o, *this; }
  inline modint &operator+=(modint o) {
    return x = x + o.x >= P ? x + o.x - P : x + o.x, *this;
  }
  inline modint &operator-=(modint o) {
    return x = x - o.x < 0 ? x - o.x + P : x - o.x, *this;
  }
  inline modint &operator*=(modint o) { return x = 1ll * x * o.x % P, *this; }
  inline modint &operator^=(long long b) {
    modint a = *this, c;
    if (!~b) b = P - 2;
    c.x = 1 % P;
    while (b) {
      if (b & 1) c *= a;
      a *= a, b >>= 1;
    }
    return x = c.x, *this;
  }
  inline modint &operator/=(modint o) { return *this *= o ^= -1; }
  inline modint &operator+=(int o) {
    return x = x + o >= P ? x + o - P : x + o, *this;
  }
  inline modint &operator-=(int o) {
    return x = x - o < 0 ? x - o + P : x - o, *this;
  }
  inline modint &operator*=(int o) { return x = 1ll * x * o % P, *this; }
  inline modint &operator/=(int o) {
    modint y = modint(o);
    return *this *= y ^= -1;
  }
  template <class I>
  inline friend modint operator+(modint a, I b) {
    return a += b;
  }
  template <class I>
  inline friend modint operator-(modint a, I b) {
    return a -= b;
  }
  template <class I>
  inline friend modint operator*(modint a, I b) {
    return a *= b;
  }
  inline friend modint operator^(modint a, long long b) { return a ^= b; }
  template <class I>
  inline friend modint operator/(modint a, I b) {
    return a /= b;
  }
  inline friend bool operator==(modint a, int b) { return a.x == b; }
  inline friend bool operator!=(modint a, int b) { return a.x != b; }
  inline friend bool operator==(modint a, modint b) { return a.x == b.x; }
  inline friend bool operator!=(modint a, modint b) { return a.x != b.x; }
  inline bool operator!() { return !x; }
  inline modint operator-() { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }
const int N = 207, M = 307;
int n, m, k;
char s[N];
bool v[N][N][N];
modint h[N][N][N], f[M], g[M][M], F[M], G[M][M];
inline modint H(int i, int l, int r) {
  if (i < 0) return 0;
  if (v[i][l][r]) return h[i][l][r];
  v[i][l][r] = 1;
  if (l == 1 && r == m) return h[i][l][r] = !i;
  if (l != 1 && s[l - 1] != s[r]) h[i][l][r] += H(i - 1, l - 1, r);
  if (r != m && s[l] != s[r + 1]) h[i][l][r] += H(i - 1, l, r + 1);
  if (l != 1 && r != m && s[l - 1] == s[r + 1])
    h[i][l][r] += H(i, l - 1, r + 1);
  return h[i][l][r];
}
inline int ceil(int x) { return (x >> 1) + (x & 1); }
inline void mul(modint f[M], modint g[M][M]) {
  modint a[M];
  for (int j = 1; j <= k; j++)
    for (int i = 1; i <= k; i++) a[i] += f[j] * g[j][i];
  for (int i = 1; i <= k; i++) f[i] = a[i];
}
inline void mul(modint g[M][M]) {
  modint a[M][M];
  for (int i = 1; i <= k; i++)
    for (int o = i; o <= k; o++)
      for (int j = o; j <= k; j++) a[i][j] += g[i][o] * g[o][j];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++) g[i][j] = a[i][j];
}
inline void ksm(int o) {
  while (o) {
    if (o & 1) mul(f, g);
    mul(g), o >>= 1;
  }
}
int main() {
  rds(s, m), rd(n), k = m + ceil(m);
  for (int i = 0; i < m; i++) {
    modint c;
    for (int j = 1; j <= m; j++) {
      c += H(i, j, j);
      if (j != m && s[j] == s[j + 1]) c += H(i, j, j + 1);
    }
    if (i) {
      g[i][k - ceil(m - i)] = c, g[i][i] = 24;
      if (i != 1)
        g[i - 1][i] = 1;
      else
        f[i] = 1;
    } else {
      f[m] = c, g[k][k] = 26;
      for (int j = m; j < k; j++) g[j][j + 1] = 1, g[j][j] = 25;
    }
  }
  if ((n + m) & 1)
    for (int i = 1; i <= k; i++) F[i] = f[i];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++) G[i][j] = g[i][j];
  ksm(ceil(n + m));
  if (!((n + m) & 1)) return print(f[k]), 0;
  modint ans = f[k];
  for (int i = 1; i <= k; i++) f[i] = F[i];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++) g[i][j] = G[i][j];
  for (int i = 0; i < m; i++) {
    modint c;
    for (int j = 1; j <= m; j++)
      if (j != m && s[j] == s[j + 1]) c += H(i, j, j + 1);
    if (i)
      g[i][k - ceil(m - i)] = c;
    else
      f[m] = c, g[k][k] = 0;
  }
  ksm(ceil(n + m));
  print(ans - f[k]);
  return 0;
}
