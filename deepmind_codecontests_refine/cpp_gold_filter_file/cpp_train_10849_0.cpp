#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, w = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x * w;
}
const int N = 1 << 21;
int n, nn, mx, sz[N], o[N], f[N];
long long a[25], s[N];
int main() {
  n = rd();
  for (int i = (1); i <= (n); ++i) {
    a[i] = rd();
    if (!a[i]) n--, i--;
  }
  nn = 1 << n;
  for (int i = (0); i < (nn); ++i)
    for (int j = (1); j <= (n); ++j)
      if (i >> (j - 1) & 1) s[i] += a[j], sz[i]++;
  for (int i = (1); i < (nn); ++i) {
    for (int j = (i - 1) & i; 2 * j >= i && j; j = (j - 1) & i) {
      int S = i ^ j, T = j, c = sz[i] - 1;
      long long w = abs(s[S] - s[T]);
      if (w <= c && (w + c) % 2 == 0) {
        o[i] = 1;
        f[i] = 1;
        break;
      }
    }
  }
  for (int i = (1); i < (nn); ++i)
    if (o[i]) {
      int S = (nn - 1) ^ i;
      for (int j = S; j; j = (j - 1) & S) f[i | j] = max(f[i | j], f[j] + 1);
    }
  for (int i = (0); i < (nn); ++i) mx = max(mx, f[i]);
  printf("%d\n", n - mx);
  return 0;
}
