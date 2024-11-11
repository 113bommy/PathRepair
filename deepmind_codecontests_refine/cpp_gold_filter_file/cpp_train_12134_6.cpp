#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int d = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  a[0] = 1000000007;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[i - 1]) {
      ++d;
    } else
      d = 1;
    ans = max(ans, d);
  }
  printf("%d\n", ans);
  return 0;
}
