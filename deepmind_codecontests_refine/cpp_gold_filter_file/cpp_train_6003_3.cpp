#include <bits/stdc++.h>
char getc() {
  char ch = getchar();
  while (ch < 'a' || ch > 'z') ch = getchar();
  return ch;
}
const long long base = 137, mod = 1e9 + 7;
std::map<long long, int> row1;
const int maxn = 2010, maxm = 210;
char g1[maxn][maxm], g2[maxm][maxn];
long long h1[maxn], h2[maxm][maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) g1[i][j] = getc();
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) g2[i][j] = getc();
  for (int i = 1; i <= n; ++i) {
    h1[i] = 0;
    for (int j = 1; j <= m; ++j) h1[i] = (h1[i] * base + g1[i][j]) % mod;
  }
  for (int i = 1; i <= n - m + 1; ++i) {
    long long hv = 0;
    for (int j = i; j <= i + m - 1; ++j) hv = (hv * base ^ h1[j]) % mod;
    row1[hv] = i;
  }
  long long powm = 1;
  for (int i = 1; i < m; ++i) powm = powm * base % mod;
  for (int i = 1; i <= m; ++i) {
    h2[i][1] = 0;
    for (int j = 1; j <= m; ++j) h2[i][1] = (h2[i][1] * base + g2[i][j]) % mod;
    for (int j = 2; j <= n - m + 1; ++j) {
      h2[i][j] = ((h2[i][j - 1] - g2[i][j - 1] * powm) % mod + mod) % mod;
      h2[i][j] = (h2[i][j] * base + g2[i][j + m - 1]) % mod;
    }
  }
  for (int j = 1; j <= n - m + 1; ++j) {
    long long hv = 0;
    for (int i = 1; i <= m; ++i) hv = (hv * base ^ h2[i][j]) % mod;
    if (row1.find(hv) != row1.end()) {
      printf("%d %d", row1[hv], j);
      return 0;
    }
  }
}
