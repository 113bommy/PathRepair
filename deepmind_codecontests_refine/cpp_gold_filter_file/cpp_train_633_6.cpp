#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans;
  cin >> n;
  ans = 0;
  for (int i = 3; i <= n; i++)
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0)
        if (i / j == j)
          ans += 4 * j;
        else
          ans += 4 * j + 4 * i / j;
    }
  cout << ans;
  return 0;
}
