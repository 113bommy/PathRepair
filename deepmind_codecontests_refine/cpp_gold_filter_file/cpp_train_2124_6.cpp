#include <bits/stdc++.h>
using namespace std;
int n, mt[105][105];
int main() {
  scanf("%d", &n);
  if (n % 2 == 1) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) mt[0][i] = 0;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= n; j++) mt[i][j] = mt[i - 1][j];
    for (int j = i; j <= n - i + 1; j++)
      if (mt[i][i - 1] == 0)
        mt[i][j] = 1;
      else
        mt[i][j] = 0;
  }
  for (int i = n / 2 + 1; i <= n; i++)
    for (int j = 1; j <= n; j++) mt[i][j] = mt[n - i + 1][j];
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (k % 2 == 1)
          if (mt[i][j])
            printf("b");
          else
            printf("w");
        else if (mt[i][j])
          printf("w");
        else
          printf("b");
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
