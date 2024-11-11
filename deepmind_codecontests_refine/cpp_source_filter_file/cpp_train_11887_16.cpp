#include <bits/stdc++.h>
using namespace std;
int da[200005];
long long sum[400005];
int main() {
  int n;
  cin >> n;
  int cnt = 1;
  long long ma = 0, mi = 1e11;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      da[i] = cnt++;
      da[i + n] = cnt++;
    } else {
      da[i + n] = cnt++;
      da[i] = cnt++;
    }
  }
  sum[1] = da[1];
  for (int i = 2; i <= 3 * n; i++) {
    sum[i] = sum[i - 1] + (i > 2 * n ? da[i - 2 * n] : da[i]);
  }
  int f = 1;
  for (int i = n; i <= 3 * n; i++) {
    ma = max(sum[i] - sum[i - n], ma);
    mi = min(sum[i] - sum[i - n], ma);
    if (ma - mi > 1) {
      f = 0;
      break;
    }
  }
  if (f) {
    puts("yes");
    for (int i = 1; i <= 2 * n; i++)
      i == 2 * n ? printf("%d\n", da[i]) : printf("%d ", da[i]);
  } else
    puts("no");
  return 0;
}
