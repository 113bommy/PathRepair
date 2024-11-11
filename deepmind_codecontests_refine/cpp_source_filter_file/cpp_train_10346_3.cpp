#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int ans = -2e9;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    int tmp = 0;
    if (b > k) tmp = b - k;
    tmp += a;
    ans = max(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}
