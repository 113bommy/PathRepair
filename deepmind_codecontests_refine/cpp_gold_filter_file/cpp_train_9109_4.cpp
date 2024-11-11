#include <bits/stdc++.h>
using namespace std;
int N, x[3], y[3], xx, yy, jump[111111];
pair<long long, long long> dist[111111];
long long maxR2[111111], ans = LONG_LONG_MAX;
int main() {
  scanf("%d %d %d %d %d", &N, &x[1], &y[1], &x[2], &y[2]);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &xx, &yy);
    dist[i].first =
        1LL * (xx - x[1]) * (xx - x[1]) + 1LL * (yy - y[1]) * (yy - y[1]);
    dist[i].second =
        1LL * (xx - x[2]) * (xx - x[2]) + 1LL * (yy - y[2]) * (yy - y[2]);
  }
  sort(dist + 1, dist + N + 1);
  for (int i = N; i >= 0; i--) {
    maxR2[i] = max(maxR2[i + 1], dist[i].second);
    jump[i] = (dist[i].first == dist[i + 1].first) ? jump[i + 1] : (i + 1);
  }
  for (int i = 0; i <= N; i++) ans = min(ans, dist[i].first + maxR2[jump[i]]);
  printf("%I64d", ans);
}
