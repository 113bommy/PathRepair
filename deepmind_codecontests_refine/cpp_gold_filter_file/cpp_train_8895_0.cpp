#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
int main() {
  long long ans, a, b, k;
  cin >> a >> b;
  ans = 0;
  for (k = 1; k <= a; k++) ans = (ans + (k * b + 1)) % M;
  ans *= b * (b - 1) / 2 % M;
  cout << ans % M;
  return 0;
}
