#include <bits/stdc++.h>
using namespace std;
int ans, i, n, a[2000000], s;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  for (i = 1; i <= n; i++)
    if ((s - a[i]) % 2 == 0) ans++;
  printf("%d", ans);
  return 0;
}
