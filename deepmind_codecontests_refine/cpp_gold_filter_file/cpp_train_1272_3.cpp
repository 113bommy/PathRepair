#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << arr[0] << endl;
      continue;
    }
    long long prefix[n];
    long long suffix[n];
    prefix[0] = arr[0];
    for (long long i = 1; i < n; i++) {
      prefix[i] = (prefix[i - 1] | arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (long long i = n - 2; i >= 0; i--) {
      suffix[i] = (suffix[i + 1] | arr[i]);
    }
    long long maxi = 0;
    long long idx = -1;
    long long z = 1;
    for (long long i = 0; i <= n - 1; i++) {
      long long ori;
      if (i != 0 && i != n - 1)
        ori = (prefix[i - 1] | suffix[i + 1]);
      else {
        if (i == 0)
          ori = suffix[1];
        else
          ori = prefix[n - 2];
      }
      long long x = arr[i];
      for (long long j = 31; j >= 0; j--) {
        if (ori & (z << j)) {
          x &= ~(z << j);
        }
      }
      if (x >= maxi) {
        maxi = x;
        idx = i;
      }
    }
    cout << arr[idx] << " ";
    for (long long i = 0; i < n; i++) {
      if (i == idx) {
        continue;
      }
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
