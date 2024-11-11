#include <bits/stdc++.h>
using namespace std;
const int maxn = 4 * 1e5 + 10;
int n, ans, a[maxn], cur;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (a[n])
    while (a[++cur] && cur < n) a[cur + n] = 1;
  n = n + cur - 1;
  int k;
  for (int i = 1; i <= n; i++) {
    if (a[i])
      k++;
    else
      k = 0;
    ans = max(ans, k);
  }
  printf("%d", ans);
}
