#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
const long long N = 10;
const long long M = 10;
const long long ispSize = 10;
const long long primeSize = 10;
const long long matSize = 150;
const double pi = 3.141592653589;
template <class T>
T __lcm(T lcmA, T lcmB) {
  return lcmA / __gcd(lcmA, lcmB) * lcmB;
}
template <class T>
void exgcd(T E_A, T E_B, T &E_X, T &E_Y) {
  if (!E_B)
    E_X = 1, E_Y = 0;
  else
    exgcd(E_B, E_A % E_B, E_Y, E_X), E_Y -= E_A / E_B * E_X;
}
template <class T>
T Exgcd(T E_A, T E_B, T &E_X, T &E_Y) {
  if (!E_B) {
    E_X = 1, E_Y = 0;
    return E_A;
  } else {
    T res = Exgcd(E_B, E_A % E_B, E_Y, E_X);
    E_Y -= E_A / E_B * E_X;
    return res;
  }
}
template <class T>
T niyuan(T NY_a, T NY_p) {
  long long NY_x, NY_y;
  exgcd(NY_a, NY_p, NY_x, NY_y);
  return (NY_x % NY_p + NY_p) % NY_p;
}
template <class T>
T FastMul(T FMa, T FMb, T FMp) {
  return (FMa * FMb - (long long)(FMa / (long double)FMp * FMb + 1e-3) * FMp +
          FMp) %
         FMp;
}
template <class T>
T modadd(T MA, T MB) {
  return ((MA % p) + (MB % p)) % p;
}
template <class T>
T modmul(T MA, T MB) {
  return ((MA % p) * (MB % p)) % p;
}
bool bcmp(const long long &AAA, const long long &BBB) { return AAA > BBB; }
int en, prime_cnt = 0;
int front[N], isp[ispSize], prime[primeSize];
struct Edge {
  int v, w, next;
} e[M];
void addEdge(int u, int v, int w) {
  ++en;
  e[en].v = v;
  e[en].w = w;
  e[en].next = front[u];
  front[u] = en;
}
void GetPrime(int n) {
  for (int i = 1; i <= n; ++i) isp[i] = 1;
  isp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (isp[i]) prime[++prime_cnt] = i;
    for (int j = 1; j <= prime_cnt && i * prime[j] <= n; ++j) {
      isp[i * prime[j]] = 0;
      if (i % prime[j] == 0) break;
    }
  }
}
long long inv[N], fact[N];
inline void getFact(long long COUNT, long long MOD) {
  fact[0] = 1;
  for (int i = 1; i <= COUNT; ++i) fact[i] = (fact[i - 1] * i) % MOD;
}
inline void getInv(long long MOD) {
  inv[1] = 1;
  for (int i = 2; i < MOD; ++i) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}
inline long long C(long long Cn, long long Cm, long long Cp) {
  return (Cn < Cm) ? 0
                   : fact[Cn] * inv[fact[Cm]] % Cp * inv[fact[Cn - Cm]] % Cp;
}
inline long long lucas(long long Ln, long long Lm, long long Lp) {
  return (Lm == 0) ? (1 % Lp)
                   : lucas(Ln / Lp, Lm / Lp, Lp) * C(Ln % Lp, Lm % Lp, Lp) % Lp;
}
struct mat {
  long long a[matSize][matSize];
  inline mat() { memset(a, 0, sizeof(a)); }
  inline mat operator-(const mat &T) const {
    mat res;
    for (int i = 0; i < matSize; ++i)
      for (int j = 0; j < matSize; ++j) res.a[i][j] = (a[i][j] - T.a[i][j]) % p;
    return res;
  }
  inline mat operator+(const mat &T) const {
    mat res;
    for (int i = 0; i < matSize; ++i)
      for (int j = 0; j < matSize; ++j) res.a[i][j] = (a[i][j] + T.a[i][j]) % p;
    return res;
  }
  inline mat operator*(const mat &T) const {
    mat res;
    int r;
    for (int i = 0; i < matSize; ++i)
      for (int k = 0; k < matSize; ++k) {
        r = a[i][k];
        for (int j = 0; j < matSize; ++j)
          res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= p;
      }
    return res;
  }
  inline mat operator^(long long x) const {
    mat res, bas;
    for (int i = 0; i < matSize; ++i) res.a[i][i] = 1;
    for (int i = 0; i < matSize; ++i)
      for (int j = 0; j < matSize; ++j) bas.a[i][j] = a[i][j] % p;
    while (x) {
      if (x & 1) res = res * bas;
      bas = bas * bas;
      x >>= 1;
    }
    return res;
  }
};
template <class T>
T FPW(T a, T b) {
  T bs = a, res = 1;
  while (b > 0) {
    if (b & 1) res = modmul(res, bs);
    bs = modmul(bs, bs);
    b >>= 1;
  }
  return res;
}
inline long long read() {
  long long x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
inline long long mread() {
  long long res = 0;
  char ch = getchar();
  while (!isdigit(ch) and ch != EOF) ch = getchar();
  while (isdigit(ch)) {
    res = (res << 3) + (res << 1) + (ch - '0');
    res %= p;
    ch = getchar();
  }
  return res;
}
long long n, cnt;
char s[100050];
int num[100050];
void main2() {
  n = read();
  scanf("%s", s + 1);
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    num[i] = s[i] - '0';
    if (num[i] == 0) cnt++;
  }
  if (!cnt) {
    if (n & 1)
      printf("%d %d %d %d\n", 2, n, (n / 2 + 2), n);
    else
      printf("%d %d %d %d\n", 1, n, (n / 2 + 1), n);
    return;
  }
  if (n & 1) {
    for (int i = 1; i <= n; ++i) {
      if (num[i] == 0) {
        if (i <= n / 2)
          printf("%d %d %d %d\n", i, n, i + 1, n);
        else
          printf("%d %d %d %d\n", 1, i, 1, i - 1);
        return;
      }
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      if (num[i] == 0) {
        if (i <= n / 2)
          printf("%d %d %d %d\n", i, n, i + 1, n);
        else
          printf("%d %d %d %d\n", 1, i, 1, i - 1);
        return;
      }
    }
  }
  return;
}
long long T;
int main() {
  T = read();
  for (int t = 1; t <= T; ++t) {
    main2();
  }
  return 0;
}
