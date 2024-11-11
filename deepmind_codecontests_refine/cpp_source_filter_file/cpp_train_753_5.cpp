#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    map<long long, long long> m;
    long long d = *max_element(arr, arr + n);
    m[d]++;
    while (m[d] == 1) {
      for (int i = 0; i < n; i++) {
        long long a = d - arr[i];
        arr[i] = a;
      }
      k--;
      if (k == 0) break;
      d = *max_element(arr, arr + n);
      m[d]++;
    }
    if (k & 1 && k != 0) {
      for (int i = 0; i < n; i++) cout << 0ll + d - arr[i] << " ";
    } else {
      for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    cout << "\n";
  }
}
