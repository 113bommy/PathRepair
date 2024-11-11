#include <bits/stdc++.h>
using namespace std;
int n, s[105], c[105];
int main() {
  memset(c, 0, sizeof(c));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= s[i]; j++) {
      int k;
      scanf("%d", &k);
      c[i] += 15 + 5 * k;
    }
    if (c[i] < c[ans]) ans = i;
  }
  printf("%d\n", c[ans]);
  return 0;
}
