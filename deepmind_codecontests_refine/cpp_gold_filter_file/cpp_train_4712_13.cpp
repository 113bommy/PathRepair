#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  long long n, x;
  while (tc--) {
    cin >> n >> x;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<long long>());
    long long cnt = 0, pn = 1;
    for (long long i = 0; i < n; i++) {
      if (pn * a[i] >= x) {
        cnt++;
        pn = 1;
      } else
        pn++;
    }
    cout << cnt << endl;
  }
}
