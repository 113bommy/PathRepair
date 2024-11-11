#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n;
  long long k, b, t;
  long long res = 1;
  cin >> k >> b >> n >> t;
  for (i = 1;; ++i) {
    if (res == t) break;
    res = res * k + b;
    if (res > t) break;
  }
  printf("%d\n", max(n - i + 1, 0));
  return 0;
}
