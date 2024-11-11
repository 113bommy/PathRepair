#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10, inf = 1e9 + 10;
const long long INF = 1e18 + 10, mod = 2147493647;
int main() {
  int n;
  scanf("%d", &n);
  int m = (int)sqrt(n) + 0.0001;
  for (int i = m; i >= 1; i--) {
    if (n % i == 0) {
      printf("%d %d\n", i, n / i);
      return 0;
    }
  }
  return 0;
}
