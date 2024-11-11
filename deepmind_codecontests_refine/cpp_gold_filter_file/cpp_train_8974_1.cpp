#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int dpl[6 * maxn];
int dpr[6 * maxn];
int a[2 * maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0, ans = 0x3f3f3f3f;
    cin >> n;
    int sum1 = 4 * n, sum2 = 4 * n;
    for (int i = 0; i < 6 * maxn; i++) {
      dpl[i] = 0;
      dpr[i] = 0;
    }
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        sum++;
      else if (a[i] == 2)
        sum--;
    }
    for (int i = n; i >= 1; i--) {
      if (a[i] == 1)
        sum1++;
      else if (a[i] == 2)
        sum1--;
      if (dpl[sum1] != 0)
        dpl[sum1] = max(dpl[sum1], i);
      else
        dpl[sum1] = i;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
      if (a[i] == 1)
        sum2++;
      else if (a[i] == 2)
        sum2--;
      if (dpr[sum2] != 0)
        dpr[sum2] = min(dpr[sum2], i);
      else
        dpr[sum2] = i;
    }
    for (int i = -n; i <= n; i++) {
      if ((dpl[i + 4 * n] != 0 && dpr[sum - i + 4 * n] != 0))
        ans = min(ans, dpr[sum - i + 4 * n] - dpl[i + 4 * n] + 1);
    }
    if (sum == 0)
      cout << "0" << endl;
    else {
      if (dpr[sum + 4 * n] != 0) ans = min(ans, dpr[sum + 4 * n] - n);
      if (dpl[sum + 4 * n] != 0) ans = min(ans, n - dpl[sum + 4 * n] + 1);
      cout << ans << endl;
    }
  }
  return 0;
}
