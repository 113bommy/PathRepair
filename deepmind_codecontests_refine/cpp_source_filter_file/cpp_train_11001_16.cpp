#include <bits/stdc++.h>
using namespace std;
int n, ans, a[10] = {0, 100, 50, 20, 10, 5, 1};
inline void dfs(register int k) {
  if (n == 0 || k > 6) return;
  ans += n / a[k];
  n %= a[k];
  dfs(k + 1);
}
int main() {
  scanf("%d", &n);
  if (n == 0) return printf("0"), 0;
  dfs(1);
  printf("%d", ans);
}
