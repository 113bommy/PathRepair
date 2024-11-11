#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, a, b, c, d, ans[N];
int main() {
  scanf("%d %d %d %d %d %d", &n, &k, &a, &b, &c, &d);
  if (a + b + c + d <= k) return printf("-1\n"), 0;
  for (int i = 1; i <= n; i++)
    if (i != a && i != b && i != c && i != d) ans[++ans[0]] = i;
  printf("%d %d ", a, c);
  for (int i = 1; i <= n - 4; i++) printf("%d ", ans[i]);
  printf("%d %d\n%d %d ", d, b, c, a);
  for (int i = 1; i <= n - 4; i++) printf("%d ", ans[i]);
  printf("%d %d", b, d);
  return 0;
}
