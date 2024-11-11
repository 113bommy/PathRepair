#include <bits/stdc++.h>
using namespace std;
int n, a[100007];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  ans += a[0] + 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] <= a[i]) {
      ans += (a[i] - a[i - 1]) + 2;
    } else
      ans += (a[i - 1] - a[i]) + a[i] + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
