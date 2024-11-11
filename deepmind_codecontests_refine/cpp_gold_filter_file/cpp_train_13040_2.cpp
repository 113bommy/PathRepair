#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, min1, min2, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    long long arr1[n];
    long long arr2[n];
    for (long long c = 0; c < n; c++) {
      cin >> arr1[c];
    }
    for (long long d = 0; d < n; d++) {
      cin >> arr2[d];
    }
    min1 = arr1[0];
    for (long long i = 0; i < n; i++) {
      if (min1 > arr1[i]) {
        min1 = arr1[i];
      }
    }
    min2 = arr2[0];
    for (long long j = 0; j < n; j++) {
      if (min2 > arr2[j]) {
        min2 = arr2[j];
      }
    }
    long long count = 0;
    for (long long k = 0; k < n; k++) {
      a = arr1[k] - min1;
      b = arr2[k] - min2;
      if (a > b) {
        count = count + a;
      } else {
        count = count + b;
      }
    }
    cout << count << endl;
  }
  return 0;
}
