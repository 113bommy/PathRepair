#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<long long int> left(n, 0);
  vector<long long int> right(n, 0);
  for (long long int i = 0; i < n; ++i) {
    if (i == 0 || v[i] <= v[i - 1]) {
      left[i] = 1;
    } else {
      left[i] = 1 + left[i - 1];
    }
  }
  for (long long int i = n - 1; i >= 0; --i) {
    if (i == n - 1 || v[i] >= v[i + 1]) {
      right[i] = 1;
    } else {
      right[i] = 1 + right[i + 1];
    }
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; ++i) {
    ans = max(ans, left[i]);
    ans = max(ans, right[i]);
  }
  if (ans < n) ans++;
  for (long long int pos = 1; pos <= n - 2; ++pos) {
    if (v[pos + 1] - v[pos - 1] >= 2) {
      ans = max(ans, 1 + left[pos - 1] + right[pos + 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
