#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    puts("1 2 3");
    puts("1 3 3");
    puts("2 4 2");
    puts("4 5 1");
    puts("3 4");
    puts("3 5");
  } else {
    for (int i = 1; i <= n / 2; i++) printf("%d %d %d\n", i, i + n / 2, 1);
    int wt = 1;
    for (int i = n / 2 + 1; i <= n; i++, wt += 2)
      printf("%d %d %d\n", i, i + 1, wt);
    for (int i = 1; i < n / 2; i++) printf("%d %d\n", i, i + 1);
    printf("%d %d\n", 1, 3);
  }
  return 0;
}
