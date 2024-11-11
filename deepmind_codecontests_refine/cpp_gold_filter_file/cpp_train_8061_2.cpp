#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001], n, m;
long long int foo(long long int k) {
  long long int i, ret = 0;
  for (i = 0; i < n; i++) {
    if (a[i] < k) ret += (k - a[i]);
  }
  for (i = 0; i < m; i++) {
    if (b[i] > k) ret += (b[i] - k);
  }
  return ret;
}
int main() {
  long long int i, low, high, mid1, mid2, val1, val2, ans = 200000000000000000,
                                                      cnt = 100;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  low = 1;
  high = 1000000001;
  while (cnt--) {
    mid1 = low + (high - low) / 3;
    mid2 = low + 2 * (high - low) / 3;
    val1 = foo(mid1);
    val2 = foo(mid2);
    if (val1 <= val2) {
      high = mid2;
    } else {
      low = mid1;
    }
    ans = min(min(val1, val2), ans);
  }
  cout << ans << endl;
  return 0;
}
