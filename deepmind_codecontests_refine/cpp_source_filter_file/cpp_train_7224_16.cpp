#include <bits/stdc++.h>
using namespace std;
int n, m, ans, bad[4001], x, y;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    bad[x] = bad[n + y] = 1;
  }
  for (int i = 2; i < n; ++i) {
    if (!bad[i]) ++ans;
    if (!bad[n + i]) ++ans;
  }
  if (n % 2 == 1 && !bad[(n + 1) / 2] && !bad[(n + 1) / 2]) --ans;
  cout << ans;
}
