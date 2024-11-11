#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d", &n);
  if (n & 1)
    m = (n + 1) / 2;
  else
    m = (n + 2) / 2;
  printf("%d\n", m);
  for (int i = 1; i <= m; i++) printf("%d %d\n", i, 1);
  for (int i = 2; i + m - 1 <= n; i++) printf("%d %d\n", m, i);
}
