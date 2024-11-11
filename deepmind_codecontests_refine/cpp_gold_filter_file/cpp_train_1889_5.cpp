#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long noe = 0;
  long long count = 0;
  for (long long i = n - 1; i >= 0; i--) {
    noe += arr[i] / 2;
    if (arr[i] % 2 == 1 && noe > 0) {
      count++;
      noe--;
    }
  }
  if (noe > 0) {
    count += ((2 * noe) / 3);
  }
  cout << count;
  return 0;
}
