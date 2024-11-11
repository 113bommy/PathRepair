#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(void) {
  int n, l;
  int ans = 0;
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = l; i <= 100; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++) cur += (a[j] / i);
    cur *= i;
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
