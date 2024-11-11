#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a > b) {
    swap(a, b);
  }
  b = (b - a) / 2;
  printf("%d%d\n", a, b);
  return 0;
}
