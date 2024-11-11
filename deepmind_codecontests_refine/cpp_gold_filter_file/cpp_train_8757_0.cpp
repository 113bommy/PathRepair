#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  map<long long int, long long int> m;
  long long int ne[n];
  for (int i = n - 1; i >= 0; i--) {
    if (m[a[i]] == 0) {
      ne[i] = -1;
      m[a[i]] = i;
    } else {
      ne[i] = m[a[i]];
    }
  }
  long long int ans = 1;
  long long int k = -1;
  for (int i = 0; i < n; i++) {
    if (i >= k) {
      k = -1;
    }
    k = max(k, ne[i]);
    if (k == -1 && i < n - 1) {
      ans = (ans % 998244353 * 2) % 998244353;
    }
  }
  cout << ans << endl;
}
