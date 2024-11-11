#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  int i, j;
  int best = 1000000;
  int x, y;
  for (i = 0; i < k; i++) {
    scanf("%d %d", &x, &y);
    best = min(best, min(x - 1, min(n - x, min(y - 1, m - y))));
  }
  if (best <= 4)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
