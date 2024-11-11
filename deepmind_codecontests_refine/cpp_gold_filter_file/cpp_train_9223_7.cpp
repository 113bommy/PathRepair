#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  int n;
  cin >> n;
  while (n--) {
    scanf("%I64d%I64d", &a, &b);
    long long l = 1, r = 1e6, res = -1;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (m * m * m <= a * b) {
        if (m * m * m == a * b) res = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    if (res != -1 && a % res == 0 && b % res == 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
