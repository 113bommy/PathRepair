#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0;
    for (; i < n - 1; i++) {
      if (arr[i] + m >= arr[i + 1] - k) {
        m += (arr[i] - arr[i + 1] + k);
      } else {
        break;
      }
    }
    if (i == n - 1) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
