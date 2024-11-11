#include <bits/stdc++.h>
using namespace std;
int n, k, ans[2000001], cnt, ptr, last;
int main() {
  scanf("%d%d", &n, &k);
  last = n - k + 1;
  if (3 * k > n || k == 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j < 3; ++j) ans[++ptr] = i;
    ans[last++] = i;
  }
  for (int i = 2 * k + 1; i <= n - k; ++i) {
    if (cnt > k)
      ans[i] = cnt = 1;
    else
      ans[i] = ++cnt;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}
