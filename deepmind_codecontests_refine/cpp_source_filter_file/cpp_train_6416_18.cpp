#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int r = n % 10;
  if (r <= 5)
    n = n - r;
  else
    n = n + r - 10;
  printf("%d\n", n);
  return 0;
}
