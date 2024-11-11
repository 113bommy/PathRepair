#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[10], ta[10];
int b[10];
int pm[200010], tt = 0;
bool v[1000010];
inline void GetPrime(int m) {
  for (int i = 2; i <= m; ++i) {
    if (!v[i]) pm[++tt] = i;
    for (int j = 1; j <= tt && i * pm[j] <= m; ++j) {
      v[i * pm[j]] = 1;
      if (i % pm[j] == 0) break;
    }
  }
}
int g[10];
int ans = 1000000000;
inline void work() {
  int tp = 0, num = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i] != 1) ++tp;
  for (int i = 1; i <= n; ++i)
    if (!g[i]) ++num, tp += b[i];
  tp += (num > 1);
  if (tp < ans) ans = tp;
}
void dfs(int x) {
  if (x > n) {
    work();
    return;
  }
  g[x] = 0;
  dfs(x + 1);
  for (int i = 1; i <= x - 1; ++i)
    if (ta[i] % a[x] == 0) {
      ta[i] /= a[i];
      g[x] = i;
      dfs(x + 1);
      ta[i] *= a[i];
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  sort(a + 1, a + n + 1, greater<long long>());
  m = (int)sqrt(a[1]);
  GetPrime(m);
  for (int i = 1; i <= n; ++i) {
    long long x = a[i];
    for (int j = 1; j <= tt; ++j)
      if (x % pm[j] == 0) {
        while (x % pm[j] == 0) ++b[i], x /= pm[j];
        if (x == 1) break;
      }
    if (x > 1) ++b[i];
  }
  for (int i = 1; i <= n; ++i) ta[i] = a[i];
  dfs(2);
  printf("%d\n", ans);
  return 0;
}
