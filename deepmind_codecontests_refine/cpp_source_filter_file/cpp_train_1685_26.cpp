#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int min = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (min <= a[i]) {
        sum++;
      } else {
        min = a[i];
      }
    }
    cout << sum - 1 << endl;
  }
  return 0;
}
