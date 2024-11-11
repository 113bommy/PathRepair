#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    long long int arr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    long long int peaks[n];
    peaks[0] = 0;
    peaks[1] = 0;
    for (int j = 2; j < n; j++) {
      if (arr[j - 1] > arr[j - 2] && arr[j - 1] > arr[j]) {
        peaks[j] = peaks[j - 1] + 1;
      } else {
        peaks[j] = peaks[j - 1];
      }
    }
    int l;
    int p = 0, q;
    for (int j = 0; j <= (n - k); j++) {
      q = peaks[j + k - 1] - peaks[j];
      if (q > p) {
        l = j;
        p = q;
      }
    }
    cout << p + 1 << " " << l + 1 << endl;
  }
}
