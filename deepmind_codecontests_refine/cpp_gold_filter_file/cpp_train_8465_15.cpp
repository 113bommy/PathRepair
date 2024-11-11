#include <bits/stdc++.h>
using namespace std;
long long g[1000010], h[1000010], p[1000010], ans;
int n, m, a, b, sum;
int main() {
  p[0] = 1;
  for (int i = 1; i < 1000010; i++) p[i] = p[i - 1] * 999983;
  while (scanf("%d %d", &n, &m) != EOF) {
    memset(h, 0, sizeof h);
    memset(g, 0, sizeof g);
    while (m--) {
      scanf("%d %d", &a, &b);
      h[a] += p[b];
      h[b] += p[a];
    }
    for (int i = 1; i <= n; i++) g[i] = h[i] + p[i];
    sort(h + 1, h + n + 1);
    sort(g + 1, g + n + 1);
    ans = 0;
    sum = 0;
    for (int i = 2; i <= n; i++)
      if (h[i] == h[i - 1])
        ans += ++sum;
      else
        sum = 0;
    sum = 0;
    for (int i = 2; i <= n; i++)
      if (g[i] == g[i - 1])
        ans += ++sum;
      else
        sum = 0;
    printf("%I64d\n", ans);
  }
}
