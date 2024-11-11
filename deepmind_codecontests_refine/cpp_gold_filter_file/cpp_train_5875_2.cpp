#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, i, j, md[1000005], pc, p[200005];
long long c[200005], lft[200005], sv[200005];
int main() {
  for (i = 2; i <= 1000000; i++) {
    if (!md[i]) {
      p[++pc] = i;
      md[i] = pc;
    }
    for (((j)) = (1); ((j)) <= ((pc)); ((j))++) {
      if (i * p[j] > 1000000) break;
      md[i * p[j]] = j;
      if (i % p[j] == 0) break;
    }
  }
  read(n);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    int x;
    long long y;
    read(x);
    read(y);
    x = md[x];
    c[x] += y;
  }
  read(lft[0]);
  for (((i)) = (1); ((i)) <= ((pc)); ((i))++) lft[i] = lft[0];
  for (;;) {
    bool f = 0;
    for (((i)) = (1); ((i)) <= ((pc)); ((i))++)
      if (lft[i]) {
        if (c[i]) {
          f = 1;
          long long t = min(c[i], lft[i]);
          c[i] -= t;
          lft[i] -= t;
          int x = (p[i] - 1);
          while (x != 1) {
            int j = md[x], coef = 0;
            while (x % p[j] == 0) {
              x /= p[j];
              coef++;
            }
            c[j] += coef * t;
          }
          sv[i] += t - 1;
        } else if (sv[i])
          sv[i]--;
        else
          lft[i]--;
      }
    if (!f) break;
  }
  int s = 0;
  for (((i)) = (1); ((i)) <= ((pc)); ((i))++) {
    s += !!c[i];
  }
  printf("%d\n", s);
  for (((i)) = (1); ((i)) <= ((pc)); ((i))++)
    if (!!c[i]) printf("%d %lld\n", p[i], c[i]);
  return 0;
}
