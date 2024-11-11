#include <bits/stdc++.h>
using namespace std;
int n, sum;
int main() {
  scanf("%d", &n);
  int i = 1;
  while (n >= i) {
    n -= i;
    i *= 2;
    sum++;
  }
  if (n != 0) sum++;
  printf("%d\n", sum);
}
