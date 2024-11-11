#include <bits/stdc++.h>
using namespace std;
char pet[] = "4 5 2\n1 3 6\n1 2 6\n2 4 4\n3 4\n3 5\n";
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5)
    printf("%s\n", pet);
  else {
    for (int i = 0; i < n / 2; ++i)
      printf("%d %d %d\n", i + 1, i + (n / 2) + 1, 1);
    for (int i = n / 2; i < n - 1; ++i)
      printf("%d %d %d\n", i + 1, i + 2, 2 * (i + 1 - n / 2) - 1);
    for (int i = 1; i < n / 2; ++i) printf("%d %d\n", i, i + 1);
    printf("1 3\n");
  }
  return 0;
}
