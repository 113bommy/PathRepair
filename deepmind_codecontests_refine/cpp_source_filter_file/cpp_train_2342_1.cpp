#include <bits/stdc++.h>
using namespace std;
long long int arr[10000 + 99], arr2[10000 + 99];
int main() {
  long long int n, mins, maxs;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  bool sw = 0;
  if (n % 2 == 0) sw = 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      maxs = abs(arr[0] - arr[n - 1]);
      mins = abs(arr[0] - arr[i + 1]);
    } else if (i == n - 1) {
      maxs = abs(arr[n - 1] - arr[0]);
      mins = abs(arr[n - 1] - arr[i + 1]);
    } else {
      maxs = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
      mins = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    }
    cout << mins << " " << maxs << endl;
  }
  return 0;
}
