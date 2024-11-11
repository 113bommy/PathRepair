#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%d", &x);
  int ans = 0;
  while (n--) {
    int t;
    scanf("%d", &t);
    ans += t;
    if (n <= k) {
      ans = ans - t + x;
    }
  }
  printf("%d", ans);
  return 0;
}
