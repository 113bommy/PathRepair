#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
int64_t sum[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (sum[j] - sum[i] > 2 * a[i]) break;
      if (sum[j] - sum[i] == (a[i] ^ a[j + 1])) ++ans;
    }
    for (int j = i - 1; j > 1; --j) {
      if (sum[i - 1] - sum[j - 1] > 2 * a[i]) break;
      if (sum[i - 1] - sum[j - 1] > 2 * a[j - 1] &&
          sum[i - 1] - sum[j - 1] == (a[i] ^ a[j - 1]))
        ++ans;
    }
  }
  printf("%lld\n", ans);
}
