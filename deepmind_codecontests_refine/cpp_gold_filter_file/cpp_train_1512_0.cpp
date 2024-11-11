#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int i, j, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long sum = 0, ans = 0;
  for (i = 1; i <= n; i++) sum += a[i];
  long long ave = sum / n;
  sort(a + 1, a + n + 1);
  int num = sum % n;
  for (i = n; i > n - num; i--) ans += abs(a[i] - (ave + 1));
  for (i = 1; i <= n - num; i++) ans += abs(ave - a[i]);
  printf("%lld\n", ans / 2);
  return 0;
}
