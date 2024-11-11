#include <bits/stdc++.h>
using namespace std;
long long n, k, i;
signed main() {
  cin >> n >> k;
  for (i = n / 2; i >= 1; i--) {
    if (n % i == 0) break;
  }
  cout << (n - i) * k - i;
  return 0;
}
