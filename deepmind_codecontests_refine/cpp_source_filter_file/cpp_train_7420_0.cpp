#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main() {
  scanf("%d%d", &n, &m);
  ans = ((m - 1) / 3 + 1) * n;
  ans = max(ans, ((n - 1) / 3 + 1) * m);
  if ((n * m) & 1)
    ans = max(ans, n * m / 2 + 1);
  else
    ans = max(ans, n * m / 2);
  if (n == 2 || m == 2) {
    if (n != 2) swap(n, m);
    int tmp = m / 4 * 4;
    if (m % 4 > 1)
      tmp += 4;
    else if (m % 4 == 0)
      tmp += 2;
    ans = max(ans, tmp);
  }
  printf("%d", ans);
}
