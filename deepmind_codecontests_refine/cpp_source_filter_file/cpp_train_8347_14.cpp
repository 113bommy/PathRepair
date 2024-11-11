#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 1000500, M = 500000;
int n, sum[N], mx[N];
long long ans;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    sum[x]++;
    mx[x] = x;
  }
  for (int i = 1; i <= M + M; ++i)
    sum[i] += sum[i - 1], mx[i] = max(mx[i], mx[i - 1]);
  for (int y = 2; y <= 10; ++y) {
    long long cnty = 0;
    for (int k = 1; k * y <= M; ++k)
      cnty += 1LL * k * (sum[k * y + y - 1] - sum[k * y - 1]);
    int l = 2, r = 500000;
    while (l <= r) {
      int md = (l + r) >> 1;
      bool ok = 0;
      for (int k = 0; k <= M; k += y) {
        int j = mx[k + y - 1];
        if (j >= 2 * md && (cnty - j / y + (j - 2 * md) / y) >= md) {
          ok = 1;
          break;
        }
      }
      if (ok) {
        l = md + 1;
        continue;
      }
      long long mn1 = cnty, mn2 = cnty;
      for (int k = 0; k <= M; k += y) {
        int j = mx[k + y - 1];
        if (j < k) continue;
        if (j >= md) {
          mn2 = min(mn2, (long long)(j / y - (j - md) / y));
          if (mn2 < mn1) swap(mn2, mn1);
          if (sum[j] - sum[j - 1] > 1)
            mn2 = min(mn2, (long long)(j / y - (j - md) / y));
          if (j >= md && mx[j - 1] >= md && mx[j - 1] >= k) {
            j = mx[j - 1];
            mn2 = min(mn2, (long long)j / y - (j - md) / y);
            if (mn2 < mn1) swap(mn2, mn1);
          }
        }
      }
      if ((cnty - mn1 - mn2) >= md) {
        l = md + 1;
      } else
        r = md - 1;
    }
    if (l - 1 >= 2) ans = max(ans, 1LL * (l - 1) * y);
  }
  cout << ans << endl;
  return 0;
}
