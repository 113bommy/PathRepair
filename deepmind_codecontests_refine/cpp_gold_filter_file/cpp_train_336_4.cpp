#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int f = 1, f1 = 1;
  for (long long int i = 1; i <= n; i++) {
    f *= i;
    f %= (1000000007);
  }
  for (long long int i = 1; i < n; i++) {
    f1 *= 2;
    f1 %= (1000000007);
  }
  long long int ans = (f - f1);
  if (ans < 0) ans += (1000000007);
  cout << ans << endl;
}
