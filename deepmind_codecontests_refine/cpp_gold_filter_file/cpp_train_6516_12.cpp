#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i % 4 == 1 || i % 4 == 2)
      printf("b");
    else
      printf("a");
  }
  return 0;
}
