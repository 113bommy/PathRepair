#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, k;
  scanf("%d %d %d", &t, &n, &k);
  printf("%d\n", n * (n - 1) / 2);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (k)
        printf("%d %d\n", j, i);
      else
        printf("%d %d\n", i, j);
  return 0;
}
