#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, n, i, ans;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> a >> b >> n;
    if (n % a == b)
      cout << n;
    else {
      ans = a * (n / a);
      if (ans + b < n)
        ans += b;
      else
        ans = ((n / a - 1) * a) + b;
      cout << ans << endl;
    }
  }
}
