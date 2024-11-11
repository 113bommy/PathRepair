#include <bits/stdc++.h>
using namespace std;
long long k, b, n, t, p = 1LL;
int solve() {
  for (int i = 0; i < n; ++i) {
    p = p * k + b;
    if (p > t) {
      return n - i;
    }
  }
}
int main() {
  scanf("%d %d %d %d", &k, &b, &n, &t);
  printf("%d\n", solve());
  return 0;
}
