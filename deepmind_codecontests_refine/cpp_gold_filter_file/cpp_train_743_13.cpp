#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, k, t;
  cin >> n >> k >> m >> t;
  while (t--) {
    long long int a, i;
    cin >> a >> i;
    if (a == 0) {
      if (i < k)
        n -= i, k -= i;
      else
        n = i;
    } else {
      n++;
      if (i <= k) k++;
    }
    cout << n << " " << k;
    cout << "\n";
  }
}
