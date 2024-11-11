#include <bits/stdc++.h>
using namespace std;
long long a[105];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (long long i = n; i >= 1; i--) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
