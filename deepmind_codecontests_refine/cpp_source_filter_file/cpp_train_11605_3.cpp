#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, num1, res;
  int limit = 1000;
  scanf("%d %d", &num, &num1);
  while (limit--) {
    res = num % num1;
    if (res == 0) {
      printf("YES\n");
      return 0;
    }
    num += res;
  }
  printf("NO\n");
  return 0;
}
