#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    long long f = -1;
    for (long long i = 3; i <= 18000; i++) {
      if (i * n % 180 == 0 && i * n / 180 <= i - 2) {
        f = i;
        break;
      }
    }
    printf("%lld\n", f);
  }
  return 0;
}
