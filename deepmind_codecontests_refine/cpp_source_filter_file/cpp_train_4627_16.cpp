#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, l = 0, r = 1e9, sum = 0, ans = 0, x, z;
  cin >> n >> x;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ans = x;
  for (int i = 0; i < n; i++) {
    l = 0;
    r = x;
    for (int j = i; j < n; j++) {
      l = max(l, a[j]);
    }
    z = r / a[i];
    r = r % a[i] + z * l;
    ans = max(ans, r);
  }
  cout << x;
  return 0;
}
