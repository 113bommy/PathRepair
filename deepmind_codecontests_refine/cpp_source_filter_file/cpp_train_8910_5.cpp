#include <bits/stdc++.h>
using namespace std;
int main() {
  int p[200001], i, j, n, k, rem, ans;
  scanf("%d%d", &n, &k);
  p[1] = 1;
  for (i = 2; i <= k + 1; i++) p[i] = 1;
  for (i = k + 2; i <= n; i++) p[i] = i - k;
  ans = (n - 1) / k;
  ans *= 2;
  if ((n - 1) % k == 1) ans++;
  if ((n - 1) % k == 2) ans += 2;
  printf("%d\n", ans);
  for (i = 2; i <= n; i++) {
    printf("%d %d\n", i, p[i]);
  }
  return 0;
}
