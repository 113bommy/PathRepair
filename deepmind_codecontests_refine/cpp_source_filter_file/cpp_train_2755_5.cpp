#include <bits/stdc++.h>
using namespace std;
int a[103], b[103];
int n;
int main() {
  int ans = 10000;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    b[i] = a[i + 1] - a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int p = -10000;
    for (int j = 1; j <= n - 1; j++) {
      if (j == i) {
        p = max(b[j] + b[j + 1], p);
      }
      if (j == i + 1) continue;
      p = max(b[j], p);
    }
    ans = min(p, ans);
  }
  printf("%d\n", ans);
}
