#include <bits/stdc++.h>
using namespace std;
int n, a[300010];
int odd[300010], even[300010], ans[300010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans[1] = max(ans[1], a[i]);
  for (int i = 1; i < n; i++) {
    int len = min(i, n - i);
    even[len] = max(even[len], max(a[i], a[i + 1]));
  }
  for (int i = 2; i < n; i++) {
    int len = min(i - 1, n - i);
    odd[len] = max(odd[len], min(a[i], max(a[i - 1], a[i + 1])));
  }
  for (int i = n / 2; i; i--) ans[i << 1] = max(ans[(i + 1) << 1], even[i]);
  for (int i = n / 2; i; i--)
    ans[i << 1 | 1] = max(ans[(i + 1) << 1 | 1], odd[i]);
  for (int i = n; i; i--) printf("%d ", ans[i]);
  return 0;
}
