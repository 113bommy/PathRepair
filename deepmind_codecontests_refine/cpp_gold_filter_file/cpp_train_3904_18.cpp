#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    if (x <= 5 || (n - x + 1) <= 5 || y <= 5 || (m - y + 1) <= 5)
      return printf("YES\n"), 0;
  }
  printf("NO\n");
}
