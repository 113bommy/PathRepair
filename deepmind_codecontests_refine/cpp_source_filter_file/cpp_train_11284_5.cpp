#include <bits/stdc++.h>
using namespace std;
int a[200010], ans[200010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long sum = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    long long s1 =
        sum - (long long)(i - 1LL - cnt) * (long long)(n - i) * (long long)a[i];
    if (s1 < k)
      ans[++cnt] = i;
    else
      sum += (long long)a[i] * (long long)(i - 1LL);
  }
  for (int i = 1; i <= cnt; i++) printf("%d\n", ans[i]);
  return 0;
}
