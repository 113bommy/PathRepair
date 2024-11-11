#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, x, idx, mn = LLONG_MAX, res;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> x;
    if (n % x < mn) mn = n % x, idx = i, res = n / x;
  }
  cout << idx << ' ' << res << endl;
  return 0;
}
