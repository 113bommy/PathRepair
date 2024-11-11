#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int check = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int ngang = min(x, n - x);
    int doc = min(y, m - y);
    if (ngang < 5 || doc < 5) check = 1;
  }
  if (check)
    printf("YES");
  else
    printf("NO");
  return 0;
}
