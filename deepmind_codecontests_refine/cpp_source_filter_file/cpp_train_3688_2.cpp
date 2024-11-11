#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, s, q, w;
  int a[101];
  scanf("%d", &n);
  for (i = 1; i < n; i++) scanf("%d", &a[i]);
  scanf("%d%d", &q, &w);
  s = 0;
  for (i = 1; i < w; i++) s += a[i];
  printf("%d\n", s);
  return 0;
}
