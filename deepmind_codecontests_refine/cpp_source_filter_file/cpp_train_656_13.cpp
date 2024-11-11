#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, a, res;
  while (scanf("%d ", &a) == 1) {
    res += a * i;
    i++;
  }
  printf("%d\n", res);
  return 0;
}
