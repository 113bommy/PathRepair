#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &k);
  if (k > 36)
    printf("-1");
  else {
    while (k != 0 && k != 1) {
      printf("8");
      k -= 2;
    }
    if (k == 1) printf("9");
  }
  return 0;
}
