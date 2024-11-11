#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", a >= 31 ? b : b % (a << 1));
  return 0;
}
