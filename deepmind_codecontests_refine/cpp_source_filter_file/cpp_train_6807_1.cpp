#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2) {
    printf("0");
    for (int i = 1; i < n; i++) printf("%d", i);
    printf("\n0");
    for (int i = 1; i < n; i++) printf("%d", i);
    printf("\n0");
    for (int i = 1; i < n; i++) printf("%d", (i << 1) % n);
    puts("");
  } else
    puts("-1");
  return 0;
}
