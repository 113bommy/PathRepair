#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int b[n], k = 0, sum = 0, l = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 3 == 0) {
        sum++;
      } else if (a[i] % 3 == 0) {
        k++;
      } else {
        l++;
      }
    }
    if (l == k) {
      sum = sum + k;
    } else if (l < k) {
      k = k - l;
      sum = sum + l;
      k = k / 3;
      sum = sum + k;
    } else {
      l = l - k;
      sum = sum + k;
      l = l / 3;
      sum = sum + l;
    }
    cout << sum << endl;
  }
  return 0;
}
