#include <bits/stdc++.h>
using namespace std;
const int V = 100010;
char get(void) {
  static char buf[V], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, V, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
void Read(long long &x) {
  x = 0;
  static char c;
  while (c > '9' || c < '0') c = get();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = get();
  }
}
long long Pow(long long x, long long y, long long p) {
  if (!y) return 1;
  if (y == 1) return x;
  long long v = Pow(x, y >> 1, p);
  v = v * v % p;
  if (y & 1) return v * x % p;
  return v;
}
long long N, P, a[V], b[V], s1, s2;
long long div(long long x) { return Pow(x, P - 2, P); }
bool Check(long long d, long long &a1) {
  a1 = ((s1 - (N * (N - 1) / 2 * d) % P + P) % P * div(N)) % P;
  long long t = 0LL;
  t = (N * a1 % P * a1 % P);
  t += N * (N - 1) % P * (2 * N - 1) % P * d % P * d % P * div(6) % P;
  t %= P;
  t += N * (N - 1) % P * d % P * a1 % P;
  t %= P;
  return (t == s2);
}
int main(void) {
  Read(P);
  Read(N);
  int i, j;
  for (i = 1; i <= N; i++) {
    Read(a[i]);
    (s1 += a[i]) %= P;
    (s2 += a[i] * a[i] % P) %= P;
  }
  sort(a + 1, a + 1 + N);
  for (i = 1; i <= N; i++) {
    long long d = a[i] - a[1], a1;
    if (Check(d, a1)) {
      b[1] = a1;
      for (j = 2; j <= N; j++) b[j] = (b[j - 1] + d) % P;
      sort(b + 1, b + 1 + N);
      int flg = 1;
      for (j = 1; j <= N; j++) flg &= (a[j] == b[j]);
      if (flg) return printf("%I64d %I64d\n", a1, d), 0;
    }
  }
  printf("-1\n");
  return 0;
}
