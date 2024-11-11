#include <bits/stdc++.h>
using namespace std;
int n;
int deg[100005];
int leaves[100005], comv[100005];
int nleaf = 0, ncomv = 0;
int x, y;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    deg[x]++, deg[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1)
      leaves[++nleaf] = i;
    else if (deg[i] > 2)
      comv[++ncomv] = i;
  }
  if (ncomv > 1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  if (ncomv == 0)
    printf("1\n%d %d\n", leaves[1], leaves[2]);
  else {
    printf("%d\n", leaves);
    for (int i = 1; i <= nleaf; i++) {
      printf("%d %d\n", comv[1], leaves[i]);
    }
  }
  return 0;
}
