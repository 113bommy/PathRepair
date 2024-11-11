#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
const long long inf = 1e9;
const long long Inf = 1e10;
const long long P = 1000000007;
int f[N * 10], n, a[N], m;
bool vis[N * 10];
int pr[N * 10], tot, mu[N * 10];
int Pow(int x, int y, int P) {
  int A = 1;
  for (; y; y >>= 1, x = (long long)x * x % P)
    if (y & 1) A = (long long)A * x % P;
  return A;
}
int A(int x) { return (Pow(2, x, P) + P - 1) % P; }
int B(int x) {
  if (!x) return 0;
  return 1ll * x * Pow(2, x - 1, P) % P;
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", a + i);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int x = a[i];
    m = max(m, x);
    for (int j = 1; j * j <= x; j++) {
      if (x % j) continue;
      f[j]++;
      if (j * j < x) f[x / j]++;
    }
  }
  mu[1] = 1;
  for (int i = (int)(2); i <= (int)(m); i++) {
    if (!vis[i]) mu[pr[++tot] = i] = P - 1;
    for (int j = 1; j <= tot && i * pr[j] <= m; j++) {
      vis[i * pr[j]] = 1;
      if (i % pr[j] == 0) {
        mu[i * pr[j]] = 0;
        break;
      } else {
        mu[i * pr[j]] = P - mu[i];
      }
    }
  }
  int sum = 0, gt = 0;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (f[i]) sum = (sum + 1ll * mu[i] * B(f[i])) % P;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (f[i]) gt = (gt + 1ll * mu[i] * A(f[i])) % P;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (a[i] == 1) sum = (sum + P - 1) % P;
  int Ans = (0ll + sum + sum + P - 1ll * gt * n % P) % P;
  printf("%d\n", Ans);
  return 0;
}
