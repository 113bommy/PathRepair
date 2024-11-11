#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
long long a[maxn], pre[maxn], suf[maxn];
long long exp_x[20];
int n, k, x;
int main() {
  scanf("%d%d%d", &n, &k, &x);
  exp_x[0] = 1;
  for (int i = 1; i <= k; i++) exp_x[i] = exp_x[i - 1] * x;
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] | a[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] | a[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max((ans), (pre[i - 1] | suf[i + 1] | (a[i] * exp_x[k])));
  printf("%I64d", ans);
  return 0;
}
