#include <bits/stdc++.h>
using namespace std;
using namespace std;
int a[302000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int ans = 1, sum = 0, w = 0, r = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] <= a[i - 1]) {
        if (sum >= w) {
          ans++;
          sum = 1;
          w = r;
          r = 1;
        } else
          sum++;
      } else
        r++;
    }
    printf("%d\n", ans);
  }
}
