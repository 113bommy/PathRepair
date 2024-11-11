#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, a[2 * 200010];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
bool ok[200010];
int flag[200010];
long long sum[200010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int k = 1; k < n; k++) {
    if (n % k != 0) continue;
    for (int j = k; j <= n; j += k)
      if (gcd(j, n) == k) flag[j] = k;
    for (int j = 1; j <= n; j++) {
      if (flag[j] == k)
        sum[j] = sum[j - 1] + 1;
      else
        sum[j] = sum[j - 1];
    }
    memset(ok, 0, sizeof(bool) * n * 2);
    for (int j = 0; j < k; j++) {
      int mx = a[j];
      for (int t = j + k; t < n; t += k) mx = max(mx, a[t]);
      for (int t = j; t < n; t += k) {
        if (a[t] == mx) {
          ok[t + n] = ok[t] = true;
        }
      }
    }
    int pl = 0, pr = 0;
    while (pr <= 2 * n) {
      if (pl >= n) break;
      if (!ok[pr])
        pl = pr = pr + 1;
      else {
        pr++;
        int len = pr - pl;
        if (pr > n && pl < n)
          ans = ans + sum[pr - pl] - sum[n - pl];
        else
          ans = ans + sum[len];
        if (len >= n) pl++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
