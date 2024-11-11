#include <bits/stdc++.h>
using namespace std;
int num[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int main() {
  int n;
  scanf("%d", &n);
  if (n > 18 * 2)
    printf("-1\n");
  else {
    for (int i = 0; i < n / 2; i++) printf("8");
    if (n % 2 == 0)
      printf("\n");
    else
      printf("0\n");
  }
  return 0;
}
