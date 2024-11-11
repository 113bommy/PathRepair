#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005], ans, b[500005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  int now = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] != a[i - 1])
      now++;
    else if (now > 1) {
      if (now & 1) {
        for (int j = i - now; j < i; j++) b[j] = a[i];
      } else {
        for (int j = i - now; j < i - now / 2; j++) b[j] = a[i] ^ 1;
        for (int j = i - now / 2; j < i; j++) b[j] = a[i];
      }
      ans = max(ans, (now - 1) / 2), now = 1;
    }
  if (now > 1) {
    if (now & 1) {
      for (int j = n - now + 1; j <= n; j++) b[j] = a[n];
    } else {
      for (int j = n - now + 1; j <= n - now / 2; j++) b[j] = a[n] ^ 1;
      for (int j = n - now / 2 + 1; j <= n; j++) b[j] = a[n];
    }
    ans = max(ans, (now - 1) / 2), now = 1;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d%c", b[i], i < n ? ' ' : '\n');
  return 0;
}
