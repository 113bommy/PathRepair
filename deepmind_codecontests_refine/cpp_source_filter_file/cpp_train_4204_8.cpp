#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 15;
long long a[maxn], sum[maxn];
int main() {
  long long n, ans = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans = max(ans, sum[i] ^ sum[j]);
  printf("%lld\n", ans);
  return 0;
}
