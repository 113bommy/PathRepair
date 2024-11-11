#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ans = 0;
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d%d", &a, &b);
    int bufk = a + 1;
    long long power = 4;
    while (b > power) {
      power *= 4;
      ++bufk;
    }
    ans = max(ans, bufk);
  }
  printf("%d\n", ans);
  return 0;
}
