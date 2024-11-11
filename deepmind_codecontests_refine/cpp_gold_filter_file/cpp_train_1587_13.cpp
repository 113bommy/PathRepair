#include <bits/stdc++.h>
using namespace std;
int ans[500005];
bool vis[500005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) ans[i] = 0x3f3f3f3f;
  int p = n;
  int k = n / 2 + 1;
  int nowcnt = n;
  while (k > 0) {
    for (int j = 2 * k; j <= n; j += k) {
      if (!vis[j]) vis[j] = 1, nowcnt--;
    }
    k--;
    ans[nowcnt] = k;
  }
  for (int i = n - 1; i >= 2; i--) {
    ans[i] = min(ans[i], ans[i + 1]);
  }
  for (int i = 2; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
