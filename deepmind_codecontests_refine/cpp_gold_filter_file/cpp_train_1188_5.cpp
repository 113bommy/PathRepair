#include <bits/stdc++.h>
inline long long read() {
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  long long k = 0, kk = 1;
  if (c == '-') c = getchar(), kk = -1;
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return kk * k;
}
using namespace std;
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x / 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
long long n, lsg, jc[1000010], N[1000010], l, r, sum, ans, x, d;
struct qwq {
  long long x, y;
} a[1000010];
long long ksm(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) (ans *= x) %= lsg;
    (x *= x) %= lsg;
    y >>= 1;
  }
  return ans;
}
long long C(long long n, long long m) {
  return jc[n] * N[m] % lsg * N[n - m] % lsg;
}
void calc() {
  for (long long i = 2; i <= d; i++) {
    if (a[i].y >= l && a[i].y <= r) return;
    if (a[i].y < l) {
      long long dd = a[i].x - a[i - 1].x - 1, d = l - a[i].y - 1;
      if (d > dd) return;
      (sum *= C(dd, d)) %= lsg;
      d++;
      dd++;
      l -= d;
      r += dd - d;
    } else {
      long long dd = a[i].x - a[i - 1].x - 1, d = a[i].y - r - 1;
      if (d > dd) return;
      (sum *= C(dd, d)) %= lsg;
      d++;
      dd++;
      l -= dd - d;
      r += d;
    }
  }
  if (l < 1 || r > n) return;
  (ans += sum) %= lsg;
}
bool pd(qwq x, qwq y) { return x.x < y.x; }
signed main() {
  n = read();
  lsg = 1e9 + 7;
  jc[0] = 1;
  for (long long i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % lsg;
  N[n] = ksm(jc[n], lsg - 2);
  for (long long i = n - 1; i >= 0; i--) N[i] = N[i + 1] * (i + 1) % lsg;
  for (long long i = 1; i <= n; i++) {
    x = read();
    if (x) a[++d].x = x, a[d].y = i;
  }
  a[++d].x = n + 1;
  a[d].y = n + 1;
  n++;
  sort(a + 1, a + 1 + d, pd);
  if (a[1].x == 1) {
    sum = 1;
    l = r = a[1].y;
    calc();
  } else {
    l = a[1].y;
    r = a[1].x + a[1].y - 1;
    sum = ksm(2, a[1].x - 2);
    calc();
    l = a[1].y - a[1].x + 1;
    r = a[1].y;
    sum = ksm(2, a[1].x - 2);
    calc();
  }
  writeln(ans);
}
