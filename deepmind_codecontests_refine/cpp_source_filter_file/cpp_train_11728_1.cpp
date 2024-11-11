#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
long long n, d, b, a[N], sum[N];
int main() {
  scanf("%lld%lld%lld", &n, &d, &b);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n / 2; ++i) {
    if (sum[min(i + i * d, n)] >= (cnt1 + 1) * b) cnt1++;
    if (sum[n] - sum[max(n - i + 1 - i * d, 0LL)] >= (cnt2 + 1) * b) cnt2++;
  }
  printf("%d\n", n / 2 - min(cnt1, cnt2));
  return 0;
}
