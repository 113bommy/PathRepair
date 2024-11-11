#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main() {
  scanf("%d %d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1)
    ans = m;
  else if (n == 2) {
    if (m % 4 == 0)
      ans = 4 * (m / 4);
    else
      ans = 4 * ((m / 4) + 1);
    if (m % 4 == 1) ans -= 2;
  } else
    ans = ((n * m) % 2 == 0) ? (n * m) / 2 : ((n * m) / 2) + 1;
  printf("%d", ans);
}
