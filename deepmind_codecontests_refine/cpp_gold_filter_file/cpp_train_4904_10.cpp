#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf(" %d", &n);
  if (n <= 2) {
    puts("No");
    return 0;
  }
  puts("Yes");
  if (n & 1) {
    printf("2 1 %d\n", n);
    printf("%d ", n - 2);
    for (int i = 2; i < n; i++) printf("%d ", i);
    puts("");
  } else {
    printf("%d\n", n / 2);
    for (int i = 1; i <= n; i++)
      if (i & 1) printf("%d ", i);
    puts("");
    printf("%d\n", n / 2);
    for (int i = 1; i <= n; i++)
      if (!(i & 1)) printf("%d ", i);
    puts("");
  }
}
