#include <bits/stdc++.h>
using namespace std;
int n, a[5], b[5] = {1, 1, 2, 7, 4}, ans;
int main() {
  int i;
  for (i = 0, ans = 0x7fffffff; i < n; i++) {
    scanf("%d", a + i);
    ans = min(ans, a[i] / b[i]);
  }
  printf("%d\n", ans);
  return 0;
}
