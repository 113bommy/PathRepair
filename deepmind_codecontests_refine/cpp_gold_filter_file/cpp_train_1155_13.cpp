#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    ans += (int64_t)i * (a - 1) + 1;
  }
  printf("%" PRId64 "\n", ans);
  return 0;
}
