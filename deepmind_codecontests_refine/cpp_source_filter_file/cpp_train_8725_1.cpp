#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long zero, two, ans = 0;
int main() {
  cin >> n >> k;
  zero = n / k;
  two = (n + k - 2) / k;
  ans = zero * zero * zero;
  if (k % 2 == 0) ans += two * two * two;
  cout << ans << endl;
  return 0;
}
