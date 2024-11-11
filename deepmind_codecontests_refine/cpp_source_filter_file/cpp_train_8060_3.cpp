#include <bits/stdc++.h>
using namespace std;
int a[109];
bool cmp(int a, int b) { return (a < b); }
int main() {
  int n, m, i;
  i = 0;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n, cmp);
  printf("%d\n", a[m - 1]);
  return 0;
}
