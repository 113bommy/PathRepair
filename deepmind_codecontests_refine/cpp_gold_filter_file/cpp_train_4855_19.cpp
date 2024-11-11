#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1, j = 1; i <= n; i <<= 2, i |= (1 << j), ++j)
    if (n % i == 0) ans = i;
  printf("%d", ans);
}
