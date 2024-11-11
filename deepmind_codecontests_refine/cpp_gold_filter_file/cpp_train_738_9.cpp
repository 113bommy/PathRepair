#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, m, c = 0, ans = 0;
  cin >> n;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      c = 0;
      for (j = 2; j <= sqrt(i); j++) {
        if (i % j == 0) {
          c = 1;
          break;
        } else
          c = 0;
      }
      if (c == 0) {
        ans = 1;
        n -= i;
        break;
      }
    }
  }
  if (ans == 0)
    ans = 1;
  else
    ans += (n / 2);
  cout << ans << endl;
  return 0;
}
