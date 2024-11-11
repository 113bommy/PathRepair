#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    puts("1 2 4\n2 3 2\n1 4 1");
    puts("4 5 3\n3 4\n3 5\n");
    return 0;
  }
  int md = n / 2;
  for (int i = 1; i <= md; i++) printf("%d %d %d\n", i, i + md, 1);
  for (int i = md + 1; i < n; i++)
    printf("%d %d %d\n", i, i + 1, 2 * (i - md) - 1);
  for (int i = 1; i < md; i++) printf("%d %d\n", i, i + 1);
  puts("1 3");
}
