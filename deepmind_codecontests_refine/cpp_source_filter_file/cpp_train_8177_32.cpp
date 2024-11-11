#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, maxm = 500005;
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
int n, m, eu[maxm], ev[maxm];
bitset<maxn> f[maxn];
int main() {
  n = gi();
  m = gi();
  for (int i = 1; i <= m; ++i) eu[i] = gi(), ev[i] = gi(), f[eu[i]][ev[i]] = 1;
  for (int i = 1; i <= n; ++i) f[i][i + n] = 1;
  for (int i = 1; i <= n; ++i) {
    int p = i;
    while (!f[p][i]) ++p;
    if (p != i) swap(f[p], f[i]);
    for (int j = 1; j <= n; ++j)
      if (j != i && f[j][i]) f[j] ^= f[i];
  }
  for (int i = 1; i <= m; ++i) puts(f[ev[i]][eu[i] + n] ? "NO" : "YES");
  return 0;
}
