#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int n, prime[N << 1], vis[N << 1], c[N << 1], m[N << 1][1010], mx[N << 1],
    d[N << 1], e[N << 1], sum[N << 1], cnt;
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < N; i++) d[i] = i + 1;
  d[0] = N - 1;
  for (int i = 1, a; i <= n; i++) scanf("%d", &a), c[a]++;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= cnt; j++) m[i][j] += m[i - 1][j];
    int tmp = i;
    for (int j = 1; j <= cnt && prime[j] <= tmp; j++)
      while (tmp % prime[j] == 0) tmp /= prime[j], m[i][j]++;
    for (int j = 1; j <= cnt; j++) {
      ans += (long long)m[i][j] * c[i];
      if (m[i][j] > 0) mx[i] = j;
    }
  }
  for (; 1;) {
    int Max = 0, pos = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= d[0]; i++) {
      sum[mx[d[i]]] += c[d[i]];
      if (sum[mx[d[i]]] >= Max) Max = sum[mx[d[i]]], pos = mx[d[i]];
    }
    if (Max < n - Max)
      break;
    else
      ans += n - 2 * Max;
    e[0] = 0;
    for (int i = 1; i <= d[0]; i++)
      if (mx[d[i]] == pos) {
        m[d[i]][pos]--;
        while (!m[d[i]][mx[d[i]]] && mx[d[i]] > 0) mx[d[i]]--;
        if (mx[d[i]]) e[++e[0]] = d[i];
      }
    for (int i = 0; i <= e[0]; i++) d[i] = e[i];
  }
  printf("%lld\n", ans);
}
