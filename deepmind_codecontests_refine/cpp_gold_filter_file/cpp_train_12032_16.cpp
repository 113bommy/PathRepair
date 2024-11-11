#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
long long K, T, p[20], c[210][210], f[20][210];
inline long long solve(long long l) {
  memset(f, 0, sizeof f);
  for (long long i = 0; i <= p[0]; i++) f[0][i] = c[l][i];
  for (long long i = 1; i < 16; i++) {
    for (long long len = 0; len <= l; len++)
      for (long long j = 0; j <= min(p[i], len); j++)
        f[i][len] += f[i - 1][len - j] * c[l - len + j][j];
  }
  return f[15][l];
}
inline void shuchu(long long j) {
  if (j < 10)
    write(j);
  else
    putchar(j - 10 + 'a');
}
signed main() {
  c[0][0] = 1;
  for (long long i = 1; i <= 200; i++) {
    c[i][0] = 1;
    for (long long j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  K = read();
  T = read();
  for (long long i = 0; i < 16; i++) p[i] = T;
  long long len = 1;
  while (1) {
    long long kp = 0;
    if (len == 1)
      kp = 15;
    else
      for (long long j = 1; j < 16; j++) {
        p[j]--;
        kp += solve(len - 1);
        p[j]++;
      }
    if (K > kp)
      K -= kp;
    else
      break;
    len++;
  }
  for (long long i = len; i; i--) {
    if (i == 1) {
      for (long long j = 0; j < 16; j++)
        if (len != 1 || j) {
          if (p[j]) K--;
          if (!K) {
            shuchu(j);
            return 0;
          }
        }
      break;
    }
    long long kp = 0;
    for (long long j = 0; j < 16; j++)
      if (i != len || j != 0) {
        p[j]--;
        kp = solve(i - 1);
        if (K > kp)
          K -= kp;
        else {
          shuchu(j);
          break;
        }
        p[j]++;
      }
  }
  return 0;
}
