#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n == k)
    printf("%d\n", 3 * k);
  else
    printf("%d\n", 3 * n + min(n - k, k - 1));
  return 0;
}
