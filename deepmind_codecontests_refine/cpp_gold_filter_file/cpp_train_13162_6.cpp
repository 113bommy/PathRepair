#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[200], j, max1 = 0, s, s0 = 0;
  scanf("%d%d", &n, &s);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s0 += a[i];
    if (max1 < a[i]) max1 = a[i];
  }
  if (s0 - max1 > s)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
