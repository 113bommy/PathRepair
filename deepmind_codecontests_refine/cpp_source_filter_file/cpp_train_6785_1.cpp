#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
long long n, a[100005], tot = 0;
long long dis[200][200], w[200][200];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    a[++tot] = read();
    if (!a[i]) tot--;
  }
  if (tot > 130) {
    puts("3");
    return 0;
  }
  n = tot;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) w[i][j] = dis[i][j] = 99999999;
  }
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j < i; j++)
      if (a[i] & a[j]) dis[i][j] = dis[j][i] = w[i][j] = w[j][i] = 1;
  }
  long long ans = 99999999;
  for (long long k = 1; k <= n; k++) {
    for (long long i = 1; i < k; i++)
      for (long long j = i + 1; j < k; j++) {
        ans = min(ans, dis[i][j] + w[i][k] + w[k][j]);
      }
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  }
  if (ans == 99999999)
    puts("-1");
  else
    printf("%lld\n", ans);
  return 0;
}
