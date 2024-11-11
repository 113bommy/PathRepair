#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[1001];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int ans = 0, minn = 0x7fffffff, mini;
    for (register int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (minn > a[i]) {
        minn = a[i];
        mini = i;
      }
    }
    for (register int i = 1; i <= n; ++i)
      if (i != mini) ans += (k - a[i]) / mini;
    printf("%d\n", ans);
  }
  return 0;
}
