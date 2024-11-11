#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int t = 1, sum = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
  return t * sum;
}
const int Max = 1e6 + 10, mod = 1e9 + 7;
int a[Max], b[Max], num[Max], n, K, m, ans;
vector<int> f[Max];
int main() {
  int i, j, k, last, now;
  long long L;
  n = read();
  scanf("%lld", &L);
  K = read();
  for (i = 1; i <= n; i++) b[i] = a[i] = read();
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (i = 1; i <= n; i++)
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b, num[a[i]]++;
  num[0] = 1;
  f[0].push_back(1);
  for (i = 1; i <= m; i++) f[0].push_back(0);
  for (i = 1; i <= K; i++) {
    f[i].push_back(0);
    last = f[i - 1][0];
    for (j = 1; j <= m; j++) {
      now = (last + 1LL * f[i - 1][j] * num[j] % mod) % mod;
      f[i].push_back(now);
      last = now;
    }
  }
  for (i = 1; i <= K; i++)
    for (j = 1; j <= n; j++) {
      k = (L / n + (j <= L % n) - i + 1) % mod;
      if (k > 0) ans = (ans + 1LL * k * f[i][a[j]] % mod) % mod;
    }
  printf("%d\n", ans);
  return 0;
}
