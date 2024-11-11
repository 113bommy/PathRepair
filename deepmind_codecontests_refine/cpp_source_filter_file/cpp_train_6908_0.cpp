#include <bits/stdc++.h>
using namespace std;
const int N = 2005, mod = 1073741824;
bool vis[N];
int a, b, c, mu[N], prm[N];
long long ans;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
void prepare() {
  mu[1] = 1;
  for (int i = 2; i <= 2000; ++i) {
    if (!vis[i]) prm[++*prm] = i, mu[i] = -1;
    for (int j = 1; j <= *prm; ++j) {
      if (i * prm[j] > 2000) break;
      vis[i * prm[j]] = 1;
      if (i % prm[j])
        mu[i * prm[j]] = -mu[i];
      else
        break;
    }
  }
}
long long query(int x, int y) {
  long long rt = 0;
  for (int i = 1; i <= x; ++i)
    if (gcd(i, y) == 1) rt += x / i;
  return rt;
}
int main() {
  scanf("%d%d%d", &a, &b, &c);
  prepare();
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= min(b, c); ++j)
      if (gcd(i, j) == 1)
        ans = (ans + a / i * mu[j] * query(b / j, i) * query(c / j, i)) % mod;
  printf("%I64dd\n", (ans + mod) % mod);
  return 0;
}
