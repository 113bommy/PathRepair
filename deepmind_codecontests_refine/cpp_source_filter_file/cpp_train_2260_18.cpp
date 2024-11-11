#include <bits/stdc++.h>
using namespace std;
int n, a[102];
int main() {
  int ans = 0;
  scanf("%d\n", &n);
  for (int i = 1; i <= 2 * n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= 2 * n; i += 2) {
    for (int j = i + 1; j <= 2 * n; ++j) {
      if (a[i] == a[j]) {
        for (int k = j; k > i + 1; --k) swap(a[k], a[k - 1]);
        ans += j - i - 1;
        break;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
