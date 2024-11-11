#include <bits/stdc++.h>
using namespace std;
bool is_powertwo(long long n) {
  long long count = 0;
  while (n) {
    if ((n & 1) > 0) count++;
    n = n >> 1;
  }
  if (count == 1) return true;
  return false;
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long maxm = 1;
    long long l = 0;
    long long r = 1;
    while (r < n) {
      if (arr[r] - arr[l] <= 5)
        r++;
      else {
        l++;
        r++;
      }
      maxm = max(maxm, r - l);
    }
    cout << maxm << endl;
  }
  return 0;
}
