#include <bits/stdc++.h>
using namespace std;
int n, x = 10000000, k;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    x = min(x, k);
  }
  if (x == 1)
    printf("-1");
  else
    printf("%d", x);
  return 0;
}
