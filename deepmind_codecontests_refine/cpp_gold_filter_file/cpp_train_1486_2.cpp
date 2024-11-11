#include <bits/stdc++.h>
using namespace std;
void ac(long long x) {
  if (x)
    puts("YES");
  else
    puts("NO");
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long ppow(long long a, long long b, long long mod) {
  a %= mod;
  long long ans = 1 % mod;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long readdd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return f * x;
}
void printtt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) printtt(x / 10);
  putchar(x % 10 + '0');
}
bool addd(long long a, long long b) { return a > b; }
long long lowbit(long long x) { return x & -x; }
const long long dx[4] = {0, 0, 1, -1};
const long long dy[4] = {1, -1, 0, 0};
const long long BN = 2e6 + 5;
struct BIT {
  long long c[BN];
  void init() { memset(c, 0, sizeof c); }
  long long lowbit(long long i) { return i & -i; }
  void add(long long i, long long t) {
    while (i < BN) c[i] += t, i += lowbit(i);
  }
  long long ask(long long i) {
    long long ans = 0;
    while (i) ans += c[i], i -= lowbit(i);
    return ans;
  }
};
bool Isprime(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void init() { ; }
const double Pi = acos(-1);
const double eps = 1e-7;
const long long mod = 1e9 + 7;
const long long modd = mod - 1;
const long long maxm = 1e6 + 5;
long long a[maxm];
long long b[maxm];
char t[maxm];
long long d[maxm][10];
long long n, m;
long long id(long long i, long long j) { return (i - 1) * m + j; }
long long okk(long long x, long long y) {
  for (long long j = 1; j < 3; j++) {
    long long t = (y >> j & 1);
    long long aa = (x >> j & 1);
    long long bb = (y >> (j - 1) & 1);
    long long cc = (x >> (j - 1) & 1);
    long long sum = t + aa + bb + cc;
    if (sum % 2 == 0) return 0;
  }
  return 1;
}
void solve() {
  n = readdd(), m = readdd();
  long long tot = 0;
  for (signed long long(i) = 1; (i) <= (n); (i)++) {
    scanf("%s", t + 1);
    for (signed long long(j) = 1; (j) <= (m); (j)++) {
      a[id(i, j)] = t[j] - '0';
    }
  }
  if (n >= 4 && m >= 4) {
    printtt(-1);
    puts("");
    ;
    return;
  }
  long long ans = 1e18;
  if (n == 1 || m == 1) {
    printtt(0);
    puts("");
    ;
    return;
  } else if (n == 2 || m == 2) {
    if (n == 2) {
      long long temp1 = 0;
      long long temp2 = 0;
      for (signed long long(j) = 1; (j) <= (m); (j)++) {
        long long aa = id(1, j);
        long long bb = id(2, j);
        long long t = a[aa] + a[bb];
        if (j & 1) {
          if (t % 2 == 0) {
            temp1++;
          } else {
          }
        } else {
          if (t % 2 == 1) temp1++;
        }
      }
      for (signed long long(j) = 1; (j) <= (m); (j)++) {
        long long aa = id(1, j);
        long long bb = id(2, j);
        long long t = a[aa] + a[bb];
        if (j & 1) {
          if (t % 2 == 1) {
            temp2++;
          }
        } else {
          if (t % 2 == 0) temp2++;
        }
      }
      long long temp = min(temp1, temp2);
      ans = min(ans, temp);
    } else {
      long long temp1 = 0;
      long long temp2 = 0;
      for (signed long long(i) = 1; (i) <= (n); (i)++) {
        long long aa = id(i, 1);
        long long bb = id(i, 2);
        long long t = a[aa] + a[bb];
        if (i & 1) {
          if (t % 2 == 0) {
            temp1++;
          }
        } else {
          if (t % 2 == 1) temp1++;
        }
      }
      for (signed long long(i) = 1; (i) <= (n); (i)++) {
        long long aa = id(i, 1);
        long long bb = id(i, 2);
        long long t = a[aa] + a[bb];
        if (i & 1) {
          if (t % 2 == 1) {
            temp2++;
          }
        } else {
          if (t % 2 == 0) temp2++;
        }
      }
      long long temp = min(temp1, temp2);
      ans = min(ans, temp);
    }
  } else if (n == 3 || m == 3) {
    if (n == 3) {
      for (long long j = 1; j <= m; j++) {
        for (long long k = 0; k < 8; k++) {
          long long cc = 0;
          for (long long i = 1; i <= 3; i++) {
            long long t = (k >> (i - 1) & 1);
            long long x = id(i, j);
            if (a[x] != t) {
              cc++;
            }
          }
          if (j == 1) {
            d[j][k] = cc;
          } else {
            d[j][k] = 1e18;
            for (long long last = 0; last < 8; last++) {
              if (okk(last, k)) {
                d[j][k] = min(d[j][k], d[j - 1][last] + cc);
              }
            }
          }
        }
      }
      for (long long k = 0; k < 8; k++) {
        ans = min(ans, d[m][k]);
      }
    } else {
      for (long long i = 1; i <= n; i++) {
        for (long long k = 0; k < 8; k++) {
          long long cc = 0;
          for (long long j = 1; j <= 3; j++) {
            long long t = (k >> (j - 1) & 1);
            long long x = id(i, j);
            if (a[x] != t) {
              cc++;
            }
          }
          if (i == 1) {
            d[i][k] = cc;
          } else {
            d[i][k] = 1e18;
            for (long long last = 0; last < 8; last++) {
              if (okk(last, k)) {
                d[i][k] = min(d[i][k], d[i - 1][last] + cc);
              }
            }
          }
        }
      }
      for (long long k = 0; k < 8; k++) {
        ans = min(ans, d[n][k]);
      }
    }
  }
  if (ans > n * m) ans = -1;
  printtt(ans);
  puts("");
  ;
}
signed main() {
  init();
  solve();
  return 0;
}
