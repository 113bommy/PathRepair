#include <bits/stdc++.h>
using namespace std;
int mn(int a, int b) { return (a < b) ? a : b; }
int ara[1000009];
int main() {
  int i, j, k, l, m, n, p, q, cnt;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
  }
  cnt = 1, m = n;
  for (i = n; i >= 1; i--) {
    if (i < m) cnt++;
    p = i - ara[i];
    if (p < 0) p = 0;
    m = mn(m, p);
  }
  printf("%d\n", cnt);
  return 0;
}
