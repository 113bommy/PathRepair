#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn], nxt[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), nxt[i] = 1e9;
    int ans = 1e9;
    for (int i = n; i >= 1; i--) {
      ans = min(ans, nxt[a[i]] - i + 1);
      nxt[a[i]] = i;
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
