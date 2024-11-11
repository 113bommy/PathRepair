#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  long long a[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
  if (n == 0) ans = 1;
  while (n) {
    ans += a[n % 16];
    n /= 16;
  }
  cout << ans << endl;
  return 0;
}
