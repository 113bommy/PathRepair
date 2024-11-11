#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << "1";
    return 0;
  }
  long long maxi = 2;
  long long counting = 2;
  for (long long i = 2; i < n; i++) {
    if (arr[i] == arr[i - 1] + arr[i - 2])
      counting++;
    else {
      counting = 2;
    }
    maxi = max(maxi, counting);
  }
  cout << maxi;
}
