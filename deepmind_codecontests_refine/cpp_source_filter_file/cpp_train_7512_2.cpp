#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1, i;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    if (n == 1)
      cout << arr[0] << endl;
    else {
      int diff[n - 1];
      for (i = 1; i < n; i++) diff[i - 1] = arr[i] - arr[i - 1];
      sort(diff, diff + n - 1);
      int p = n - k, sum = 0;
      for (i = 0; i < p; i++) sum += diff[i];
      cout << sum << endl;
    }
  }
}
