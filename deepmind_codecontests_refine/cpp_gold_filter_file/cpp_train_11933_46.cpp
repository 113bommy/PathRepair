#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans;
  scanf("%d", &ans);
  if (ans == 1) {
    printf("1 1\n1\n");
    return 0;
  }
  printf("%d 2\n", 2 * (ans - 1));
  printf("1 2\n");
}
