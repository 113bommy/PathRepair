#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int res0, ans = 0;
  int res;
  res = n * k;
  int z = 1000000000;
  for (int i = 1; i <= k; i++) {
    if (n % i == 0) {
      ans = (res / i) + i;
      res0 = (ans / k) * (ans % k);
      if (res0 == n) {
        z = min(z, ans);
      }
    }
  }
  cout << z;
}
