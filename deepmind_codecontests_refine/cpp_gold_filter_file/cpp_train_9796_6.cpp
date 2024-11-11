#include <bits/stdc++.h>
using namespace std;
const int maxbuff = 1 << 17;
char ibuff[maxbuff], obuff[maxbuff];
inline char Getchar() {
  static char *p1 = ibuff, *p2 = ibuff;
  if (p1 == p2) {
    p1 = ibuff;
    p2 = ibuff + fread(ibuff, 1, maxbuff, stdin);
    if (p1 == p2) return -1;
  }
  return *p1++;
}
int optr = 0;
inline void Putchar(char c) {
  if (optr == maxbuff) {
    fwrite(obuff, 1, optr, stdout);
    optr = 0;
  }
  obuff[optr++] = c;
}
inline void Flush() { fwrite(obuff, 1, optr, stdout); }
template <class T>
inline int read(T &x) {
  x = 0;
  char c = Getchar();
  if (c == EOF) return -1;
  for (; c < '0' || c > '9'; c = Getchar())
    ;
  for (; c >= '0' && c <= '9'; c = Getchar()) x = x * 10 + c - '0';
  return 0;
}
template <class T>
inline void write(const T &x, int tag = 0) {
  if (!x) {
    if (!tag) Putchar(x + '0');
    return;
  }
  write(x / 10, 1);
  Putchar(x % 10 + '0');
}
template <class T>
inline void writeln(const T &x) {
  write(x);
  Putchar('\n');
}
template <class T>
inline void writesp(const T &x) {
  write(x);
  Putchar(' ');
}
const int N = 4e6 + 19;
long long num[N], A[N];
int cnt, fac[N];
map<long long, int> mp1, mp2;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve(int n, long long x, long long y) {
  long long t = y;
  for (long long i = 2; i <= 1000000 && i * i <= y && i <= t; ++i) {
    if (t % i == 0) {
      while (t % i == 0) t /= i;
      fac[cnt++] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] % x) continue;
    long long tmp = gcd(A[i] / x, y / x);
    int msk = 0;
    for (int j = 0; j < cnt; ++j) msk |= (tmp % fac[j] == 0) << j;
    ++num[msk];
  }
  for (int i = 0; i < cnt; ++i)
    for (int j = 0; j < (1 << cnt); ++j)
      if ((j & (1 << i)) == 0) num[j | (1 << i)] += num[j];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (y % A[i]) continue;
    long long tmp = y / A[i];
    int msk = 0;
    for (int j = 0; j < cnt; ++j) msk |= (tmp % fac[j] == 0) << j;
    ans += num[((1 << cnt) - 1) ^ msk];
  }
  writeln(ans);
}
signed main() {
  long long n, x, y;
  read(n);
  read(x);
  read(y);
  if (y % x) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    read(A[i]);
    if (A[i] % x == 0) ++mp1[gcd(A[i] / x, y / x)];
    if (y % A[i] == 0) ++mp2[y / A[i]];
  }
  if (mp1.size() < 5000 && mp2.size() < 5000) {
    long long ans = 0;
    for (auto u : mp1)
      for (auto v : mp2)
        if (gcd(u.first, v.first) == 1) ans += 1ll * u.second * v.second;
    writeln(ans);
  } else
    solve(n, x, y);
  Flush();
  return 0;
}
