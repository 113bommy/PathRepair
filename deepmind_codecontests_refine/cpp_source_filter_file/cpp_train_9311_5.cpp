#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, a[maxn], pre[maxn], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = a[i] > a[i - 1] ? pre[i - 1] + 1 : 1;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, pre[i] + 1);
    if (a[i - pre[i] + 1] > a[i - pre[i] - 1] + 1 ||
        a[i - pre[i] + 2] > a[i - pre[i]] + 1)
      ans = max(ans, pre[i] + pre[i - pre[i]]);
  }
  printf("%d", ans);
  return 0;
}
