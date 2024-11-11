#include <bits/stdc++.h>
using namespace std;
int a[205];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n + n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n + n; i += 2) {
    if (a[i] == a[i + 1]) continue;
    for (int j = i + 1; j <= n + n; j++) {
      if (a[i] == a[j]) {
        for (int k = j - 1; k >= i + 1; k--) {
          swap(a[k], a[k + 1]);
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
}
