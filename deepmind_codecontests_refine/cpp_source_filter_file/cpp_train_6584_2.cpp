#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k, i, t, d, f;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k >= n)
      cout << "1"
           << "\n";
    else {
      long long int flag = 0;
      long long int e = INT_MAX;
      for (i = 1; i <= sqrt(n) && i <= k; i++) {
        if (n % i == 0) {
          d = n / i;
          if (d < k) {
            e = min(i, e);
            flag = 1;
          }
        }
      }
      if (flag == 1)
        cout << min(e, d) << "\n";
      else
        cout << d << "\n";
    }
  }
}
