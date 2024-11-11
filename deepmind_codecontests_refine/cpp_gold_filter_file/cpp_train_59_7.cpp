#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int n, p[N + 1], cnt[N + N + N];
int main() {
  scanf("%d", &n);
  int shift = 0, gt = 0, lte = 0;
  long long dev = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    ++cnt[p[i] - i + n];
    dev += abs(p[i] - i);
    if (p[i] <= i)
      ++lte;
    else
      ++gt;
  }
  long long ans = dev;
  for (int k = 1; k < n; ++k) {
    dev += lte - gt - 1 + 2 * p[n - k + 1] - (n + 1);
    --cnt[p[n - k + 1] - (n - k + 1) + n];
    ++cnt[p[n - k + 1] - (n - k + 1) + n + n];
    lte += cnt[k + n] - 1;
    gt -= cnt[k + n] - 1;
    if (dev < ans) {
      shift = k;
      ans = dev;
    }
  }
  printf("%lld %d\n", ans, shift);
  return 0;
}
