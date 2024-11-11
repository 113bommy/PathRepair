#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, t, d = 0, min = 0;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> s >> t;
  if (s != t) {
    if (s < t) {
      for (long long i = s - 1; i < t - 1; i++) {
        d += arr[i];
      }
      if (s != 1) {
        for (long long i = 0; i < s; i++) {
          min += arr[i];
        }
      }
      for (long long i = n - 1; i >= t - 1; i--) {
        min += arr[i];
      }
      if (min < d) {
        d = min;
      }
    } else {
      for (long long i = t - 1; i < s - 1; i++) {
        d += arr[i];
      }
      if (t != 1) {
        for (long long i = 0; i < t; i++) {
          min += arr[i];
        }
      }
      for (long long i = n - 1; i >= s - 1; i--) {
        min += arr[i];
      }
      if (min < d) {
        d = min;
      }
    }
  }
  cout << d << endl;
  return 0;
}
