#include <bits/stdc++.h>
using namespace std;
int t[100010];
int main() {
  int n, ans;
  while (scanf("%d", &n) > 0) {
    ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    for (int i = n - 1; i >= 1; i--) {
      if (t[i] > t[i + 1]) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
