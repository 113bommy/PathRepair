#include <bits/stdc++.h>
using namespace std;
long long int n, mn = 0, mx = 0, i;
int main() {
  cin >> n;
  int arr[100000];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n; i++) {
    if (i == 0) {
      mx = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
      mn = abs(arr[i] - arr[i + 1]);
      cout << mn << " " << mx << endl;
    } else if (i == n - 1) {
      mx = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
      mn = abs(arr[i] - arr[i - 1]);
      cout << mn << " " << mx << endl;
    } else {
      mx = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
      mn = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
      cout << mn << " " << mx << endl;
    }
  }
  return 0;
}
