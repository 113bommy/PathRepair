#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 1 << 20;
int k, n;
int a[N];
long long c[N];
long long d[N][20];
int main() {
  k = read(), n = read();
  for (int i = (0); i <= (k - 1); i++)
    for (int j = (1); j <= (n); j++) {
      int x;
      scanf("%1d", &x);
      a[j] |= x << i;
    }
  for (int i = (1); i <= (n); i++) c[a[i]]++;
  int m = (1 << k) - 1;
  for (int i = (0); i <= (m); i++) d[i][__builtin_popcount(i)] = 1;
  for (int i = (0); i <= (k - 1); i++)
    for (int j = (0); j <= (m); j++)
      if (~j >> i & 1) {
        {
          long long x = c[j], y = c[j | 1 << i];
          c[j] = x + y, c[j | 1 << i] = x - y;
        }
        {
          for (int t = (0); t <= (k); t++) {
            long long x = d[j][t], y = d[j | 1 << i][t];
            d[j][t] = x + y, d[j | 1 << i][t] = x - y;
          }
        }
      }
  for (int i = (0); i <= (m); i++)
    for (int j = (0); j <= (k); j++) d[i][j] *= c[i];
  for (int i = (0); i <= (k - 1); i++)
    for (int j = (0); j <= (m); j++)
      if (~j >> i & 1) {
        for (int t = (0); t <= (k); t++) {
          long long x = d[j][t], y = d[j | 1 << i][t];
          d[j][t] = (x + y) / 2, d[j | 1 << i][t] = (x - y) / 2;
        }
      }
  int ans = 1e9;
  for (int i = (0); i <= (m); i++) {
    int now = 0;
    long long sum = 0;
    for (int j = (0); j <= (k); j++) {
      sum += d[i][j];
      now += min(j, k - j) * d[i][j];
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
