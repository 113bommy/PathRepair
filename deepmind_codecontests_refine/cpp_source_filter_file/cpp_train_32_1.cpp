#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  printf("%d\n", (n * y / 100 + ((n * y % 100) ? 1 : 0)) - x);
}
