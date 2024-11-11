#include <bits/stdc++.h>
using namespace std;
const long long C = (long long)1e6 + 100;
const int N = 200200;
int n;
int m;
long long ans = 0;
long long curSum = 0;
long long a[N];
long long sum[N];
pair<long long, long long> h[N];
void addLine(long long k, long long y) {
  while (m > 0) {
    long long l = -C, r = C;
    long long k1 = h[m - 1].first, y1 = h[m - 1].second;
    if (k1 * l + y1 >= k * l + y) {
      m--;
      continue;
    }
    if (k1 * r + y1 <= k * r + y) return;
    if (m == 1) break;
    while (r - l > 1) {
      long long x = (l + r) / 2;
      if (k1 * x + y1 < k * x + y)
        l = x;
      else
        r = x;
    }
    if (h[m - 2].first * l + h[m - 2].second <= k1 * l + y1)
      m--;
    else
      break;
  }
  h[m++] = make_pair(k, y);
  return;
}
long long getVal(long long x) {
  if (m == 1 || h[0].first * x + h[0].second <= h[1].first * x + h[1].second)
    return h[0].first * x + h[0].second;
  int l = 0, r = m - 1;
  while (r - l > 1) {
    int p = (l + r) / 2;
    if (h[p].first * x + h[p].second >= h[p + 1].first * x + h[p + 1].second)
      l = p;
    else
      r = p;
  }
  return h[r].first * x + h[r].second;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    curSum += a[i] * (i + 1);
    sum[i + 1] = sum[i] + a[i];
  }
  for (int i = 0; i <= n; i++) addLine(-i, sum[i]);
  for (int i = 0; i < n; i++) {
    long long val = -getVal(a[i]);
    val += sum[i] - a[i] * i;
    ans = max(ans, val);
  }
  printf("%I64d\n", curSum + ans);
  return 0;
}
