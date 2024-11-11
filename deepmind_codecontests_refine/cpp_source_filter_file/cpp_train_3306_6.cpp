#include <bits/stdc++.h>
using namespace std;
const long long int N = 100005;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long int i, j = 1e10, k = 0, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    long long int a[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] -= i;
      if (a[i] <= i) {
        cout << i + 1;
        return 0;
      } else {
        m = ceil(a[i] / n);
        if (i + m * n < j) {
          j = i + m * n;
          k = i;
        }
      }
    }
    cout << k;
  }
}
