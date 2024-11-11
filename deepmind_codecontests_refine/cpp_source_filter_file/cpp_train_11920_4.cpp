#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  long long i1, i2, z = 0, y = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (a[i] != i) {
      i1 = i;
      break;
    }
  }
  for (long long i = n; i >= 1; i--)
    if (a[i] != i) {
      i2 = i;
      break;
    }
  for (long long i = i1; i < i2; i++)
    if (a[i] - a[i + 1] != 1) {
      cout << 0 << " " << 0;
      return 0;
    }
  cout << i1 << " " << i2;
}
