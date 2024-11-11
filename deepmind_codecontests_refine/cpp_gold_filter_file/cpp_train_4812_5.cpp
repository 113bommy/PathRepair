#include <bits/stdc++.h>
using namespace std;
const int maxn = 3500 + 100;
int a[maxn], n, m, k, T;
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int ans1, ans2 = 0;
    k = min(k, m - 1);
    for (int l = 0; l <= k; l++) {
      int r = l + n - k - 1;
      ans1 = 1e9 + 7;
      for (int i = 0; i < m - k; i++) {
        int ll = l + i, rr = r - (m - k) + 1 + i;
        ans1 = min(ans1, max(a[ll], a[rr]));
      }
      ans2 = max(ans1, ans2);
    }
    printf("%d\n", ans2);
  }
}
