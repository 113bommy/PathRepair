#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%1d", &a[i]);
    b[i] = b[i - 1] + a[i];
  }
  for (int i = 1; i + k - 1 <= n; i++) {
    int sum = b[i - 1] + b[n] - b[i + k - 1];
    if (sum == 0 || sum == (i - 1 + n - (i + k - 1))) {
      puts("tokitsukaze");
      return 0;
    }
  }
  if (2 * k >= n && k != 1) {
    bool flag = true;
    for (int i = 2; i + k - 1 < n; i++) {
      int sum1 = b[i - 1];
      int sum2 = b[n] - b[i + k - 1];
      if (sum1 == 0 && sum2 == (n - (i + k - 1))) {
        continue;
      }
      if (sum2 == 0 && sum1 == (i - 1)) {
        continue;
      }
      flag = false;
    }
    if (flag) {
      puts("quality");
      return 0;
    }
  }
  puts("once again");
  return 0;
}
