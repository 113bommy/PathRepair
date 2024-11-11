#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (n < k || (k == 1 && n > 1))
    printf("-1\n");
  else {
    int p = 1;
    for (int i = 1; i <= n - max(k - 2, 0); i++)
      if (i % 2)
        printf("a");
      else
        printf("b"), p = 2;
    for (int i = p; i < k; i++) printf("%c", 'a' + i);
    printf("\n");
  }
  return 0;
}
