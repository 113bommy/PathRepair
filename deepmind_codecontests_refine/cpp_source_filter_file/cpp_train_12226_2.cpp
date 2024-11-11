#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF)
    if (k >= n)
      printf("-1\n");
    else {
      printf("%d\n", n * k);
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) printf("%d %d\n", i, (i + j - 1) % n + 1);
    }
  return 0;
}
