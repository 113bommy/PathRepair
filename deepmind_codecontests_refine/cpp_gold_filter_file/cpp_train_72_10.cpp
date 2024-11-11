#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1000010];
int blo[1000010];
int ri[1000010];
long long ans;
const long long INF = 1e18;
long long cal(long long x) {
  long long r = 0;
  long long res = 0;
  while (r < n) {
    if (ri[r] == -1) return INF;
    long long tmp = ri[r] + x;
    res++;
    if (tmp <= r) return INF;
    r = tmp;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= n; i++) blo[i] = 1;
  for (int i = 1; i <= m; i++) {
    int tmp;
    scanf("%d", &tmp);
    blo[tmp] = 0;
  }
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n; i++) {
    if (blo[i] == 1)
      ri[i] = i;
    else {
      if (i == 0)
        ri[i] = -1;
      else
        ri[i] = ri[i - 1];
    }
  }
  ans = INF;
  for (int l = 1; l <= k; l++) {
    long long tmp = cal(l);
    if (tmp == INF) continue;
    ans = min(ans, tmp * a[l]);
  }
  if (ans == INF) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", ans);
}
