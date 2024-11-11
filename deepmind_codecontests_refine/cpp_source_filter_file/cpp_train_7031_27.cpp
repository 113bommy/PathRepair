#include <bits/stdc++.h>
using namespace std;
int main() {
  int mn = 1000000000, x;
  for (int i = 0; i < 4; ++i) scanf("%d", &x), mn = min(mn, x);
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", max(0, min(b, mn) - max(0, a)));
  return 0;
}
