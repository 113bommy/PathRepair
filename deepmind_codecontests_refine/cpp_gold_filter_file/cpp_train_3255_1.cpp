#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n], v[n];
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      v[i] = arr[i];
      mini = min(mini, arr[i]);
    }
    sort(v, v + n);
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      if (arr[i] != v[i]) {
        if (arr[i] % mini != 0) {
          flag = true;
          break;
        }
      }
    }
    if (flag)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
