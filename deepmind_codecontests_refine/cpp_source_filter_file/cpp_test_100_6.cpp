#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10;
int T;
int a[maxn], n, ans;
int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    memset(a, 0, sizeof(a));
    ans = -1e8;
    cin >> n;
    for (int j = 1; j <= n; j++) scanf("%d", &a[j]);
    sort(a + 1, a + n + 1);
    for (int j = 1; j <= n; j++) ans = max(a[j] - a[j - 1], ans);
    printf("%d\n", ans);
  }
  return 0;
}
