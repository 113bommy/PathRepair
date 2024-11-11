#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 5) {
    puts("1 3 3\n1 2 3\n2 4 2\n4 5 1");
    puts("3 4");
    puts("3 5");
    return 0;
  }
  for (int(i) = (1); (i) <= (n / 2); (i)++) printf("%d %d 1\n", i, i + n / 2);
  for (int(i) = (n / 2 + 1); (i) <= (n - 1); (i)++)
    printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
  puts("1 3");
  for (int(i) = (1); (i) <= (n / 2 - 1); (i)++) printf("%d %d\n", i, i + 1);
}
