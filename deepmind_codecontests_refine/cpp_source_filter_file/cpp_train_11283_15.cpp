#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, y, sum = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d %d", &x, &y), sum += y - x + 1;
  printf("%d\n", k - sum % k);
  return 0;
}
