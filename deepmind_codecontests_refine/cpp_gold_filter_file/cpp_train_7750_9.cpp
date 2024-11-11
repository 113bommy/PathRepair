#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  int d, ce, cha;
  scanf("%d%d", &n, &s);
  s *= 100;
  int maxn = -1;
  int m = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &d, &ce);
    int cost = d * 100 + ce;
    if (cost > s) {
      m++;
    }
    cha = (s - cost) % 100;
    if (cha > maxn) maxn = cha;
  }
  if (m == n)
    printf("-1\n");
  else
    printf("%d\n", maxn);
  return 0;
}
