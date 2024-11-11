#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const long long INF = 0x3F3F3F3F;
int w;
long long sum[MAXN];
int n, l, r, ql, qr;
int min(long long a, long long b) { return a < b ? a : b; }
long long F(int x) {
  long long ans = 0;
  ans += sum[x] * l;
  ans += (sum[n] - sum[x]) * r;
  if (x > n - x)
    ans += (2 * x - n - 1) * ql;
  else if (x < n - x)
    ans += (n - x * 2 - 1) * qr;
  return ans;
}
int main() {
  while (~scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr)) {
    memset(sum, 0, sizeof(sum));
    long long mins = INF;
    for (int i = 1; i <= n; i++) scanf("%d", &w), sum[i] = sum[i - 1] + w;
    if (n == 1) {
      mins = min(sum[1] * l, sum[1] * r);
      printf("%I64d\n", mins);
      continue;
    }
    for (int i = 1; i <= n; i++) mins = min(mins, F(i));
    printf("%I64d\n", mins);
  }
  return 0;
}
