#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 1;
int main() {
  long long n, ans;
  scanf("%lld", &n);
  if (n == 2)
    ans = 1;
  else if (n % 2 == 0)
    ans = 2;
  else {
    ans = -1;
    for (long long i = 2; i * i <= n; i++)
      if (n % i == 0) {
        ans = 3;
        break;
      }
    if (ans == -1)
      ans = 1;
    else {
      for (long long i = 2; i * i <= n - 2; i++)
        if ((n - 2) % i == 0) {
          ans = 2;
          break;
        }
      if (ans == 2)
        ans = 3;
      else
        ans = 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
