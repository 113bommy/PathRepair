#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
const long long mod = 1e9 + 7;
int n;
long long x, y;
long long cnt[MAXN];
long long sum[MAXN];
int main() {
  scanf("%d%lld%lld", &n, &x, &y);
  int maxn = 0;
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    cnt[val]++;
    sum[val] += (long long)val;
    maxn = max(maxn, val);
  }
  for (int i = 1; i <= maxn * 2; i++)
    sum[i] += sum[i - 1], cnt[i] += cnt[i - 1];
  long long ans = ((long long)0x3f3f3f3f3f3f3f3f);
  if (maxn == 1) {
    ans = min(y * n, x * (n - 1));
  }
  for (int i = 2; i <= maxn; i++) {
    long long cost = 0;
    for (int j = 1; j <= maxn; j += i) {
      int r = j + i - 1;
      int tmpr = r - ((x + y - 1) / y);
      if (tmpr - j + 1 > 0) {
        cost += (cnt[tmpr] - cnt[j - 1]) * x +
                ((cnt[r - 1] - cnt[tmpr]) * r - sum[r - 1] + sum[tmpr]) * y;
      } else {
        cost += ((cnt[r - 1] - cnt[j - 1]) * r - sum[r - 1] + sum[j - 1]) * y;
      }
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}
