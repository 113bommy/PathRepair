#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long d[200010];
long long sum[200010];
int main() {
  int n, k;
  cin >> n >> k;
  long long ss = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    sum[i] = sum[i - 1] + a[i];
    if (i == 1) continue;
    ss += (i - 2) * a[i - 1];
    d[i] = ss - (i - 1) * (n - i) * a[i];
  }
  long long tot = 0;
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    d[i] += cnt * (n - i) * a[i];
    d[i] -= tot;
    tot += cnt * a[i];
    if (d[i] >= k) continue;
    tot -= cnt * a[i];
    tot += a[i] * (i - 1);
    cnt++;
    printf("%d\n", i);
  }
  return 0;
}
