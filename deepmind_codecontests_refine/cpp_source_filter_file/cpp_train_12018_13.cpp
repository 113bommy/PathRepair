#include <bits/stdc++.h>
using namespace std;
int ar[100005];
int main() {
  int n, i, j, x, k, p;
  scanf("%d", &n);
  p = 1;
  memset(ar, -1, sizeof(ar));
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &k);
    if (x > 0) {
      if (ar[k] != x - 1) p = 0;
    }
    if (ar[k] < x) ar[k] = x;
  }
  if (p == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
