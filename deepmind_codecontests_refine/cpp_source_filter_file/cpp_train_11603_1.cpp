#include <bits/stdc++.h>
using namespace std;
long long P[100005], Inv[100005];
long long f1(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
int prm[100005], Q[100005], mu[100005], pri;
void Init() {
  P[0] = 1;
  for (int i = 1; i < 100005; i++) P[i] = P[i - 1] * i % 1000000007;
  Inv[0] = 1;
  for (int i = 1; i < 100005; i++) Inv[i] = f1(P[i], 1000000007 - 2);
  mu[1] = 1;
  for (int i = 2; i < 100005; i++) {
    if (!Q[i]) {
      prm[++pri] = i;
      mu[i] = -1;
    }
    for (int j = 1; prm[j] * i < 100005; j++) {
      Q[prm[j] * i] = 1;
      if (i % prm[j] == 0) {
        mu[prm[j] * i] = 0;
        break;
      }
      mu[prm[j] * i] = -mu[i];
    }
  }
}
long long C(int x, int y) {
  if (x < y || y < 0) return 0;
  return P[x] * Inv[y] % 1000000007 * Inv[x - y] % 1000000007;
}
int n, k;
int main() {
  Init();
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &n, &k);
    if (n == k && n == 1) {
      puts("1");
      continue;
    }
    long long ans = C(n - 1, k - 1);
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) {
        ans = (ans + C(n / i - 1, k - 1) * mu[i] + 1000000007) % 1000000007;
        if (i * i != n)
          ans = (ans + C(i - 1, k - 1) * mu[n / i] + 1000000007) % 1000000007;
      }
    printf("%lld\n", ans);
  }
  return 0;
}
