#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if (n == 1) {
      printf("%lld\n", 0);
      continue;
    }
    if (n == 2) {
      printf("%lld\n", m);
      continue;
    }
    printf("%lld\n", 2 * m);
  }
  return 0;
}
