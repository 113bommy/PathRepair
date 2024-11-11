#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << max({a[n - 5] * a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1],
                 a[0] * a[1] * a[n - 3] * a[n - 2] * a[n - 1],
                 a[0] * a[1] * a[2] * a[3] * a[n - 1]})
         << endl;
  }
  return 0;
}
