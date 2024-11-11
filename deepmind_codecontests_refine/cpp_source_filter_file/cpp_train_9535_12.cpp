#include <bits/stdc++.h>
using namespace std;
int a[300000 + 10], ans[300000 + 10];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans[1] = max(ans[1], a[i]);
  }
  for (int i = 1; i < n; i++) {
    int len = min(i - 1, n - (i + 1)) * 2 + 2;
    ans[len] = max(ans[len], max(a[i], a[i + 1]));
  }
  for (int i = 2; i < n; i++) {
    int len = min(i - 1, n - (i + 1)) * 2 + 3;
    ans[len] = max(ans[len], min(a[i], max(a[i - 1], a[i + 1])));
  }
  for (int i = n; i > 1; i--) ans[i] = max(ans[i], ans[i + 2]);
  for (int k = 0; k < n; k++) printf("%d ", ans[n - k]);
  return 0;
}
