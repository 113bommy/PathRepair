#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  if (n == 1 || n == 2) {
    cout << n << endl;
    return 0;
  }
  for (long long int i = 1; i <= (sqrt(n) + 1); i++) {
    if (n % i == 0) ans += 2;
    if (i * i == n) ans = ans - 1;
  }
  cout << ans << endl;
  return 0;
}
