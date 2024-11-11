#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int m = unique(a + 1, a + 1 + n) - a - 1;
  if (!a[1]) m--;
  printf("%d\n", m);
  return 0;
}
