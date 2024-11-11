#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n < 6)
    puts("-1");
  else {
    printf("1 2\n");
    int a = n / 2 - 1, b = n - 2 - a;
    assert(a >= 2 && b >= 2);
    for (auto i = (0); i < (a); i++) printf("1 %d\n", i + 3);
    for (auto i = (a); i < (a + b); i++) printf("2 %d\n", i + 3);
  }
  for (auto i = (1); i < (n); i++) printf("%d %d\n", i, i + 1);
}
