#include <bits/stdc++.h>
using namespace std;
const long long M = 505;
struct point {
  long long x, y;
  point(){};
  point(long long _x, long long _y) { x = _x, y = _y; }
  point operator-(const point &A) const { return point(x - A.x, y - A.y); }
  long long operator*(const point &A) const {
    return (long long)x * A.y - (long long)y * A.x;
  }
} A[M], B[M];
long long n, m;
long long sum[M][M], ans;
int main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &A[i].x, &A[i].y);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", &B[i].x, &B[i].y);
  A[0] = point(-1e9 - 5, -1e9 - 5);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) {
      if ((A[i] - A[0]) * (A[j] - A[0]) <= 0) continue;
      for (long long k = 1; k <= m; k++)
        if ((A[i] - A[0]) * (B[k] - A[0]) >= 0 &&
            (A[j] - A[i]) * (B[k] - A[i]) >= 0 &&
            (B[k] - A[0]) * (A[j] - A[0]) >= 0)
          sum[i][j]++;
      sum[j][i] = -sum[i][j];
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++)
      for (long long k = j + 1; k <= n; k++)
        ans += ((sum[i][j] + sum[j][k] + sum[k][i]) == 0);
  printf("%lld", ans);
  return 0;
}
