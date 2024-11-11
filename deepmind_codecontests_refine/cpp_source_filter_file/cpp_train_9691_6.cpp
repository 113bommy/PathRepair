#include <bits/stdc++.h>
using namespace std;
long long x[100000], c = 2, d;
int main() {
  int n;
  scanf("%d%lld\n", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (d >= 1) {
      if (x[i + 1] - x[i] == 2 * d) {
        c++;
      } else if (x[i + 1] - x[i] > 2 * d) {
        c = c + 2;
      }
    } else {
      c = 0;
    }
  }
  printf("%lld\n", c);
  return 0;
}
