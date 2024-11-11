#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long a[200005], b[200005];
long long cal(long long p) {
  b[n] = min(a[n], (long long)m * p - p * (p - 1) / 2 * n);
  for (int i = n - 1; i >= 1; i--) {
    b[i] = min(a[i], b[i + 1] - p);
  }
  if (b[1] < p * (p - 1) / 2 * n + p) return 0;
  long long pos = b[1] - ((m + 1) * (p - 1) - p * (p - 1) / 2 * n);
  pos = max(pos, 1LL);
  long long ss = b[1], buy = b[1];
  long long free = m - n * p - pos + 1;
  for (int i = 2; i <= n; i++) {
    buy += p;
    long long gp = min(a[i] - buy, free);
    free -= gp;
    buy += gp;
    ss += buy;
  }
  return ss;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = 0; (i) < (int)(n); (i)++) scanf("%lld", a + i + 1);
  long long ans = 0;
  for (int i = 1; i * n <= m; i++) ans = max(ans, cal(i));
  printf("%lld\n", ans);
  return 0;
}
