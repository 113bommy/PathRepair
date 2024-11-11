#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      ans += (int)(((double)k - 0.5 - (double)x) * 2);
    }
    printf("%d\n", max(ans, 0));
  }
  return 0;
}
