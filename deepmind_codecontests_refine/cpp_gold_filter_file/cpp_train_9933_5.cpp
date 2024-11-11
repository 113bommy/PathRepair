#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, n, m, k, t, l, d, p, nl, np;
  t = 1;
  while (t--) {
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (k == 1) {
      cout << min_element(arr.begin(), arr.end()) - arr.begin() + 1;
    } else {
      for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
      long long small = arr[k - 1];
      long long ans = 0;
      for (int i = k; i < n; i++) {
        if (arr[i] - arr[i - k] < small) {
          small = arr[i] - arr[i - k];
          ans = i - k + 1;
        }
      }
      cout << ans + 1 << endl;
    }
  }
}
