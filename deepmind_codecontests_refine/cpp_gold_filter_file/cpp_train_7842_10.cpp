#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, b, n, t;
  cin >> k >> b >> n >> t;
  if (k == 1) {
    long long int now = (t - 1) / b;
    cout << max(0ll, n - now) << endl;
    return 0;
  }
  long long int now = 1;
  long long int daaa3 = (t * (k - 1) + b) / (k - 1 + b);
  long long int ans = 0;
  while (1 && n - ans + 1 > 0) {
    if (now > daaa3) {
      ans--;
      break;
    }
    now *= k;
    ans++;
  }
  cout << max(0ll, n - ans) << endl;
}
