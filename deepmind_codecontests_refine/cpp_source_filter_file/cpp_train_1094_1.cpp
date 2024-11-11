#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
long long sum[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  long long ans_sum = 0;
  int ans_len = 0, pos = 1, len = 1;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = min(i - 1, n - i);
    while (l < r) {
      int ml = (2 * l + r) / 3, mr = (2 * r + l + 2) / 3;
      long long suml = sum[i] - sum[i - ml - 1] + sum[n] - sum[n - ml];
      long long sumr = sum[i] - sum[i - mr - 1] + sum[n] - sum[n - mr];
      if (suml * (2 * mr + 1) < sumr * (2 * ml + 1))
        l = ml + 1;
      else
        r = mr - 1;
    }
    long long tmp_sum =
        sum[i] - sum[i - l - 1] + sum[n] - sum[n - l] - (l * 2 + 1) * a[i];
    if (tmp_sum * len > ans_sum * (2 * l + 1))
      ans_sum = tmp_sum, ans_len = l, pos = i, len = 2 * l + 1;
  }
  printf("%d\n", ans_len * 2 + 1);
  for (int i = pos - ans_len; i <= pos; i++) printf("%d ", a[i]);
  for (int i = n - ans_len + 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
