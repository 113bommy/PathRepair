#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0, str, ctr;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] % 2 == 0)
      sum += arr[i];
    else {
      if (ctr == 0) {
        str = arr[i];
        ctr = 1;
      } else {
        sum += arr[i] + str;
        ctr = 0;
      }
    }
  }
  cout << sum;
  return 0;
}
