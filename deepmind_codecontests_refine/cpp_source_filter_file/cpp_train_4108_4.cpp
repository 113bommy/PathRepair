#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100010], num[100010], f[100010], mx;
int main() {
  scanf("%d", &n);
  memset(num, 0, sizeof num);
  mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    num[a[i]] += a[i];
    mx = max(mx, a[i]);
  }
  f[0] = 0;
  f[1] = num[1];
  for (int i = 2; i <= mx; i++) {
    f[i] = max(f[i - 2] + num[i], f[i - 1]);
  }
  printf("%lld\n", f[n]);
  return 0;
}
