#include <bits/stdc++.h>
using namespace std;
int a[100010];
long long f[100010];
int main() {
  int n;
  long long sum = 0, ans = -2e9, s = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    s += a[i];
    ans = max(ans, s);
    if (s < 0) s = 0;
  }
  printf("%lld", ans * 2 - sum);
  return 0;
}
