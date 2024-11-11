#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2100000;
int n, d[Maxn], bj[Maxn], ans[Maxn], num;
long long pre[Maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  sort(d, d + n);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + d[i - 1];
  int j = 0;
  for (int k = 1; k <= n; k++) {
    long long l = pre[n] - pre[n - k], r = (long long)k * (k - 1);
    while (j < n && d[j] < k) j++;
    r += pre[min(j, n - k)] + 1ll * max(0, n - k - j) * k;
    long long now = d[n - k], diff = l - r;
    if (diff <= k && diff <= now) {
      bj[max(diff, 0ll)]++;
      bj[now + 1]--;
    }
    l -= d[n - k], r += min(d[n - k], k);
    diff = r - l;
    if (diff >= now + 1) {
      bj[now + 1]++;
      bj[min(diff + 1, (long long)n + 1)]--;
    }
  }
  j = 0;
  for (int i = 0; i <= n; i++) {
    j += bj[i];
    if (j == n && (pre[n] + i & 1) == 0) ans[++num] = i;
  }
  if (num == 0)
    puts("-1");
  else
    for (int i = 1; i <= num; i++) printf("%d ", ans[i]);
  return 0;
}
