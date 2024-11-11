#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
const long long inf = 1e18;
const int maxn = 3e5 + 10, mod = 1e9 + 7;
const int mod1 = 1e8 + 7, mod2 = 41;
const double pi = acos(-1);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
complex<double> power(complex<double> a, int n) {
  complex<double> p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
unsigned long long power(unsigned long long a, unsigned long long n) {
  unsigned long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
int n, m, k;
char s[maxn];
int dpx[10000][100], dpm[10000][100];
int l[maxn], r[maxn];
int all, pl;
int p, q, f, g;
void dfs(int x) {
  if (pl == n) return;
  while (s[pl] == ')') pl++;
  if (s[pl] == '(') {
    all++;
    l[x] = all;
    pl++;
    dfs(all);
  }
  while (s[pl] == ')') pl++;
  if (s[pl] == '?') {
    all++;
    r[x] = all;
    pl++;
    dfs(all);
    for (int i = 0; i <= g; i++) {
      dpx[x][i] = -1e5;
      dpm[x][i] = 1e5;
      for (int j = 0; j < i; j++) {
        if (f == 1) {
          dpx[x][i] = max(dpx[x][i], dpx[l[x]][j] + dpx[r[x]][i - j - 1]);
          dpm[x][i] = min(dpm[x][i], dpm[l[x]][j] + dpm[r[x]][i - j - 1]);
        } else {
          dpx[x][i] = max(dpx[x][i], dpx[l[x]][j] - dpm[r[x]][i - j - 1]);
          dpm[x][i] = min(dpm[x][i], dpm[l[x]][j] - dpx[r[x]][i - j - 1]);
        }
      }
      for (int j = 0; j <= i; j++) {
        if (f == 1) {
          dpx[x][i] = max(dpx[x][i], dpx[l[x]][j] - dpm[r[x]][i - j]);
          dpm[x][i] = min(dpm[x][i], dpm[l[x]][j] - dpx[r[x]][i - j]);
        } else {
          dpx[x][i] = max(dpx[x][i], dpx[l[x]][j] + dpx[r[x]][i - j]);
          dpm[x][i] = min(dpm[x][i], dpm[l[x]][j] + dpm[r[x]][i - j]);
        }
      }
    }
    return;
  }
  if (s[pl] <= '9' && s[pl] >= '0') {
    dpx[x][0] = s[pl] - '0';
    dpm[x][0] = s[pl] - '0';
    for (int i = 1; i <= g; i++) {
      dpx[x][i] = -1e5;
      dpm[x][i] = 1e5;
    }
    pl++;
    return;
  }
}
int main() {
  int kase = 1;
  while (~scanf("%s", s)) {
    n = strlen(s);
    scanf("%d%d", &p, &q);
    if (p <= q)
      f = 1;
    else
      f = 2;
    g = min(p, q);
    pl = 0;
    all = 0;
    dfs(0);
    printf("%d\n", dpx[0][g]);
  }
  return 0;
}
