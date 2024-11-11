#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-9;
int main() {
  int n, i, j, m;
  scanf("%d", &n);
  printf("%d\n", n / 3 * 2 + (n % 3 == 1));
  return 0;
}
