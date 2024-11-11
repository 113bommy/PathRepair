#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long k = 0;
  long long ans = 1;
  long long p = 3;
  while (p < n) {
    if (p % n) ans = max(ans, n / p + 1);
    p *= 3ll;
  }
  cout << ans;
  return 0;
}
