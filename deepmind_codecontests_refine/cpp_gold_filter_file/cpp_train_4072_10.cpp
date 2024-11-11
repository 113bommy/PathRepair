#include <bits/stdc++.h>
using namespace std;
int mu[300005], prime[300005], tot, n;
int num[300005], ans[300005], f[300005], g[300005];
bool flag[300005];
void Prime(int N) {
  mu[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (flag[i] == false) tot++, prime[tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot; j++) {
      if (i * prime[j] > N) break;
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else
        mu[i * prime[j]] = mu[i] * (-1);
    }
  }
}
int main() {
  Prime(300000);
  scanf("%d", &n);
  for (int i = 0; i <= 300000; i++) ans[i] = 1000000000;
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), num[x]++, ans[x] = 0;
  for (int i = 1; i <= 300000; i++)
    for (int j = 1; j <= 300000 / i; j++) f[i] += num[i * j];
  for (int i = 1; i <= 300000; i++)
    for (int j = 1; j <= 300000 / i; j++) g[i * j] += mu[i] * f[i];
  for (int i = 300000; i >= 1; i--)
    for (int j = 1; j <= 300000 / i; j++)
      if (g[j]) ans[i] = min(ans[i], ans[i * j] + 1);
  if (ans[1] >= 1000000000)
    printf("-1\n");
  else
    printf("%d\n", ans[1] + 1);
  return 0;
}
