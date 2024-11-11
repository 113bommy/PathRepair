#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m <= n / k)
      cout << m << "\n";
    else {
      long long int x = n / k;
      m -= x;
      k -= 1;
      if (m % k == 0) {
        cout << x - (m / k) << "\n";
      } else {
        cout << x - (m / k + m % k) << "\n";
      }
    }
  }
}
