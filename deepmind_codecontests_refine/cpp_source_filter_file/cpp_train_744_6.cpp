#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, count, sum;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    count = 0;
    for (i = 0; i < n - 1; i++) {
      if (abs(arr[i] - arr[i + 1]) != 1) count++;
    }
    if (abs(arr[0] - arr[n - 1]) != 1) count++;
    if (count == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
