#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = (sqrt(4 * n + 1) - 1);
  x /= 2;
  long long ans;
  if (x * (x + 1) == n) {
    ans = (2 * x + 1);
  } else {
    long long temp = (x * (x + 1));
    x += 1;
    if (n > (temp + x)) {
      ans = (2 * x + 1);
    } else {
      ans = 2 * x;
    }
  }
  cout << ans;
  return 0;
}
