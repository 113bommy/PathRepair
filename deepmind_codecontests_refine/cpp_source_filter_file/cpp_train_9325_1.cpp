#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const long long MAXN = 1000010;
const long long MAXT = MAXN;
const long long INF = 1e9;
const long long Mod = 1e9 + 7;
long long N;
long long a[MAXN + 1];
struct data {
  long long x0, x1, x2;
  data(long long t0 = 0, long long t1 = 0, long long t2 = 0) {
    x0 = t0;
    x1 = t1;
    x2 = t2;
  }
} f[MAXN + 1];
long long s[MAXN + 1];
data operator+(const data a, const data b) {
  return data(
      a.x0 * b.x0 % Mod, (a.x1 * b.x0 + b.x1 * a.x0) % Mod,
      (a.x2 * b.x0 % Mod + b.x2 * a.x0 % Mod + a.x1 * b.x1 % Mod * 2 % Mod) %
          Mod);
}
long long tp[MAXN + 1];
int main() {
  N = read();
  for (long long i = 0; i < MAXT; i++) f[i] = data(1, 0, 0);
  for (long long i = 1; i <= N; i++)
    a[i] = read(), f[a[i]] = f[a[i]] + data(2, a[i], a[i] * a[i] % Mod);
  for (long long j = 0; j < MAXT; j++) tp[j] = j;
  long long pw10 = 1;
  for (long long i = 1; i <= 6; i++) {
    for (long long j = MAXT - 1; j >= 0; j--) {
      if ((tp[j] % 10) < 9) f[j] = f[j] + f[j + pw10];
      tp[j] /= 10;
    }
    pw10 = pw10 * 10 % Mod;
  }
  pw10 = 100000;
  long long ans = 0;
  for (long long j = 0; j < MAXT; j++) s[j] = f[j].x2;
  for (long long i = 6; i >= 1; i--) {
    for (long long j = 0; j < MAXT; j++) {
      if (((j / pw10) % 10) < 9) s[j] = (s[j] - s[j + pw10] + Mod) % Mod;
    }
    pw10 /= 10;
  }
  for (long long i = 0; i < MAXT; i++) ans ^= (s[i] * i);
  printf("%lld\n", ans);
  return 0;
}
