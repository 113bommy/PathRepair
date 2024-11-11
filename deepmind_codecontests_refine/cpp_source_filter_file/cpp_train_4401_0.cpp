#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ar[n];
    long long int mx_ind = 0, mx = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> ar[i];
      if (ar[i] > mx) {
        mx = ar[i];
        mx_ind = i;
      }
    }
    long long int k = mx_ind;
    long long int count = 0;
    while (k < n && ar[k] == mx) {
      k++;
      count++;
    }
    if (k == n) {
      cout << n << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
