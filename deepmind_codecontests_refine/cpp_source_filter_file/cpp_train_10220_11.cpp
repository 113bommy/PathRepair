#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, i;
  long long int k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    int arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    if ((arr[n - 1] - arr[0]) > 2 * k) {
      cout << "-1"
           << "\n";
    } else {
      cout << arr[0] + k;
    }
  }
  return 0;
}
