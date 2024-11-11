#include <bits/stdc++.h>
using namespace std;
long long h[100000], n, p, r;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", h + i), h[i]--;
  for (int i = 1; i <= n; i++) {
    r = (r + min(h[i], h[i - 1]) * p % 1000000007 + h[i]) % 1000000007;
    p = (min(h[i], h[i + 1]) +
         min(h[i], min(h[i - 1], h[i + 1])) * p % 1000000007) %
        1000000007;
  }
  printf("I64d\n", r);
  return 0;
}
