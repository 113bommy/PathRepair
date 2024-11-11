#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int t, n, k, ans = 0, ans1 = 0;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> k;
    ans = 0;
    while (n) {
      ans = ans + (n % k);
      n = n / k;
      ans++;
    }
    cout << ans - 1 << endl;
  }
}
