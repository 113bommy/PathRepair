#include <bits/stdc++.h>
using namespace std;
int n, nn, m;
long long x[1000010], xx[1000010];
long long lft[1000010], rht[1000010];
long long cnt1[1000010], cnt2[1000010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d", x + i), xx[i] = x[i];
  sort(xx, xx + n);
  nn = unique(xx, xx + n) - xx;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(xx, xx + nn, x[i]) - xx;
    cnt1[idx]++;
    cnt2[idx]++;
  }
  for (int i = 1; i < nn; i++) cnt1[i] += cnt1[i - 1];
  for (int i = nn - 1; i >= 0; i--) cnt2[i] += cnt2[i + 1];
  long long ans = 1LL << 60;
  for (int i = nn - 2; i >= 0; i--) {
    rht[i] = rht[i + 1] + (cnt2[i + 1] + m - 1) / m * 2 * (xx[i + 1] - xx[i]);
  }
  ans = rht[0];
  for (int i = 1; i < nn; i++) {
    lft[i] = lft[i - 1] + (cnt1[i - 1] + m - 1) / m * 2 * (xx[i] - xx[i - 1]);
    ans = min(ans, rht[i] + lft[i]);
  }
  cout << ans << endl;
}
