#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= (n + m) / 3 && n - 2 * i >= 0 && m - i > 0; i++) {
    ans = max(ans, i + min(n - 2 * i, (m - i) / 2));
  }
  printf("%d", ans);
  return 0;
}
