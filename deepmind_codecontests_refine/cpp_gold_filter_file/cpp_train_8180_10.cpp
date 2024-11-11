#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 4 > 1)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = n % 4; i < n; i += 4) {
      for (int k = 1; k < 4; k += 2) {
        for (int j = 1; j <= i; ++j) printf("%d %d\n", j, i + k);
        printf("%d %d\n", i + k, i + k + 1);
        for (int j = i; j >= 1; --j) printf("%d %d\n", j, i + k + 1);
      }
      printf("%d %d\n", i + 1, i + 3);
      printf("%d %d\n", i + 2, i + 4);
      printf("%d %d\n", i + 1, i + 4);
      printf("%d %d\n", i + 2, i + 3);
    }
  }
  return 0;
}
