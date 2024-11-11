#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  double r = 0;
  if (n % 2 == 0) {
    for (int i = 1; i < n; i += 2) {
      r += (arr[i] * arr[i] - arr[i - 1] * arr[i - 1]);
    }
  } else {
    r = arr[0];
    for (int i = 2; i < n; i += 2) {
      r += arr[i] * arr[i] - arr[i - 1] * arr[i - 1];
    }
  }
  cout << fixed << setprecision(9) << r * 3.1415926536;
  return 0;
}
