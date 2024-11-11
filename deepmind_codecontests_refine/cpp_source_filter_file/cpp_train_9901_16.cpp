#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 7;
const long long INF = 1ll << 60;
int n;
long long x[N], y[N];
int xmn, ymn, xmx, ymx;
long long tri, qua;
long long dis(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
long long max_4(long long a, long long b, long long c, long long d) {
  return max(max(a, b), max(c, d));
}
int main() {
  scanf("%d", &n);
  xmn = ymn = xmx = ymx = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", x + i, y + i);
    if (x[i] < x[xmn]) xmn = i;
    if (x[i] > x[xmx]) xmx = i;
    if (y[i] < y[ymn]) ymn = i;
    if (y[i] > y[ymx]) ymx = i;
  }
  for (int i = 1; i <= n; ++i)
    tri = max(tri, max_4(dis(i, xmn) + dis(i, ymn) + dis(xmn, ymn),
                         dis(i, xmx) + dis(i, ymn) + dis(xmx, ymn),
                         dis(i, xmn) + dis(i, ymx) + dis(xmn, ymx),
                         dis(i, xmx) + dis(i, ymx) + dis(xmx, ymx)));
  qua = dis(xmn, ymn) + dis(xmx, ymn) + dis(xmn, ymx) + dis(xmx, ymx);
  printf("%lld ", tri);
  for (int i = 4; i <= n; ++i) printf("%lld ", qua);
  return 0;
}
